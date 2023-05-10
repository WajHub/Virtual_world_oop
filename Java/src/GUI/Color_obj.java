package GUI;
import java.awt.Color;
public enum Color_obj {
    BACKGROUND(new Color(194, 164, 164)),
    EMPTY(new Color(89, 89, 89));
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
