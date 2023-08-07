import javax.swing.*;  
import javax.swing.tree.DefaultMutableTreeNode;  

public class Tree_CCA5
{  
    JFrame frame;  
    Tree_CCA5()
    {  
        frame=new JFrame();   
        DefaultMutableTreeNode style=new DefaultMutableTreeNode("Style");  
        DefaultMutableTreeNode color=new DefaultMutableTreeNode("color");  
        DefaultMutableTreeNode font=new DefaultMutableTreeNode("font");  
    
        style.add(color);  
        style.add(font);  
    
        DefaultMutableTreeNode red=new DefaultMutableTreeNode("red");  
        DefaultMutableTreeNode blue=new DefaultMutableTreeNode("blue");  
        DefaultMutableTreeNode black=new DefaultMutableTreeNode("black");  
        DefaultMutableTreeNode green=new DefaultMutableTreeNode("green");  
        color.add(red); color.add(blue); color.add(black); color.add(green);      
    
        JTree tree=new JTree(style);  
    
        frame.add(tree);  
        frame.setSize(400,200);  
        frame.setVisible(true);  
    }  
    public static void main(String[] args) 
    {  
        new Tree_CCA5();  
    }
}  