import java.io.*;
import java.util.ArrayList;

public class ParseOpcodes {
    public static void main(String[] args) {
        String filename = "input.txt";
        ArrayList<String> opcodes = new ArrayList<>();
        ArrayList<String> operands = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) continue;

                String[] tokens = line.split("\\s+|,");

                int startIndex = 0;
                if (!tokens[0].matches("[A-Z]+")) {
                    startIndex = 1;
                }

                if (startIndex < tokens.length) {
                    opcodes.add(tokens[startIndex]);
                }

                if (startIndex + 1 < tokens.length) {
                    StringBuilder operandBuilder = new StringBuilder();
                    for (int i = startIndex + 1; i < tokens.length; i++) {
                        operandBuilder.append(tokens[i]).append(" ");
                    }
                    operands.add(operandBuilder.toString().trim());
                }
            }

            System.out.println("Opcodes:");
            for (String opcode : opcodes) {
                System.out.println(opcode);
            }

            System.out.println("\nOperands:");
            for (String operand : operands) {
                System.out.println(operand);
            }

        } catch (FileNotFoundException e) {
            System.out.println("File " + filename + " not found");
        } catch (IOException e) {
            System.out.println("An error occurred while reading the file\n" + e);
        }
    }
}
