import javax.swing.*;
import java.awt.*;


public class GameFrame extends JFrame {
    final static public int  SCREEN_HEIGHT=500;
    final static public int SCREEN_WIDTH=700;
    static public int UNIT_SIZE=25;
    GameFrame(){
        this.add(new GamePanel());
        this.setTitle("Virtual World");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
        this.setLocation(300,50);
        this.setResizable(false);
        this.pack();
    }
}