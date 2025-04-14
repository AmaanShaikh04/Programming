package Practice;

import java.io.*;
import java.util.*;

public class Practice_SSCD1 {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        String inputFilePath = "assembler_input.txt";
        String outputFilePath = "intermediate_code.txt";

        int locationCounter = 0;
        Map <String, Integer> symbolTable = new LinkedHashMap<>();
        Map <String, Integer> symbolLengths = new LinkedHashMap<>();
        List <String> intermediateCode = new ArrayList<>();
        Set <String> constants = new HashSet<>();

        Map <String, String> IS = new LinkedHashMap<>();
        IS.put("STOP","00");
        IS.put("ADD","01");
        IS.put("SUB","02");
        IS.put("MULT","03");

        Map <String, String> AD = new LinkedHashMap<>();
        AD.put("START","01");
        AD.put("ORIGIN","02");
        AD.put("EQU","03");
        AD.put("LTORG","04");
        AD.put("END","05");

        Map <String, String> DL = new LinkedHashMap<>();
        DL.put("DC","01");
        DL.put("DS","02");

        Map <String, String> registerCodes = new LinkedHashMap<>();
        registerCodes.put("AREG","1");
        registerCodes.put("BREG","2");
        registerCodes.put("CREG","3");
        registerCodes.put("DREG","4");

        try (BufferedReader reader = new BufferedReader(new FileReader(inputFilePath));
        PrintWriter writer = new PrintWriter(new FileWriter(outputFilePath))) 
        {
            String line;
            while ((line = reader.readLine()) != null)
            {
                String[] tokens = line.trim().split("\\s+|,");

                if(tokens[0].equalsIgnoreCase("START"))
                {
                    if(tokens.length > 1)
                    {
                        try{
                            locationCounter = Integer.parseInt(tokens[1]);
                        }catch(NumberFormatException e)
                        {
                            System.err.println("Invalid location counter, Defaulting to 0");
                            locationCounter = 0;
                        }
                    }
                    else {
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
                }
                else if (tokens.length == 3) {
                    if (DL.containsKey(tokens[1]))
                    {
                        operand1 = tokens[0];
                        opcode = tokens [1];
                        operand2 = tokens[2];
                    }
                    else
                    {
                        opcode = tokens[0];
                        operand1 = tokens[1];
                        operand2 = tokens[2];
                    }
                }
                else if (tokens.length == 2) {
                    opcode = tokens[0];
                    operand1 = tokens[1];
                }
                if (tokens.length == 1) {
                    opcode = tokens[0];
                }

                if (label != null && !symbolTable.containsKey(label))
                {
                    symbolTable.put(label, locationCounter);
                }

                if (IS.containsKey(opcode))
                {
                    String code = "IS," +IS.get(opcode);
                    String regCode = registerCodes.getOrDefault(operand1,"0");
                    String operandCode;
                    if (isNumeric(operand2))
                    {
                        operandCode = "C," + operand2;
                        constants.add(operand2);
                    }
                    else{ 
                        operandCode = operand2 != null ? "S," + getSymbolIndex(symbolTable, operand2) : "";
                    }
                    if (label != null) {
                        intermediateCode.add(locationCounter + " " + code + " " + regCode + " " + operandCode);
                    } else {
                        intermediateCode.add(locationCounter + " " + code + " " + regCode + " " + operandCode);
                    }
                    locationCounter++;
                }
            }
        }
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