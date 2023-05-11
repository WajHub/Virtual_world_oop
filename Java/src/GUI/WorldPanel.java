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

        JLabel move = new JLabel("                  Move - arrays (when human is alive)                                                        ");
        move.setBorder(new EmptyBorder(4,4,4,4));
        move.setFont(font);
        legendPanel.add(move);

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

        JLabel antelope = new JLabel("  Antelope   ");
        antelope.setBorder(new EmptyBorder(4,4,4,4));
        antelope.setFont(font);
        antelope.setBackground(Color_obj.ANTELOPE.getColor());
        antelope.setOpaque(true);
        legendPanel.add(antelope);

        JLabel fox = new JLabel("  Fox   ");
        fox.setBorder(new EmptyBorder(4,4,4,4));
        fox.setFont(font);
        fox.setBackground(Color_obj.FOX.getColor());
        fox.setOpaque(true);
        legendPanel.add(fox);

        JLabel sheep = new JLabel("  Sheep   ");
        sheep.setBorder(new EmptyBorder(4,4,4,4));
        sheep.setFont(font);
        sheep.setBackground(Color_obj.SHEEP.getColor());
        sheep.setOpaque(true);
        legendPanel.add(sheep);

        JLabel tortoise = new JLabel("  Tortoise   ");
        tortoise.setBorder(new EmptyBorder(4,4,4,4));
        tortoise.setFont(font);
        tortoise.setBackground(Color_obj.TORTOISE.getColor());
        tortoise.setOpaque(true);
        legendPanel.add(tortoise);

        JLabel grass = new JLabel("  Grass   ");
        grass.setBorder(new EmptyBorder(4,4,4,4));
        grass.setFont(font);
        grass.setBackground(Color_obj.GRASS.getColor());
        grass.setOpaque(true);
        legendPanel.add(grass);
    }
    public void description(String text){
        label_descritption.setText(text);
    }
}
