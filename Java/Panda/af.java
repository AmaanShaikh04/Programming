import java.util.Scanner;

public class af
{
    public static void main(String[] args)
    {
        database ob[] = new database[20];

        for(int i=0;i<1;i++)
        {
            ob[i]=new database();
            System.out.println("Roll number: "+(i+1));
            ob[i].accept();
            ob[i].grade=ob[i].grade();
        }
        for(int j=0;j<1;j++)
        {
            ob[j].display();
        }
    }

}

class database
{
    Scanner sc=new Scanner(System.in);
    String sub1="Maths";
    String sub2="English";
    String sub3="Science";
    String sub4="Hindi";
    String sub5="Computer";
    int mm;
    int em;
    int sm;
    int hm;
    int cm;
    String stuname;
    int total;
    double grade;
    void accept()
    {
        System.out.println("Enter the student name: ");
        stuname=sc.nextLine();
        System.out.println("Enter the marks of student for "+(sub1));
        mm=sc.nextInt();
        System.out.println("Enter the marks of student for "+(sub2));
        em=sc.nextInt();
        System.out.println("Enter the marks of student for "+(sub3));
        sm=sc.nextInt();
        System.out.println("Enter the marks of student for "+(sub4));
        hm=sc.nextInt();
        System.out.println("Enter the marks of student for "+(sub5));
        cm=sc.nextInt();
    }
    void display()
    {
        System.out.println("The database entered is:");
        System.out.println("Name \tMaths \tEnglish \tScience \tHindi \tComputer");

        System.out.println(stuname+"\t\t" +mm+"\t\t"+ em +"\t\t\t"+sm+"\t\t\t"+hm+"\t\t"+cm);
    }
    double grade()
    {
        total=mm+em+sm+hm+cm;
        grade=total/50;
        return grade;
    }
}