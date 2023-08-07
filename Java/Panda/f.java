import java.sql.*;
import java.util.*;

public class f{
    public static void select_db() {
        try {
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc",
                    "root", "P@$$w0rD");

            Statement q = conn.createStatement();
            ResultSet rs = q.executeQuery("select * from AD");

            while(rs.next()) {
                System.out.println("ID: "+rs.getInt("id"));
                System.out.println("name: "+rs.getString("name"));
                System.out.println("Phone: "+rs.getInt("phone"));
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
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc",
                    "root", "P@$$w0rD");
            Statement q = conn.createStatement();

            q.executeUpdate("insert into AD values (1,'A',90000)");
            System.out.println("Record inserted!");

            q.close();
            conn.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void prepared_insert_db() {
        int id,phone;
        String name;
        Scanner scan = new Scanner(System.in);
        final String insert_val =
                "INSERT INTO AD(id, name, phone) VALUES(?, ?, ?)";

        System.out.println("Enter ID:");
        id = scan.nextInt();
        System.out.println("Enter Name:");
        name = scan.next();
        System.out.println("Enter Phone number:");
        phone = scan.nextInt();

        try {
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc",
                    "root", "P@$$w0rD");
            PreparedStatement prep_ins = conn.prepareStatement(insert_val);

            prep_ins.setInt(1, id);
            prep_ins.setString(2, name);
            prep_ins.setInt(3, phone);

            prep_ins.executeUpdate();
            f.select_db();

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