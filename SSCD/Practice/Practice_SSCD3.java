import java.io.*;
import java.util.*;

public class Practice_SSCD3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("macro_input.txt"));
        PrintWriter im = new PrintWriter("Intermediate.txt");
        PrintWriter mnt = new PrintWriter("MNT.txt");
        PrintWriter mdt = new PrintWriter("MDT.txt");
        PrintWriter ala = new PrintWriter("ALA.txt");

        List<String> ALA = new ArrayList<>();
        List<String> MDT = new ArrayList<>();
        int mdtp = 1, macroStart = 0;
        String line, macroName = "";
        boolean inMacro = false;

        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.equals("MACRO")) {
                inMacro = true;
                ALA.clear();
                continue;
            }
            if (inMacro) {
                if (macroName.isEmpty()) {
                    String[] parts = line.split("\\s+", 2);
                    macroName = parts[0];
                    String[] argus = parts[1].split(",");
                    for (int i = 0; i < argus.length; i++)
                        ALA.add(argus[i].trim());
                    String header = macroName + " " + "#1";
                    for (int i = 1; i < ALA.size(); i++)
                        header += "," + "#" + (i + 1);
                    macroStart = mdtp;
                    MDT.add(mdtp++ + " " + header);
                } else if (line.equals("MEND")) {
                    MDT.add(mdtp++ + " MEND");
                    mnt.println(macroName + " " + macroStart);
                    for (int i = 0; i < ALA.size(); i++)
                        ala.println((i + 1) + " " + ALA.get(i));
                    inMacro = false;
                    macroName = "";
                } else {
                    for (int i = 0; i < ALA.size(); i++)
                        line = line.replace(ALA.get(i), "#" + (i + 1));
                    MDT.add(mdtp++ + " " + line);
                }
            } else {
                im.println(line);
            }
        }

        // Write MDT last
        mdt.println("Index Instruction");
        for (String m : MDT) mdt.println(m);

        br.close();
        im.close(); mnt.close(); mdt.close(); ala.close();
        System.out.println("Macro Pass 1 Done!");
    }
}
