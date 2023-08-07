/*Write a program to calculate the salary of an employee using Single Inheritance. (Use proper visibility modes to declare the data members).

        i. Create a class "Employee" as base class having data members empId, empName.

        ii. Derive the class "Salary" from "Employee" having data members basicSalary, DA.

        - Define accept() method to accept the employee  details.
        - Define the method totalSalary() to calculate the total salary. (TotalSalary=basicSalary+DA)
        - Define display() method to show all the details of Employee.
*/
import java.util.*;
public class Employee
{
    protected int empId;
    protected String empName;
    public static void main(String args[])
    {
        Salary obj = new Salary();
        obj.accept();
        obj.totalSalary();
        obj.display();
    }
}
class Salary extends Employee
{
    private double basicSalary, DA, TotalSalary;
    public void accept()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Employee ID");
        empId=sc.nextInt();
        System.out.println("Enter Employee Name");
        empName=sc.next();
        System.out.println("Enter Basic Salary");
        basicSalary=sc.nextDouble();
        System.out.println("Enter DA");
        DA=sc.nextDouble();
    }
    public void totalSalary()
    {
        TotalSalary=basicSalary+DA;
    }
    public void display()
    {
        System.out.println("Employee details:\n\n");
        System.out.println("Employee ID:\t"+empId);
        System.out.println("Employee Name:\t"+empName);
        System.out.println("Basic Salary:\t"+basicSalary);
        System.out.println("DA:\t\t"+DA);
        System.out.println("Total Salary:\t"+TotalSalary);
    }
}
