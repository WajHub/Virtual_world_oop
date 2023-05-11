package GUI;

import javax.swing.*;
import java.awt.*;

public class LegendPanel extends JPanel {
    public LegendPanel() {
        this.setFocusable(true);
        this.setBackground(new Color(217, 217, 217));
        this.setBounds(WorldFrame.FREE_SPACE,BoardPanel.height+WorldFrame.FREE_SPACE*2,
                WorldFrame.SCREEN_WIDTH-WorldFrame.FREE_SPACE*2, WorldFrame.SCREEN_HEIGHT-BoardPanel.height-WorldFrame.FREE_SPACE*4); // ustawienie pozycji i rozmiaru panelu wewnątrz panelu nadrzędnego
        this.setLayout(new FlowLayout(FlowLayout.CENTER));
    }
}
