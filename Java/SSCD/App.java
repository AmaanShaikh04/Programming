import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        String filePath = "example.txt"; 
        HashMap<String, String> symboltable = new HashMap<>();
     
        Integer count=1;


        Scanner scanner = new Scanner(System.in); 
        System.out.println( "Do you want to enter a symbol");
        String input = scanner.nextLine(); 
        while(input.equals("y") || input.equals("Y")){

        System.out.println( "Enter location of " + "S"+count);
        String sLoc = scanner.nextLine(); 

        String symbolName = "S"+Integer.toString(count);    
        count++;
        symboltable.put(symbolName,sLoc); 
        System.out.println( "Do you want to enter a symbol");
        input = scanner.nextLine();  
        }


        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;

            String outputString;
            while ((line = br.readLine()) != null) {
                String str = line;
                String[] words = str.split(" "); // Splitting on space

                int n = words.length;
                outputString ="";
                for (int i=0;i<n;i++) {
                     

                        String word = words[i];
                        if(i==0){    //LOCATION COUNTER
                               outputString += word;
                        }
                        else if(i==1){   //opcode
                            String[] str1 = word.split(","); // Splitting on comma

                   
                             if(str1[0].equals("AD") || str1[0].equals("DC") || str1[0].equals("DS")){
                                outputString="";
                                break;

                            }
                            else if(symboltable.get(str1[0])!=null){
                                outputString += " "+symboltable.get(str1[0]);
                                
                                
                            }
                            else if(str1[1]!=null){
                                outputString+=" " + str1[1];
                            }
                    

                    }
            
                    else if(i==2 || i==3){
                
                    
                        //symbol
                        String[] str1 = word.split(","); 
                        if(str1[0].matches("\\d+")){
                            outputString+=" "+word;
                        }else {
                        String value = symboltable.get(str1[0]);

        
                        if (value != null) {
                            outputString+=" "+value;

                            }
                        else if(str1[0].equals("C")){

                            outputString+=" "+str1[1]; 
                            }
                            else if(str1[0].equals("DS") || str1[0].equals("DC")){
                              
                                outputString="";
                                break;                                
                            }
                        }
                         } 
                     }
        if(outputString!=null) System.out.println(outputString);
                            }
        } catch (IOException e) {
            System.out.println("Error reading the file: " + e.getMessage());
        }
    }
}