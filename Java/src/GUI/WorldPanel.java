package GUI;

import javax.swing.*;
import java.awt.*;

public class WorldPanel extends JPanel{
    private LegendPanel legendPanel = new LegendPanel();
    private JLabel label_descritption = new JLabel("Turn: 0  Human ability is active: 0");
    public WorldPanel() {
        this.setFocusable(true);
        this.setBackground(Color_obj.BACKGROUND.getColor());
        this.setPreferredSize(new Dimension(WorldFrame.SCREEN_WIDTH, WorldFrame.SCREEN_HEIGHT));
        this.setLayout(null);
        legendPanel.add(label_descritption);
        this.add(legendPanel);
        this.add(new MenuPanel());
    }
    public void description(String text){
        label_descritption.setText(text);
    }
}
