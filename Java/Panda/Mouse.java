import java.awt.*;
import java.awt.event.*;
public class Mouse extends Frame implements MouseListener{
    Label l,m;
    Mouse(){
        addMouseListener(this);

        l=new Label();
        m=new Label();
        l.setBounds(20,50,100,20);
        m.setBounds(40,100,100,20);
        add(l);
        setSize(300,300);
        setLayout(null);
        setVisible(true);

    }
    public void mouseClicked(MouseEvent e) { l.setText("Mouse Clicked"); Location();}
    public void mouseEntered(MouseEvent e) { l.setText("Mouse Entered"); Location();}
    public void mouseExited(MouseEvent e) { l.setText("Mouse Exited"); Location();}
    public void mousePressed(MouseEvent e) { l.setText("Mouse Pressed"); Location();}
    public void mouseReleased(MouseEvent e) { l.setText("Mouse Released"); Location();}
    public void Location() {
        Point p = MouseInfo.getPointerInfo().getLocation();
        int x = p.x;
        int y = p.y;
        m.setText("X: " +x+ "    Y: " +y);
    }
    public static void main(String[] args) {
        new Mouse();
    }
}