/*
 * File name:   ChatBot.java
 * Description: Java Chatbot file
 * Authors:     Hrushikesh Pandit and Amaan Shaikh
 * (c) 2021 HP.AS
 */

//importing all the java packages required for the program
import java.awt.*;
import java.awt.event.*;
import java.net.*;
import java.time.*;
import java.util.*;
import javax.swing.*;

//Start of class Chatbot which extends JFrame from javax.swing and implements ActionListener from java.awt
class ChatBot extends JFrame implements ActionListener
{
    static JTextArea area=new JTextArea();  //setting the text are
    JTextField field=new JTextField();      //setting the text field
    JScrollPane sp;     //scroll
    JButton send;       //button
    LocalTime time=LocalTime.now();         //used for getting local time
    LocalDate date=LocalDate.now();         //used for getting locat date
    Random random=new Random();             //for choosing random choice

    //start of parameterised constructor
    public ChatBot(String title)
    {
        //For setting up the Jframe
        super(title);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);
        setResizable(false);
        getContentPane().setBackground(Color.gray);
        field=new JTextField();
        send=new JButton(">");
        send.setFont(new Font("Times New Roman",Font.BOLD,22));
        send.setBackground(Color.white);
        send.setBounds(735,520,50,35);
        add(send);
        //For Text area
        area.setEditable(false);
        area.setBackground(Color.white);
        add(area);
        area.setFont(new Font("Times New Roman",Font.PLAIN,20));
        //scrollbar
        sp=new JScrollPane(area,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        sp.setBounds(10,20,775,470);
        add(sp);
        //For TextField
        field.setSize(725,35);
        field.setLocation(10,520);
        field.setForeground(Color.black);
        field.setFont(new Font("Times New Roman",Font.BOLD,22));
        add(field);
        send.addActionListener(this);
        getRootPane().setDefaultButton(send);
    }
    //end of parameterised constructor

