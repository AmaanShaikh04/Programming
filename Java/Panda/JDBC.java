import java.sql.*;
import java.util.*;

public class JDBC{
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

    public static void prepared_insert_db() {
        int emp_id,sal;
        String emp_name;
        Scanner scan = new Scanner(System.in);
        final String insert_val =
                "INSERT INTO employee(emp_id, emp_name, sal) VALUES(?, ?, ?)";

        System.out.println("Enter Employee ID:");
        emp_id = scan.nextInt();
        System.out.println("Enter Employee Name:");
        emp_name = scan.next();
        System.out.println("Enter Salary:");
        sal = scan.nextInt();

        try {
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb",
                    "amaan", "12345");
            PreparedStatement prep_ins = conn.prepareStatement(insert_val);

            prep_ins.setInt(1, emp_id);
            prep_ins.setString(2, emp_name);
            prep_ins.setInt(3, sal);

            prep_ins.executeUpdate();
            JDBC.select_db();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(true) {
            System.out.println("Press 1 for printing database");
            System.out.println("Press 2 for inserting in database");
            System.out.println("Press 3 for preferred statement insert in database");
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
                    prepared_insert_db();
                    break;
                case 4:
                    return;
                default:
                    System.out.println("Wrong input");
            }
        }
    }
}