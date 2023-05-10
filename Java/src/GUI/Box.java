package GUI;

import javax.swing.*;
import java.awt.*;

public class Box extends JButton {
    private int x;
    private int y;
    private Color color = Color_obj.EMPTY.getColor();

    public Box(int x, int y) {
        this.x = x;
        this.y = y;
        this.setBackground(color);
//        this.setText("x:"+x+" y: "+y);
    }

    public void setColor(Color_obj color2){
        color=color2.getColor();
        this.setBackground(color);
    }

    public Color getColor() {
        return color;
    }

//    @Override
//    public int getX() {
//        return x;
//    }
//
//    @Override
//    public int getY() {
//        return y;
//    }
}
