package GUI;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class WorldPanel extends JPanel{
    public WorldPanel() {
        this.setFocusable(true);
        this.setBackground(Color.gray);
        this.setPreferredSize(new Dimension(WorldFrame.SCREEN_WIDTH, WorldFrame.SCREEN_HEIGHT));
    }
}
