package GUI;

import javax.swing.*;
import java.awt.*;

public class BoardPanel extends JPanel {
    final int width = WorldFrame.SCREEN_WIDTH-250;
    final int height = WorldFrame.SCREEN_HEIGHT-150;
    public BoardPanel() {
        this.setFocusable(true);
        this.setBackground(Color.white);
        this.setPreferredSize(new Dimension(width, height));
        this.setBounds(1,1,width,height);
    }
}
