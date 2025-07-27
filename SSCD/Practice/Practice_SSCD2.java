import java.util.*;

public class Practice_SSCD2 {
    public static void main(String[] args) {
        // Simulated symbol table: ID -> Address
        Map<Integer, Integer> symAddr = Map.of(1, 500, 2, 501);

        // Simulated intermediate code lines
        String[] IC = {
            "400 IS,01 1 S,1",
            "401 IS,02 2 S,2",
            "402 IS,04 1 S,1"
        };

        System.out.println("Location MachineCode");
        for (String line : IC) {
            String[] p = line.split(" ");
            String loc = p[0], opcode = "", reg = "0", mem = "000";
            for (String token : Arrays.copyOfRange(p, 1, p.length)) {
                if (token.startsWith("IS,")) opcode = token.substring(3);
                else if (token.matches("\\d")) reg = token;
                else if (token.startsWith("S,")) mem = String.valueOf(symAddr.getOrDefault(Integer.parseInt(token.substring(2)), 0));
                else if (token.startsWith("C,")) mem = token.substring(2);
            }
            System.out.println(loc + " " + opcode + " " + reg + " " + mem);
        }
    }
}
