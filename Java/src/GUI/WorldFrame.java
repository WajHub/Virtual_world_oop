package GUI;

import javax.swing.*;


public class WorldFrame extends JFrame {
    final static public int FREE_SPACE=10;
    final static public int  SCREEN_HEIGHT=800;
    final static public int SCREEN_WIDTH=1000;
    static public int UNIT_SIZE=25;
    public WorldFrame(){
        this.setTitle("Virtual World.World");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
        this.setLocation(300,50);
        this.setResizable(false);
        this.pack();
    }
}