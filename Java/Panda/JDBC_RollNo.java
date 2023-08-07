import java.sql.*;
import java.util.*;

public class JDBC_RollNo{
    public static void select() {
        try {
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb",
                    "amaan", "12345");

            Statement q = conn.createStatement();
            ResultSet rs = q.executeQuery("select * from student_table");

            while(rs.next()) {
                System.out.println("Roll No: \t"+rs.getString("roll"));
                System.out.println("Name: \t"+rs.getString("name"));
                System.out.println();
            }
            q.close();
            conn.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void insert() {
        int roll;
        String name;
        Scanner scan = new Scanner(System.in);
        final String insert_val =
                "INSERT INTO student_table(name, roll_no) VALUES(?, ?)";

        System.out.println("Enter Student roll no:");
        roll = scan.nextInt();
        System.out.println("Enter Student Name:");
        name = scan.next();

        try {
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb",
                    "amaan", "12345");
            PreparedStatement prep_ins = conn.prepareStatement(insert_val);

            prep_ins.setInt(1, roll);
            prep_ins.setString(2, name);

            prep_ins.executeUpdate();
            JDBC_RollNo.select();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(true) {
            System.out.println("Press 1 for printing database");
            System.out.println("Press 2 for inserting in database");
            System.out.println("Press 3 for exit");
            int ch = sc.nextInt();
            switch (ch)
            {
                case 1:
                    select();
                    break;
                case 2:
                    insert();
                    break;
                case 3:
                    return;
                default:
                    System.out.println("Wrong input");
            }
        }
    }
}