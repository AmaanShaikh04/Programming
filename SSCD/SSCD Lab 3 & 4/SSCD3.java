package Macro;
// Amaan Shaikh
// Macro Pass 1

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class SSCD3 {
    private static List<MNTEntry> mntTable = new ArrayList<>();
    private static List<ALAEntry> alaTable = new ArrayList<>();
    private static List<MDTEntry> mdtTable = new ArrayList<>();
    
    private static int mntIndexCounter = 1;
    private static int mdtIndexCounter = 1;
    
    private static Map<String, String> currentALA = new HashMap<>();

    public static void main(String[] args) {
        String filePath = "macro_input.txt";
        String intermediateFileName = "Intermediate.txt";
        String mntFileName = "MNT.txt";
        String alaFileName = "ALA.txt";
        String mdtFileName = "MDT.txt";

        try (BufferedReader br = new BufferedReader(new FileReader(filePath));
             PrintWriter intermediateWriter = new PrintWriter(new FileWriter(intermediateFileName))) {

            String line;
            boolean inMacroDefinition = false;
            boolean headerProcessed = false;

            while ((line = br.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) {
                    if (!inMacroDefinition) {
                        intermediateWriter.println();
                    }
                    continue;
                }

                if (line.equalsIgnoreCase("MACRO")) {
                    inMacroDefinition = true;
                    headerProcessed = false;
                    currentALA.clear();
                    continue;
                }

                if (inMacroDefinition) {
                    if (!headerProcessed) {
                        String[] parts = line.split("\\s+");
                        String macroName = parts[0];
                        int startingMDTIndex = mdtIndexCounter;

                        mntTable.add(new MNTEntry(mntIndexCounter++, macroName, startingMDTIndex));

                        if (parts.length > 1) {
                            String params = line.substring(macroName.length()).trim();
                            String[] formalArgs = params.split(",");
                            int argCount = 1;
                            for (String arg : formalArgs) {
                                arg = arg.trim();
                                if (!arg.isEmpty()) {
                                    String alaIndex = "#" + argCount;
                                    currentALA.put(arg, alaIndex);
                                    alaTable.add(new ALAEntry(alaIndex, arg, null, macroName));
                                    argCount++;
                                }
                            }
                        }

                        mdtTable.add(new MDTEntry(mdtIndexCounter++, line));
                        headerProcessed = true;
                    } else {
                        if (line.equalsIgnoreCase("MEND")) {
                            mdtTable.add(new MDTEntry(mdtIndexCounter++, line));
                            inMacroDefinition = false;
                        } else {
                            String processedLine = replaceFormals(line, currentALA);
                            mdtTable.add(new MDTEntry(mdtIndexCounter++, processedLine));
                        }
                    }
                } else {
                    intermediateWriter.println(line);
                }
            }

        } catch (IOException e) {
            System.err.println("Error processing file: " + e.getMessage());
            return;
        }

        writeMNTTable(mntFileName);
        writeALA(alaFileName);
        writeMDT(mdtFileName);

        System.out.println("Pass One completed successfully.");
        System.out.println("Output files generated:");
        System.out.println("1. " + mntFileName);
        System.out.println("2. " + alaFileName);
        System.out.println("3. " + mdtFileName);
        System.out.println("4. " + intermediateFileName);
    }

    private static String replaceFormals(String line, Map<String, String> alaMapping) {
        for (Map.Entry<String, String> entry : alaMapping.entrySet()) {
            String formalArg = entry.getKey();
            String alaIndex = entry.getValue();
            line = line.replace(formalArg, alaIndex);
        }
        return line;
    }

    private static void writeMNTTable(String fileName) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(fileName))) {
            writer.println(String.format("%-10s %-10s %-10s", "MNT Index", "Name", "MDT Index"));
            for (MNTEntry entry : mntTable) {
                writer.println(entry);
            }
        } catch (IOException e) {
            System.err.println("Error writing MNT table: " + e.getMessage());
        }
    }

    private static void writeALA(String fileName) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(fileName))) {
            writer.println(String.format("%-10s %-15s %-15s %-10s", "Index", "Formal Arg", "Actual Arg", "Macro Name"));
            for (ALAEntry entry : alaTable) {
                writer.println(entry);
            }
        } catch (IOException e) {
            System.err.println("Error writing ALA table: " + e.getMessage());
        }
    }

    private static void writeMDT(String fileName) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(fileName))) {
            writer.println(String.format("%-10s %s", "MDT Index", "Instruction"));
            for (MDTEntry entry : mdtTable) {
                writer.println(entry);
            }
        } catch (IOException e) {
            System.err.println("Error writing MDT table: " + e.getMessage());
        }
    }

    static class MNTEntry {
        int mntIndex;
        String macroName;
        int mdtIndex;

        public MNTEntry(int mntIndex, String macroName, int mdtIndex) {
            this.mntIndex = mntIndex;
            this.macroName = macroName;
            this.mdtIndex = mdtIndex;
        }

        @Override
        public String toString() {
            return String.format("%-10d %-10s %-10d", mntIndex, macroName, mdtIndex);
        }
    }

    static class ALAEntry {
        String index;
        String formalArg;
        String actualArg;
        String macroName;

        public ALAEntry(String index, String formalArg, String actualArg, String macroName) {
            this.index = index;
            this.formalArg = formalArg;
            this.actualArg = actualArg;
            this.macroName = macroName;
        }

        @Override
        public String toString() {
            return String.format("%-10s %-15s %-15s %-10s", index, formalArg, actualArg, macroName);
        }
    }

    static class MDTEntry {
        int mdtIndex;
        String instruction;

        public MDTEntry(int mdtIndex, String instruction) {
            this.mdtIndex = mdtIndex;
            this.instruction = instruction;
        }

        @Override
        public String toString() {
            return String.format("%-10d %s", mdtIndex, instruction);
        }
    }
}