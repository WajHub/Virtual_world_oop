package GUI;

import javax.swing.*;


public class WorldFrame extends JFrame {
    final static public int  SCREEN_HEIGHT=600;
    final static public int SCREEN_WIDTH=800;
    static public int UNIT_SIZE=25;
    public WorldFrame(){
        this.setTitle("Virtual World");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
        this.setLocation(300,50);
        this.setResizable(false);
        this.pack();
    }
}