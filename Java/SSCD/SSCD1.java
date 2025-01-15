// Amaan Shaikh
// Assembler Pass 1 and Data Structures

import java.io.*;
import java.util.*;

public class SSCD1 {
    public static void main(String[] args) {
        String inputFilePath = "input.txt";

        int locationCounter = 0;
        Map<String, Integer> symbolTable = new LinkedHashMap<>();
        Map<String, Integer> symbolLengths = new LinkedHashMap<>();
        List<String> intermediateCode = new ArrayList<>();
        Set<String> constants = new HashSet<>();

        Map<String, String> IS = new LinkedHashMap<>();
        IS.put("STOP", "00");
        IS.put("ADD", "01");
        IS.put("SUB", "02");
        IS.put("MULT", "03");
        IS.put("MOVER", "04");
        IS.put("MOVEM", "05");
        IS.put("JMP", "06");
        IS.put("BC", "07");
        IS.put("DIV", "08");
        IS.put("READ", "09");
        IS.put("PRINT", "10");

        Map<String, String> AD = new LinkedHashMap<>();
        AD.put("START", "01");
        AD.put("ORIGIN", "02");
        AD.put("EQU", "03");
        AD.put("LTORG", "04");
        AD.put("END", "05");

        Map<String, String> DL = new LinkedHashMap<>();
        DL.put("DC", "01");
        DL.put("DS", "02");

        Map<String, String> registerCodes = new LinkedHashMap<>();
        registerCodes.put("AREG", "1");
        registerCodes.put("BREG", "2");
        registerCodes.put("CREG", "3");
        registerCodes.put("DREG", "4");

        try (BufferedReader reader = new BufferedReader(new FileReader(inputFilePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] tokens = line.trim().split("\\s+|,");

                if (tokens[0].equalsIgnoreCase("START")) {
                    locationCounter = Integer.parseInt(tokens[1]);
                    intermediateCode.add("- (AD,01) (C," + tokens[1] + ")");
                    continue;
                }

                String label = null;
                String opcode = null;
                String operand1 = null;
                String operand2 = null;

                if (tokens.length == 4) {
                    label = tokens[0];
                    opcode = tokens[1];
                    operand1 = tokens[2];
                    operand2 = tokens[3];
                } else if (tokens.length == 3) {
                    opcode = tokens[0];
                    operand1 = tokens[1];
                    operand2 = tokens[2];
                } else if (tokens.length == 2) {
                    opcode = tokens[0];
                    operand1 = tokens[1];
                } else if (tokens.length == 1) {
                    opcode = tokens[0];
                }

                if (label != null && !symbolTable.containsKey(label)) {
                    symbolTable.put(label, locationCounter);
                }

                if (IS.containsKey(opcode)) {
                    String code = "(IS," + IS.get(opcode) + ")";
                    String regCode = registerCodes.getOrDefault(operand1, "0");
                    String operandCode;
                    if (isNumeric(operand2)) {
                        operandCode = "(C," + operand2 + ")";
                        constants.add(operand2);
                    } else {
                        operandCode = operand2 != null ? "(S," + getSymbolIndex(symbolTable, operand2) + ")" : "";
                    }
                    if (label != null) {
                        intermediateCode.add(locationCounter + " (S," + getSymbolIndex(symbolTable, label) + ") " + code + " (" + regCode + ") " + operandCode);
                    } else {
                        intermediateCode.add(locationCounter + " " + code + " (" + regCode + ") " + operandCode);
                    }
                    locationCounter++;
                } else if (DL.containsKey(opcode)) {
                    if (label != null) {
                        symbolTable.put(label, locationCounter);
                        int length = opcode.equals("DS") ? Integer.parseInt(operand1) : 1;
                        symbolLengths.put(label, length);
                        intermediateCode.add(locationCounter + " (S," + getSymbolIndex(symbolTable, label) + ") (DL," + DL.get(opcode) + ") (C," + operand1 + ")");
                        locationCounter += length;
                    }
                } else if (AD.containsKey(opcode)) {
                    if (opcode.equals("ORIGIN")) {
                        locationCounter = symbolTable.getOrDefault(operand1, locationCounter);
                        intermediateCode.add("- (AD," + AD.get(opcode) + ") (C," + operand1 + ")");
                    } else {
                        intermediateCode.add("- (AD," + AD.get(opcode) + ")");
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("Intermediate Code Table (Opcode Table):");
        System.out.println("+----------------+----------------------------+");
        System.out.println("|    Location    |     Intermediate Code      |");
        System.out.println("+----------------+----------------------------+");
        intermediateCode.forEach(code -> {
            String[] parts = code.split(" ", 2);
            String location = parts[0];
            String instrCode = parts.length > 1 ? parts[1] : "";
            System.out.printf("| %-14s | %-26s |\n", location, instrCode);
        });
        System.out.println("+----------------+----------------------------+\n");

        System.out.println("Symbol Table:");
        System.out.println("+----+---------------------+------------------+--------+");
        System.out.println("| ID |     Symbol Name     |     Address      | Length |");
        System.out.println("+----+---------------------+------------------+--------+");
        int id = 1;
        for (Map.Entry<String, Integer> entry : symbolTable.entrySet()) {
            String symbol = entry.getKey();
            int address = entry.getValue();
            int length = symbolLengths.getOrDefault(symbol, 1);
            System.out.printf("| %-2d | %-19s | %-16d | %-6d |\n", id++, symbol, address, length);
        }
        System.out.println("+----+---------------------+------------------+--------+");
    }

    private static int getSymbolIndex(Map<String, Integer> symbolTable, String symbol) {
        return symbolTable.computeIfAbsent(symbol, k -> symbolTable.size() + 1);
    }

    private static boolean isNumeric(String str) {
        if (str == null) {
            return false;
        }
        try {
            Integer.parseInt(str);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }
}
