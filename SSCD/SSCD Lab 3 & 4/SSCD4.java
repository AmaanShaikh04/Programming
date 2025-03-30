package Macro;
// Amaan Shaikh
// Macro Pass 2

import java.io.*;
import java.util.*;

public class SSCD4 {
    private static Map<String, Integer> mntTable = new HashMap<>();
    private static Map<Integer, String> mdtTable = new HashMap<>();
    private static Map<String, List<String>> alaTable = new HashMap<>();
    private static Map<String, String> actualALA = new HashMap<>();

    public static void main(String[] args) {
        String intermediateFile = "Intermediate.txt";
        String mntFile = "MNT.txt";
        String mdtFile = "MDT.txt";
        String alaFile = "ALA.txt";
        String updatedAlaFile = "ALA_Pass2.txt";
        String outputFile = "assembler_input.txt";

        loadMNT(mntFile);
        loadMDT(mdtFile);
        loadALA(alaFile);
        processIntermediate(intermediateFile, outputFile, updatedAlaFile);

        System.out.println("Pass Two completed successfully.");
        System.out.println("Output files generated:");
        System.out.println("1. " + outputFile);
        System.out.println("2. " + updatedAlaFile);
    }

    private static void loadMNT(String fileName) {
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            br.readLine(); // Skip header
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.trim().split("\\s+");
                if (parts.length == 3) {
                    mntTable.put(parts[1], Integer.parseInt(parts[2]));
                }
            }
        } catch (IOException e) {
            System.err.println("Error reading MNT: " + e.getMessage());
        }
    }

    private static void loadMDT(String fileName) {
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            br.readLine(); // Skip header
            String line;
            while ((line = br.readLine()) != null) {
                int index = Integer.parseInt(line.substring(0, 10).trim());
                String instruction = line.substring(10).trim();
                mdtTable.put(index, instruction);
            }
        } catch (IOException e) {
            System.err.println("Error reading MDT: " + e.getMessage());
        }
    }

    private static void loadALA(String fileName) {
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            br.readLine(); // Skip header
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.trim().split("\\s+");
                if (parts.length == 4) {
                    alaTable.computeIfAbsent(parts[3], k -> new ArrayList<>()).add(parts[0]);
                }
            }
        } catch (IOException e) {
            System.err.println("Error reading ALA: " + e.getMessage());
        }
    }

    private static void processIntermediate(String inputFile, String outputFile, String updatedAlaFile) {
        try (BufferedReader br = new BufferedReader(new FileReader(inputFile));
             PrintWriter writer = new PrintWriter(new FileWriter(outputFile));
             PrintWriter alaWriter = new PrintWriter(new FileWriter(updatedAlaFile))) {

            alaWriter.println(String.format("%-10s %-15s %-15s %-10s", "Index", "Formal Arg", "Actual Arg", "Macro Name"));

            String line;
            while ((line = br.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) {
                    writer.println();
                    continue;
                }
                
                String[] parts = line.split("\\s+");
                if (mntTable.containsKey(parts[0])) {
                    expandMacro(parts, writer, alaWriter);
                } else {
                    writer.println(line);
                }
            }
        } catch (IOException e) {
            System.err.println("Error processing Intermediate file: " + e.getMessage());
        }
    }

    private static void expandMacro(String[] parts, PrintWriter writer, PrintWriter alaWriter) {
        String macroName = parts[0];
        int mdtIndex = mntTable.get(macroName);
        List<String> actualArgs = Arrays.asList(parts).subList(1, parts.length);
        List<String> formalArgs = alaTable.get(macroName);

        Map<String, String> argMap = new HashMap<>();
        for (int i = 0; i < formalArgs.size() && i < actualArgs.size(); i++) {
            String actualArg = actualArgs.get(i).replaceAll(",", "").trim();
            argMap.put("#" + (i + 1), actualArg);
            actualALA.put(formalArgs.get(i), actualArg);
        }

        for (Map.Entry<String, String> entry : actualALA.entrySet()) {
            alaWriter.println(String.format("%-10s %-15s %-15s %-10s", entry.getKey(), "&" + entry.getKey().substring(1), entry.getValue(), macroName));
        }

        while (mdtTable.containsKey(mdtIndex)) {
            String instruction = mdtTable.get(mdtIndex++);
            if (instruction.equals("MEND")) break;
            for (Map.Entry<String, String> entry : argMap.entrySet()) {
                instruction = instruction.replace(entry.getKey(), entry.getValue());
            }
            writer.println(instruction);
        }
    }
}
