package GUI;

import javax.swing.*;
import java.awt.*;

public class Box extends JButton {
    private int x;
    private int y;
    private Color_obj color_obj = Color_obj.EMPTY;

    public Box(int x, int y) {
        this.x = x;
        this.y = y;
        this.setBackground(color_obj.getColor());
//        this.setText("x:"+x+" y: "+y);
    }

    public void setColor(Color color) {
        this.setColor(color);
    }

    public Color getColor() {
        return color_obj.getColor();
    }

    @Override
    public int getX() {
        return x;
    }

    @Override
    public int getY() {
        return y;
    }
}
