package GUI;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;

public class WorldPanel extends JPanel{
    private LegendPanel legendPanel = new LegendPanel();
    private JLabel label_descritption = new JLabel("Turn: 0  Human ability is active: false");
    public WorldPanel() {
        this.setFocusable(true);
        this.setBackground(Color_obj.BACKGROUND.getColor());
        this.setPreferredSize(new Dimension(WorldFrame.SCREEN_WIDTH, WorldFrame.SCREEN_HEIGHT));
        this.setLayout(null);
        legendPanel.add(label_descritption);
        Font font = label_descritption.getFont(); // Pobranie istniejącej czcionki
        font = font.deriveFont(17f); // Utworzenie nowej czcionki z tymi samymi właściwościami, ale z rozmiarem 17 punktów
        label_descritption.setFont(font); // Ustawienie nowej czcionki dla etykiety
        legend_bodies();
        this.add(legendPanel);
        this.add(new MenuPanel());
    }
    private void legend_bodies(){
        Font font = label_descritption.getFont(); // Pobranie istniejącej czcionki
        font = font.deriveFont(17f); // Utworzenie nowej czcionki z tymi samymi właściwościami, ale z rozmiarem 17 punktów

        JLabel wolf = new JLabel("  Wolf   ");
        wolf.setBorder(new EmptyBorder(4,4,4,4));
        wolf.setFont(font);
        wolf.setBackground(Color_obj.WOLF.getColor());
        wolf.setForeground(Color.white);
        wolf.setOpaque(true);
        legendPanel.add(wolf);

        JLabel human = new JLabel("  Human   ");
        human.setBorder(new EmptyBorder(4,4,4,4));
        human.setFont(font);
        human.setBackground(Color_obj.HUMAN.getColor());
        human.setOpaque(true);
        legendPanel.add(human);
    }
    public void description(String text){
        label_descritption.setText(text);
    }
}
