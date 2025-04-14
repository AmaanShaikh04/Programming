// Amaan Shaikh
// Assembler Pass 1

import java.io.*;
import java.util.*;

public class SSCD1 {
    public static void main(String[] args) {
        String inputFilePath = "assembler_input.txt";
        String outputFilePath = "intermediate_code.txt";

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

        try (BufferedReader reader = new BufferedReader(new FileReader(inputFilePath));
             PrintWriter writer = new PrintWriter(new FileWriter(outputFilePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] tokens = line.trim().split("\\s+|,");

                if (tokens[0].equalsIgnoreCase("START")) {
                    if (tokens.length > 1) {
                        try {
                            locationCounter = Integer.parseInt(tokens[1]);
                        } catch (NumberFormatException e) {
                            System.err.println("Invalid location counter for START. Defaulting to 0.");
                            locationCounter = 0;
                        }
                    } else {
                        locationCounter = 0;
                    }
                    intermediateCode.add("- AD,01 C," + locationCounter);
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
                    if (DL.containsKey(tokens[1])) {
                        operand1 = tokens[0];
                        opcode = tokens[1];
                        operand2 = tokens[2];
                    } else {
                        opcode = tokens[0];
                        operand1 = tokens[1];
                        operand2 = tokens[2];
                    }
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
                    String code = "IS," + IS.get(opcode);
                    String regCode = registerCodes.getOrDefault(operand1, "0");
                    String operandCode;
                    if (isNumeric(operand2)) {
                        operandCode = "C," + operand2;
                        constants.add(operand2);
                    } else {
                        operandCode = operand2 != null ? "S," + getSymbolIndex(symbolTable, operand2) : "";
                    }
                    if (label != null) {
                        intermediateCode.add(locationCounter + " " + code + " " + regCode + " " + operandCode);
                    } else {
                        intermediateCode.add(locationCounter + " " + code + " " + regCode + " " + operandCode);
                    }
                    locationCounter++;
                
                } if (DL.containsKey(opcode)) {
                    if (operand1 != null) {
                        symbolTable.put(operand1, locationCounter);
                        int length = opcode.equals("DS") ? Integer.parseInt(operand2) : 1;
                        symbolLengths.put(operand1, length);
                        intermediateCode.add(locationCounter + " DL," + DL.get(opcode) + " C," + operand2);
                        locationCounter += length;
                    }
                } if (AD.containsKey(opcode)) {
                    if (opcode.equals("ORIGIN")) {
                        locationCounter = Integer.parseInt(operand1);
                        intermediateCode.add("- AD," + AD.get(opcode) + " C," + operand1);
                    } else {
                        intermediateCode.add("- AD," + AD.get(opcode));
                    }
                }
            }

            writer.println("ID SymbolName Address Length");
            int id = 1;
            for (Map.Entry<String, Integer> entry : symbolTable.entrySet()) {
                String symbol = entry.getKey();
                int address = entry.getValue();
                int length = symbolLengths.getOrDefault(symbol, 1);
                writer.println(id++ + " " + symbol + " " + address + " " + length);
            }
            writer.println();
            writer.println("Location IntermediateCode");
            for (String code : intermediateCode) {
                String[] parts = code.split(" ", 2);
                String location = parts[0];
                String instrCode = parts.length > 1 ? parts[1] : "";
                writer.println(location + " " + instrCode);
            }

            
            

        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("\nPass 1 Assembler Execution Complete. Output written to " + outputFilePath);
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