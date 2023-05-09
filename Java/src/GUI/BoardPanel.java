package GUI;

import javax.swing.*;
import java.awt.*;

public class BoardPanel extends JPanel {
    final static int width = WorldFrame.SCREEN_WIDTH-400;
    final static int height = WorldFrame.SCREEN_HEIGHT-200;
    public BoardPanel() {
        this.setFocusable(true);
        this.setBackground(Color.white);
        this.setBounds(WorldFrame.FREE_SPACE, WorldFrame.FREE_SPACE, width, height); // ustawienie pozycji i rozmiaru panelu wewnątrz panelu nadrzędnego
    }
}
