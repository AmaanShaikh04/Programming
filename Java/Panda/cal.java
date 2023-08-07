import java.awt.*;
import java.awt.event.*;
public class cal implements ActionListener{

    //Declaring Objects
    Frame mainwindow=new Frame();
    Label label1=new Label("Enter number in textfield");
    Label label2=new Label("Enter number in textfield");
    Label label3=new Label("Addition of two numbers");
    TextField t1=new TextField();
    TextField t2=new TextField();
    TextField t3=new TextField();
    Button b1=new Button("Add");
    cal()
    {

        //Giving Coordinates
        label1.setBounds(50,100,150,20);
        label2.setBounds(50,140,150,20);
        label3.setBounds(50,180,150,20);
        t1.setBounds(210,80,100,50);
        t2.setBounds(210,130,100,50);
        t3.setBounds(210,180,100,50);
        b1.setBounds(50,250,150,50);
        mainwindow.add(label1);
        mainwindow.add(label2);
        mainwindow.add(label3);
        mainwindow.add(t1);
        mainwindow.add(t2);
        mainwindow.add(t3);
        mainwindow.add(b1);
        b1.addActionListener(this);
        mainwindow.setLayout(null);
        mainwindow.setVisible(true);
        mainwindow.setSize(400,350);
    }
    public void actionPerformed(ActionEvent e) {
        int n1 = Integer.parseInt(t1.getText());
        int n2 = Integer.parseInt(t2.getText());
        if(e.getSource() == b1)
        {
            t3.setText(String.valueOf(n1 + n2));
        }
    }
    public static void main(String args[])
    {
        new cal();
    }
}
