/*
 * File name:   Microproject_AJP.java
 * Description: Java JDBC and Java Swing application
 * Authors:     Hrushikesh Pandit, Aditya Samudra, Amaan Shaikh and Ishan Vyavhare
 * (c) 2021 H.A.A.I
 */

//importing all the java packages required for the program
import javax.swing.*;
import java.awt.event.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

public class Microproject_AJP extends JFrame implements ActionListener {
    JFrame f = new JFrame();
    JButton insert_b, delete_b;
    JLabel text;
    Microproject_AJP()
    {
        text = new JLabel("Choose the operation");
        insert_b = new JButton("Insert");
        delete_b = new JButton("Delete");

        text.setBounds(110,30,200,20);
        insert_b.setBounds(50, 80, 100, 25);
        delete_b.setBounds(200, 80, 100, 25);

        f.add(text);
        f.add(insert_b);
        f.add(delete_b);

        f.setLayout(null);
        f.setVisible(true);
        f.setSize(400, 200);
        insert_b.addActionListener(this);
        delete_b.addActionListener(this);
    }

    public void actionPerformed(ActionEvent ae){
        if (ae.getSource() == insert_b)
        {
            Insert obj = new Insert();
        }
        if (ae.getSource() == delete_b)
        {
            Delete obj = new Delete();
        }
    }
    public static void main(String[] args) {
        new Microproject_AJP();
    }
}
class Insert extends JFrame implements ActionListener {
    JFrame f = new JFrame();
    JLabel prn, name, marks, email;
    JTextField prn_t, name_t, marks_t, email_t;         //setting the text field
    JButton clear, insert, delete;

    //constructor
    Insert() {
        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Student Admission Portal");   //insert
        setSize(400, 350);

        //create prn label and text field
        prn = new JLabel();
        prn.setText("PRN");
        prn_t = new JTextField(30);

        //create name label and text field
        name = new JLabel();
        name.setText("Name");
        name_t = new JTextField(30);

        //create marks label and text field
        marks = new JLabel();
        marks.setText("Marks");
        marks_t = new JTextField(5);

        //create email label and text field
        email = new JLabel();
        email.setText("Email");
        email_t = new JTextField(30);

        //create clear button
        clear = new JButton("Clear");

        //create insert button
        insert = new JButton("Insert");


        //Giving Coordinates
        prn.setBounds(50, 50, 100, 20);
        name.setBounds(50, 90, 100, 20);
        marks.setBounds(50, 130, 100, 20);
        email.setBounds(50, 170, 100, 20);
        prn_t.setBounds(200, 50, 100, 20);
        name_t.setBounds(200, 90, 100, 20);
        marks_t.setBounds(200, 130, 100, 20);
        email_t.setBounds(200, 170, 100, 20);
        clear.setBounds(50, 230, 90, 20);
        insert.setBounds(150, 230, 90, 20);

        //Adding components to the frame
        f.add(prn);
        f.add(name);
        f.add(marks);
        f.add(email);
        f.add(prn_t);
        f.add(name_t);
        f.add(marks_t);
        f.add(email_t);
        f.add(clear);
        f.add(insert);
        clear.addActionListener(this);
        insert.addActionListener(this);

        f.setLayout(null);
        f.setVisible(true);
        f.setSize(400, 350);

    }

    public void actionPerformed(ActionEvent ae) {

        String prn_text = prn_t.getText();
        String name_text = name_t.getText();
        String marks_text = marks_t.getText();
        String email_text = email_t.getText();

        if (ae.getSource() == insert) {
            final String insert_val =
                    "INSERT INTO student(prn_no, student_name, marks, email) VALUES(?, ?, ?, ?)";


            try {
                Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/ajp_microproject",
                        "amaan", "12345");
                PreparedStatement prep_ins = conn.prepareStatement(insert_val);

                prep_ins.setInt(1, Integer.parseInt(prn_text));
                prep_ins.setString(2, name_text);
                prep_ins.setInt(3, Integer.parseInt(marks_text));
                prep_ins.setString(4, email_text);
                prep_ins.executeUpdate();


            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        if (ae.getSource() == clear) {
            prn_t.setText("");
            name_t.setText("");
            marks_t.setText("");
            email_t.setText("");
        }
    }
}
class Delete extends JFrame implements ActionListener
{
    JFrame f = new JFrame();
    JLabel prn;
    JTextField prn_t;
    JButton delete,clear;

    //constructor
    Delete()
    {
        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Delete");
        setSize(400, 350);

        //create prn label and text field
        prn = new JLabel();
        prn.setText("PRN");
        prn_t = new JTextField(30);

        //create clear button
        clear = new JButton("Clear");

        //create delete button
        delete = new JButton("Delete");

        prn.setBounds(50, 50, 100, 20);
        prn_t.setBounds(200, 50, 100, 20);
        clear.setBounds(50, 100, 90, 20);
        delete.setBounds(150, 100, 90, 20);

        f.add(prn);
        f.add(prn_t);
        f.add(delete);
        f.add(clear);

        delete.addActionListener(this);
        clear.addActionListener(this);

        f.setLayout(null);
        f.setVisible(true);
        f.setSize(400, 200);
    }
    public void actionPerformed(ActionEvent ae) {
        String prn_text = prn_t.getText();

        if (ae.getSource() == delete)
        {
            final String delete_one_val =
                    "DELETE FROM student WHERE prn_no = "+prn_text;


            try {
                Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/ajp_microproject",
                        "amaan", "12345");
                PreparedStatement prep_ins = conn.prepareStatement(delete_one_val);

                prep_ins.executeUpdate();

            } catch (Exception e) {
                e.printStackTrace();
            }

        }
        if (ae.getSource() == clear) {
            prn_t.setText("");
        }
    }
}
