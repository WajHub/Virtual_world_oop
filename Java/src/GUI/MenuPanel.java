package GUI;

import javax.swing.*;
import java.awt.*;

public class MenuPanel extends JPanel {
    final static int height = 50;
    public MenuPanel() {
        this.setFocusable(true);
        this.setBackground(Color.white);
        this.setBounds(WorldFrame.FREE_SPACE*3+BoardPanel.width, WorldFrame.FREE_SPACE,
                WorldFrame.SCREEN_WIDTH-(WorldFrame.FREE_SPACE*4+BoardPanel.width), height); // ustawienie pozycji i rozmiaru panelu wewnątrz panelu nadrzędnego
    }
}
