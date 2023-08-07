import java.sql.*;
import java.util.*;

public class JDBC_CCA{
    public static void select_db() {
        try {
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb",
                    "amaan", "12345");

            Statement q = conn.createStatement();
            ResultSet rs = q.executeQuery("select * from employee");

            while(rs.next()) {
                System.out.println("Employee ID: "+rs.getString("emp_id"));
                System.out.println("Employee name: "+rs.getString("emp_name"));
                System.out.println("Salary: "+rs.getString("sal"));
                System.out.println();
            }
            q.close();
            conn.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void insert_db() {
        try {
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb",
                    "amaan", "12345");
            Statement q = conn.createStatement();

            q.executeUpdate("insert into employee values (1,'A',90000)");
            System.out.println("Record inserted!");

            q.close();
            conn.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void delete_db() {
        final String delete_all_val =
                "TRUNCATE employee";


        try {
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb",
                    "amaan", "12345");
            PreparedStatement prep_ins = conn.prepareStatement(delete_all_val);

            prep_ins.executeUpdate();

            System.out.println("Truncated Table employee!");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(true) {
            System.out.println("Press 1 for printing database");
            System.out.println("Press 2 for inserting in database");
            System.out.println("Press 3 for deleting in database");
            System.out.println("Press 4 for exit");
            int ch = sc.nextInt();
            switch (ch)
            {
                case 1:
                    select_db();
                    break;
                case 2:
                    insert_db();
                    break;
                case 3:
                    delete_db();
                    break;
                case 4:
                    return;
                default:
                    System.out.println("Wrong input");
            }
        }
    }
}