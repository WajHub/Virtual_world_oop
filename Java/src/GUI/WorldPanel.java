package GUI;

import javax.swing.*;
import java.awt.*;

public class WorldPanel extends JPanel{
    public WorldPanel() {
        this.setFocusable(true);
        this.setBackground(Color_obj.BACKGROUND.getColor());
        this.setPreferredSize(new Dimension(WorldFrame.SCREEN_WIDTH, WorldFrame.SCREEN_HEIGHT));
        this.setLayout(null);
        this.add(new LegendPanel());
        this.add(new MenuPanel());
    }
}
