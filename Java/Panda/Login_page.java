//import required classes and packages  
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.lang.Exception;

//create Login_page class to create login form
//class extends JFrame to create a window where our component add  
//class implements ActionListener to perform an action on button click  
class Login_page extends JFrame implements ActionListener
{
    //initialize button, panel, label, and text field  
    JButton b1,b2;
    JPanel newPanel;
    JLabel userLabel, passLabel;
    final JTextField  textField1, textField2;

    //calling constructor  
    Login_page()
    {

        //create label for username
        userLabel = new JLabel();
        userLabel.setText("Username");      //set label value for textField1

        //create text field to get username from the user
        textField1 = new JTextField(30);    //set length of the text

        //create label for password
        passLabel = new JLabel();
        passLabel.setText("Password");      //set label value for textField2

        //create text field to get password from the user
        textField2 = new JPasswordField(20);    //set length for the password

        //create reset button
        b2 = new JButton("RESET");  //set label to button

        //create submit button
        b1 = new JButton("SUBMIT"); //set label to button

        //create panel to put form elements  
        newPanel = new JPanel(new GridLayout(3, 1));
        newPanel.add(userLabel);    //set username label to panel  
        newPanel.add(textField1);   //set text field to panel  
        newPanel.add(passLabel);    //set password label to panel  
        newPanel.add(textField2);   //set text field to panel
        newPanel.add(b2);           //set button to panel
        newPanel.add(b1);           //set button to panel

        //set border to panel   
        add(newPanel, BorderLayout.CENTER);

        //perform action on button click
        b2.addActionListener(this);     //add action listener to button
        b1.addActionListener(this);     //add action listener to button
        setTitle("LOGIN FORM");         //set title to the login form  
    }

    //define abstract method actionPerformed() which will be called on button click   
    public void actionPerformed(ActionEvent ae)     //pass action listener as a parameter  
    {
        String userValue = textField1.getText();        //get user entered username from the textField1  
        String passValue = textField2.getText();        //get user entered password from the textField2



            //check whether the credentials are authentic or not
        if (userValue.equals("Amaan") && passValue.equals("abcabc")) {  //if authentic, navigate user to a new page

            //create instance of the NewPage  
            NewPage page = new NewPage();

            //make page visible to the user  
            page.setVisible(true);

            //create a welcome label and set it to the new page  
            JLabel wel_label = new JLabel("Welcome: "+userValue);
            page.getContentPane().add(wel_label);
        }
        else if(ae.getSource()==b2)
        {
            textField1.setText("");
            textField2.setText("");
        }
        else{
            //show error message  
            System.out.println("Please enter valid username and password");
        }
    }

    public static void main(String[] args)
    {
        try
        {
            //create instance of the Login_page
            Login_page form = new Login_page();
            form.setSize(600,150);  //set size of the frame
            form.setVisible(true);  //make form visible to the user
        }
        catch(Exception e)
        {
            //handle exception
            JOptionPane.showMessageDialog(null, e.getMessage());
        }
    }
}

class NewPage extends JFrame
{
    //constructor
    NewPage()
    {
        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Welcome");
        setSize(400, 200);
    }
}