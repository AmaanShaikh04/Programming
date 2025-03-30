import java.io.*;
import java.util.*;

class lab3 {

    static int LC = 0;
    static int mntIndex = 1;
    static int mdtIndex = 1;
    static int alaIndex = 1;

    static Map<String, Integer> mnt = new LinkedHashMap<>();
    static List<String[]> mdt = new ArrayList<>();
    static Map<String, Integer> ala = new LinkedHashMap<>();
    static List<String[]> outputTable = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input3.txt"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));

        String line;
        boolean inMacroDefinition = false;
        boolean inOutputTable = false;
        int alaCounter = 1;

        while ((line = br.readLine()) != null) {
            String[] parts = line.trim().split("\\s+");

            if (parts.length == 0) continue; // Skip empty lines

            String opcode = parts[0];
            String operand1 = parts.length > 1 ? parts[1] : "";
            String operand2 = parts.length > 2 ? parts[2] : "";

            if (opcode.equals("MACRO")) {
                inMacroDefinition = true;
                mnt.put(parts[1], mntIndex++);
            } else if (opcode.equals("MEND")) {
                inMacroDefinition = false;
                mdt.add(new String[]{"MEND", "", ""});
            } else if (inMacroDefinition) {
                if (operand1.startsWith("&")) { // Argument replacement
                    if (!ala.containsKey(operand1)) {
                        ala.put(operand1, alaCounter++);
                    }
                    operand1 = "#" + ala.get(operand1);
                }
                if (operand2.startsWith("&")) {
                    if (!ala.containsKey(operand2)) {
                        ala.put(operand2, alaCounter++);
                    }
                    operand2 = "#" + ala.get(operand2);
                }
                mdt.add(new String[]{opcode, operand1, operand2});
            } else if (opcode.equals("START") || opcode.equals("END") || !inMacroDefinition) {
                outputTable.add(new String[]{opcode, operand1, operand2});
                if (opcode.equals("START")) {
                    inOutputTable = true;
                } else if (opcode.equals("END")) {
                    inOutputTable = false;
                }
            }
        }

        // Print and write the output to file

        bw.write("\nMNT (Macro Name Table):\n");
        System.out.println("\nMNT (Macro Name Table):");
        for (Map.Entry<String, Integer> entry : mnt.entrySet()) {
            String output = entry.getKey() + " -------- " + entry.getValue();
            System.out.println(output);
            bw.write(output + "\n");
        }

        bw.write("\nMDT (Macro Definition Table):\n");
        System.out.println("\nMDT (Macro Definition Table):");
        int mdtCounter = 1;
        for (String[] entry : mdt) {
            String output = mdtCounter++ + "  " + entry[0] + " " + entry[1] + " " + entry[2];
            System.out.println(output);
            bw.write(output + "\n");
        }

        bw.write("\nALA (Argument List Array):\n");
        System.out.println("\nALA (Argument List Array):");
        int alaCounterPrint = 1;
        for (Map.Entry<String, Integer> entry : ala.entrySet()) {
            String output = "#" + alaCounterPrint++ + "  " + entry.getKey() + " -------- " + entry.getValue();
            System.out.println(output);
            bw.write(output + "\n");
        }

        bw.write("\nOutput Table:\n");
        System.out.println("\nOutput Table:");
        for (String[] entry : outputTable) {
            String output = entry[0] + "  " + entry[1] + "  " + entry[2];
            System.out.println(output);
            bw.write(output + "\n");
        }

        // Close file writer
        bw.close();
    }
}