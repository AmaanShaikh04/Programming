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
            while ((line = reader.readLine()) != null) {
                if (line.startsWith("ID SymbolName")) {
                    symbolTableStart = true;
                    continue;
                }
                
                if (symbolTableStart) {
                    String[] parts = line.trim().split("\s+");
                    if (parts.length == 4) {
                        int id = Integer.parseInt(parts[0]);
                        int address = Integer.parseInt(parts[2]);
                        symbolAddresses.put(id, address);
                    }
                } else {
                    if (line.trim().isEmpty() || line.startsWith("Location") || line.contains("(AD,")) {
                        continue;
                    }
                    machineCode.add(processInstruction(line, symbolAddresses));
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
    
            if (token.startsWith("(C,")) {
                machineCode.append(token.substring(3, token.length() - 1)).append(" ");
            } else if (token.startsWith("(S,")) {
                int symbolId = Integer.parseInt(token.substring(3, token.length() - 1));
                if (symbolAddresses.containsKey(symbolId)) {
                    machineCode.append(symbolAddresses.get(symbolId)).append(" ");
                }
            } else if (token.startsWith("(IS,")) {
                machineCode.append(token.substring(4, token.length() - 1)).append(" ");
                instructionProcessed = true;
            } else if (token.startsWith("(DL,")) {
                continue;
            } else if (token.matches("\\(\\d+\\)")) { 
                machineCode.append(token).append(" ");
            }
        }

        return instructionProcessed ? machineCode.toString().trim() : "";
    }
    
}
