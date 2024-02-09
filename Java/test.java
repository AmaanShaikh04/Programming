interface ABC
{
	void check ();
	void perform ();
}

interface DEF extends ABC
{
	boolean X = false;
	boolean Y = true;
	boolean isY ();
}

class HIJ implements ABC
{
	private String name;
	HIJ (String name)
	{ this.name=name; } 
	String getName()
	{ return name; }
	public void check () {}
	public void perform () {}
}

class XYZ extends HIJ
{
XYZ (String name)
{ super (name);}
public void check ()
{ System.out.print ("1 ");}
public void perform ()
{ System.out.print ("0"); } 
public String toString()
{ return getName(); }
}

public class Alpha
{
public static void main(String[] args)
{
XYZ c = new XYZ ("abc");
c.perform();
System.out.println (c.toString());
ABC ss = c;
ss.check ();
System.out.println (ss.toString());
}
}
