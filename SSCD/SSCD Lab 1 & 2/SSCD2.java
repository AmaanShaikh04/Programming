// Amaan Shaikh
// Assembler Pass 2

import java.io.*;
import java.util.*;

public class SSCD2 {
    public static void main(String[] args) {
        String inputFilePath = "intermediate_code.txt";
        String outputFilePath = "machine_code.txt";

        Map<Integer, Integer> symbolAddresses = new HashMap<>();
        List<String> machineCode = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(inputFilePath));
             PrintWriter writer = new PrintWriter(new FileWriter(outputFilePath))) {
            
            String line;
            boolean symbolTableStart = false;
            boolean intermediateCodeStart = false;

            while ((line = reader.readLine()) != null) {
                line = line.trim();

                if (line.startsWith("ID SymbolName")) {
                    symbolTableStart = true;
                    continue;
                }

                if (symbolTableStart && !intermediateCodeStart) {
                    if (line.startsWith("Location")) {
                        intermediateCodeStart = true;
                        continue;
                    }
                    String[] parts = line.split("\\s+");
                    if (parts.length == 4) {
                        int id = Integer.parseInt(parts[0]);
                        int address = Integer.parseInt(parts[2]);
                        symbolAddresses.put(id, address);
                    }
                } else if (intermediateCodeStart) {
                    if (line.isEmpty() || line.startsWith("-")) {
                        continue;
                    }
                    String output = processInstruction(line, symbolAddresses);
                    if (!output.isEmpty()) {
                        machineCode.add(output);
                    }
                }
            }
            
            writer.println("Location MachineCode");
            for (String code : machineCode) {
                writer.println(code);
            }
            
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("\nPass 2 Assembler Execution Complete. Output written to " + outputFilePath);
    }

    private static String processInstruction(String line, Map<Integer, Integer> symbolAddresses) {
        String[] parts = line.trim().split(" ");
        String location = parts[0];
        StringBuilder machineCode = new StringBuilder(location + " ");
        boolean instructionProcessed = false;

        for (int i = 1; i < parts.length; i++) {
            String token = parts[i];

            if (token.startsWith("C,")) {
                machineCode.append(token.substring(2)).append(" ");
            } else if (token.startsWith("S,")) {
                int symbolId = Integer.parseInt(token.substring(2));
                if (symbolAddresses.containsKey(symbolId)) {
                    machineCode.append(symbolAddresses.get(symbolId)).append(" ");
                } else {
                    System.out.println("Warning: Symbol ID " + symbolId + " not found in symbol table.");
                    machineCode.append("?? ");
                }
            } else if (token.startsWith("IS,")) {
                machineCode.append(token.substring(4)).append(" ");
                instructionProcessed = true;
            } else if (token.startsWith("DL,")) {
                continue;
            } else if (token.matches("\\d+")) { 
                machineCode.append(token).append(" ");
            } else {
                System.out.println("Warning: Unexpected token " + token);
            }
        }

        return instructionProcessed ? machineCode.toString().trim() : "";
    }
}