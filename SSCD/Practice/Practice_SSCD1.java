import java.util.*;

public class Practice_SSCD1 {
    public static void main(String[] args) {
        String[] input = {
            "START 400",
            "ADD AREG A",
            "SUB BREG B",
            "MOVER AREG A",
            "END"
        };

        int lc = 0;
        List<String> ic = new ArrayList<>();
        Map<String, Integer> symbols = new LinkedHashMap<>();
        List<String> symbolList = new ArrayList<>();

        Map<String, String> IS = Map.of("ADD","01","SUB","02","MOVER","04");
        Map<String, String> AD = Map.of("START","01","END","05");
        Map<String, String> REG = Map.of("AREG","1","BREG","2","CREG","3","DREG","4");

        for (String line : input) {
            String[] t = line.split("\\s+");
            if (t[0].equals("START")) {
                lc = Integer.parseInt(t[1]);
                ic.add("- AD," + AD.get("START") + " C," + lc);
            } else if (t[0].equals("END")) {
                ic.add("- AD," + AD.get("END"));
            } else {
                String op = t[0], r = t[1], sym = t[2];
                if (!symbols.containsKey(sym)) {
                    symbols.put(sym, -1);
                    symbolList.add(sym);
                }
                ic.add(lc++ + " IS," + IS.get(op) + " " + REG.get(r) + " S," + (symbolList.indexOf(sym) + 1));
            }
        }

        System.out.println("Symbol Table:");
        for (int i = 0; i < symbolList.size(); i++)
            System.out.println((i + 1) + " " + symbolList.get(i) + " ?? 1");

        System.out.println("\nIntermediate Code:");
        ic.forEach(System.out::println);
    }
}
