package GUI;

import javax.swing.*;
import java.awt.*;

public class BoardPanel extends JPanel {
    final static int width = WorldFrame.SCREEN_WIDTH-400;
    final static int height = WorldFrame.SCREEN_HEIGHT-200;
    private int x_size;
    private int y_size;

    public BoardPanel(int x_size, int y_size) {
        this.x_size = x_size;
        this.y_size = y_size;
        this.setFocusable(true);
        this.setBackground(Color.white);
        this.setBounds(WorldFrame.FREE_SPACE, WorldFrame.FREE_SPACE, width, height); // ustawienie pozycji i rozmiaru panelu wewnątrz panelu nadrzędnego
        this.setLayout(new GridLayout(x_size, y_size));
    }
}
