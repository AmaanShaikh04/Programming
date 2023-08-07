package SamplePackage;

/*Write a program to

         i. Create a package named "SamplePackage". Add class "ClassA" in the package (Use package statement).

         ii. Create a method  display() in the class. 

         iii. Create another class "ClassB" which should not be part of SamplePackage. (Use import statement to import SamplePackage)

          iv. Create object of ClassA in ClassB.

          v. Call display() method to display the message "I am in ClassA display()".
 */
public class ClassA
{
    public void display(String str)
    {
        System.out.println(str);
    }
}
