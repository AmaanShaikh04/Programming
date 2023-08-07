import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.*;

public class Key extends JFrame implements KeyListener {
    JFrame window = new JFrame();
    JLabel response_label = new JLabel("Type a key");
    JTextArea txt_area = new JTextArea();

    Key() {
        window.setLayout(null);
        window.setSize(new Dimension(720, 480));
        window.setDefaultCloseOperation(EXIT_ON_CLOSE);
        window.setTitle("Key Listener Experiment 1");
        txt_area.setBounds(50, 50, 400, 300);
        txt_area.setBackground(Color.black);
        txt_area.setForeground(Color.white);
        response_label.setBounds(10, 1, 100, 20);
        // adding the desired components
        window.add(response_label);
        window.add(txt_area);
        //-----------------------//
        txt_area.addKeyListener(this);
        window.setVisible(true);
    }

    @Override
    public void keyTyped(KeyEvent e) {
        response_label.setText("Key Typed");
    }

    @Override
    public void keyPressed(KeyEvent e) {
        response_label.setText("Key Pressed");
    }

    @Override
    public void keyReleased(KeyEvent e) {
        response_label.setText("Key Released");
    }

    public static void main(String[] args) {
        new Key();
    }
}