    //start of function actionPerformed()
    public void actionPerformed(ActionEvent e)
    {
        String message=field.getText().toLowerCase();   //accepting and converting the message into lower case
        area.append("You: "+field.getText()+"\n");      //printing the message which the user entered
        field.setText("");                              //clearing the textfield
        Socket sock=new Socket();                       //creating a new socket object

        //start of AI conditions
        if(message.contains("how are you"))
        {
            //randomly chooses a reply
            int num=random.nextInt(3);
            if(num==0)
            {
                bot("I'm fine! What about you?");
            }
            else if(num==1)
            {
                bot("I am good, thanks for asking!");
            }
            else
            {
                bot("I am great, thanks for asking!");
            }
        }
        else if(message.contains("you")&&(message.contains("smart")||message.contains("good")))
        {
            bot("Thank you!");
        }
        else if(message.contains("welcome"))
        {
            bot("You are so polite. How can i help you?");
        }
        else if(message.contains("what") && message.contains("you") || message.contains("who") && message.contains("you"))
        {
            if(message.contains("doing"))
            {
                //randomly chooses a reply
                int num=random.nextInt(3);
                if(num==0)
                {
                    bot("I was reading an article about how human beings think!");
                }
                else if(num==1)
                {
                    bot("Trying to unserstand the laws of thermodynamics!");
                }
                else if(num==2)
                {
                    bot("Surfing the Internet!");
                }
                else if(num==3)
                {
                    bot("Nothing much!");
                }
            }
            else
            {
                bot("I'm your virtual assistant, Pegasus!");
            }
        }
        else if(message.contains("hi")||message.contains("hello")||message.contains("hey"))
        {
            //randomly chooses a reply
            int num=random.nextInt(3);
            if(num==0)
            {
                bot("Hii!");
            }
            else if(num==1)
            {
                bot("Hello!");
            }
            else if(num==2)
            {
                bot("Heyy!");
            }
            else if(num==3)
            {
                bot("Hey buddy!");
            }
        }
        else if(message.contains("bye"))
        {
            bot("Bye, See you soon!!");
        }
        else if(message.contains("i am good")||message.contains("i am great")||message.contains("i am ")&&message.contains("fine")
                ||message.contains("im good"))
        {
            bot("Good to hear");
        }
        else if(message.contains("i am sad")||message.contains("not good")||message.contains("im sad"))
        {
            bot("Oh, I don't think I can be of much help but keep your head up.");
        }
        else if(message.contains("thank"))
        {
            //randomly chooses a reply
            int num=random.nextInt(3);
            if(num==0)
            {
                bot("You're welcome!");
            }
            else if(num==1)
            {
                bot("My pleasure!");
            }
            else if(num==2)
            {
                bot("Happy to help!");
            }
            else if(num==3)
            {
                bot("That's what i'm here for!");
            }
        }
        else if(message.contains("what") && message.contains("name"))
        {
            if(message.contains("your"))
            {
                bot("My name is Pegasus, your personal Chatbot assistant!");
            }
            if(message.contains("my"))
            {
                bot("I dont know what your name is.");
            }
        }
        else if(message.contains("change"))
        {
            bot("Sorry, I am a chatbot, I can't change anything!");
        }
        else if( message.contains("time"))
        {
            String ctime=new String();
            if(time.getHour()>12)
            {
                int hour=time.getHour()-12;
                ctime=ctime+hour+":"+time.getMinute()+":"+time.getSecond()+" PM!";
            }
            else
            {
                ctime=ctime+time.getHour()+":"+time.getMinute()+":"+time.getSecond()+" AM!";
            }
            bot(ctime);
        }
        else if(message.contains("date")||message.contains("month")||message.contains("year")||message.contains("day"))
        {
            String cdate=new String();
            cdate=cdate + date.getDayOfWeek()+","+date.getDayOfMonth()+" "+date.getMonth()+" "+date.getYear();
            bot(cdate);
        }
        else if(message.contains("Good morning"))
        {
            bot("Good morning, Have a nice day!");
        }
        else if(message.contains("Good night"))
        {
            bot("Goodnight, Sweet dreams!");
        }
        else if(message.contains("Good evening"))
        {
            bot("Good Evening!!");
        }
        else if(message.contains("Good") && message.contains("noon"))
        {
            bot("Good Afternoon!!");
        }
        else if(message.contains("clear")&&(message.contains("screen")||message.contains("chat")))
        {
            bot("Wait a few seconds...");
            area.setText("");
        }
        else
        {
            try         //using try catch block for exception handling
            {
                try     //will enter of user asks something which the chatbot doesnt know
                {
                    bot("It seems like I don't understand what you said");
                    bot("Let's look up on the internet, maybe that can help");
                    URL url=new URL("https://duckduckgo.com");
                    URLConnection connection=url.openConnection();
                    connection.connect();
                    bot("Here some results for you...");
                    java.awt.Desktop.getDesktop().browse(java.net.URI.create("https://duckduckgo.com/?q="+message.replace(" ", "+")+"&btnG=Google+Search"));
                }
                catch(Exception ex) //will catch the exception thrown by catch block if the system is not connected to an internet connection
                {
                    bot("Connect with internet connection to get better results...");
                }
            }
            catch(Exception ex1)    //will catch the exception thrown by catch block if the inside try-catch block doesn't work
            {
                int num=random.nextInt(3);
                if(num==0)
                {
                    bot("Sorry, I can't understand you!");
                }
                else if(num==1)
                {
                    bot("Sorry, I didn't understand");
                }
                else if(num==2)
                {
                    bot("My apologies... I didn't understand");
                }
            }
        }
    }
    //end of function actionPerformed()

    //start of function bot() which prints the bot's message
    public static void bot(String message)
    {
        area.append("Pegasus: "+message+"\n");
    }
    //end of function bot()

    //start of main method
    public static void main(String[] args)
    {
        ChatBot cb=new ChatBot("Pegasus");
        cb.setSize(800,605);
        cb.setLocation(50,50);
        bot("Hey im Pegasus, I am a Chatbot. Enter a message to start the conversation.");
    }
    //end of main method
}
//end of class ChatBot
//EOF
