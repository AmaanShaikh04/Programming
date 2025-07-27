import java.io.*;
import java.util.*;

public class Practice_SSCD4 {
    private static final Map<String, Integer> mnt = new HashMap<>();
    private static final Map<Integer, String> mdt = new HashMap<>();
    private static final Map<String, List<String>> ala = new HashMap<>();
    private static final Map<String, String> actualArgs = new HashMap<>();

    public static void main(String[] args) {
        loadTables("MNT.txt", "MDT.txt", "ALA.txt");
        processIntermediate("intermediate.txt", "ExpandedCode.txt", "ALA_Pass2.txt");
        System.out.println("Pass Two completed successfully.");
    }

    private static void loadTables(String mntFile, String mdtFile, String alaFile) {
        loadMNT(mntFile);
        loadMDT(mdtFile);
        loadALA(alaFile);
    }

    private static void loadMNT(String fileName) {
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.trim().split("\\s+");
                if (parts.length == 2) {
                    mnt.put(parts[0], Integer.parseInt(parts[1]));
                }
            }
        } catch (IOException e) {
            System.err.println("Error reading MNT: " + e.getMessage());
        }
    }

    private static void loadMDT(String fileName) {
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            br.readLine(); // Skip header line if present
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.trim().split("\\s+", 2); // Split into index and instruction
                if (parts.length == 2) {
                    mdt.put(Integer.parseInt(parts[0]), parts[1]);
                }
            }
        } catch (IOException e) {
            System.err.println("Error reading MDT: " + e.getMessage());
        } catch (NumberFormatException e) {
            System.err.println("Error parsing MDT index: " + e.getMessage());
        }
    }

    private static void loadALA(String fileName) {
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.trim().split("\\s+");
                if (parts.length == 2) {
                    String macroName = parts[1].substring(1); // Remove the '&' symbol
                    ala.computeIfAbsent(macroName, k -> new ArrayList<>()).add(parts[0]);
                }
            }
        } catch (IOException e) {
            System.err.println("Error reading ALA: " + e.getMessage());
        }
    }

    private static void processIntermediate(String inputFile, String outputFile, String updatedAlaFile) {
        try (BufferedReader br = new BufferedReader(new FileReader(inputFile));
             PrintWriter out = new PrintWriter(new FileWriter(outputFile));
             PrintWriter alaWriter = new PrintWriter(new FileWriter(updatedAlaFile))) {

            alaWriter.println(String.format("%-10s %-15s %-15s %-10s", "Index", "Formal Arg", "Actual Arg", "Macro Name"));
            String line;
            while ((line = br.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) {
                    out.println();
                    continue;
                }
                String[] parts = line.split("\\s+");
                if (mnt.containsKey(parts[0])) {
                    expandMacro(parts, out, alaWriter);
                } else {
                    out.println(line);
                }
            }
        } catch (IOException e) {
            System.err.println("Error processing Intermediate file: " + e.getMessage());
        }
    }

    private static void expandMacro(String[] parts, PrintWriter out, PrintWriter alaWriter) {
        String macroName = parts[0];
        Integer mdtIndex = mnt.get(macroName);
        
        if (mdtIndex == null) {
            System.err.println("Error: Macro " + macroName + " not found in MNT.");
            return;
        }

        List<String> actualArgsList = Arrays.asList(parts).subList(1, parts.length);
        List<String> formalArgs = ala.get(macroName);
        
        if (formalArgs == null) {
            System.err.println("Error: Formal arguments not found for macro " + macroName);
            return;
        }

        Map<String, String > argMap = new HashMap<>();

        for (int i = 0; i < Math.min(formalArgs.size(), actualArgsList.size()); i++) {
            String actualArg = actualArgsList.get(i).replaceAll(",", "").trim();
            argMap.put("#" + (i + 1), actualArg);
            actualArgs.put(formalArgs.get(i), actualArg);
        }

        actualArgs.forEach((key, value) -> alaWriter.printf("%-10s %-15s %-15s %-10s%n", key, "&" + key.substring(1), value, macroName));

        while (mdt.containsKey(mdtIndex)) {
            String instruction = mdt.get(mdtIndex++);
            if ("MEND".equals(instruction)) break;
            for (Map.Entry<String, String> entry : argMap.entrySet()) {
                instruction = instruction.replace(entry.getKey(), entry.getValue());
            }
            out.println(instruction);
        }
    }
}