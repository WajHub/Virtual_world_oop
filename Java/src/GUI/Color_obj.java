package GUI;
import java.awt.Color;
public enum Color_obj {
    BACKGROUND(new Color(194, 164, 164)),
    EMPTY(new Color(121, 121, 121)),
    HUMAN(new Color(220, 147, 147)),
    WOLF(new Color(0, 0, 0)),
    FOX(new Color(213, 85, 20)),
    TORTOISE(new Color(0, 255, 0)),
    ANTELOPE(new Color(236, 255, 0)),
    SHEEP(new Color(255, 255, 255)),
    GRASS(new Color(0, 255, 0)),
    BELLADONNA(new Color(124, 21, 49)),
    DANDELION(new Color(255, 255, 0)),
    SOSNOWSKYSHOGWEED(new Color(94, 178, 217)),;

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
