package GUI;
import java.awt.Color;
public enum Color_obj {
    BACKGROUND(new Color(194, 164, 164)),
    HUMAN(new Color(220, 147, 147)),
    WOLF(new Color(0, 0, 0)),
    EMPTY(new Color(121, 121, 121));
    public Color color;
    Color_obj(Color color) {
        this.color = color;
    }
    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }
}
