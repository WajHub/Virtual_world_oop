package GUI;
import java.awt.Color;
import java.io.Serializable;

public enum Color_obj implements Serializable {

    BACKGROUND(new Color(194, 164, 164)),
    EMPTY(new Color(121, 121, 121)),
    HUMAN(new Color(220, 147, 147)),
    WOLF(new Color(0, 0, 0)),
    FOX(new Color(213, 85, 20)),
    TORTOISE(new Color(23, 70, 23)),
    ANTELOPE(new Color(175, 110, 77)),
    SHEEP(new Color(255, 255, 255)),
    GRASS(new Color(0, 255, 0)),
    BELLADONNA(new Color(91, 14, 35)),
    DANDELION(new Color(255, 255, 0)),
    SOSNOWSKYSHOGWEED(new Color(94, 178, 217)),
    GUARANA(new Color(190, 57, 81));

    public Color color;
    private static final long serialVersionUID = 0x5a0aL;

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
