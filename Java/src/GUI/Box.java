package GUI;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import World.World;
import World.Point;
import World.body.animal.*;
import World.body.plant.*;

public class Box extends JButton{
    private World world;
    private int x;
    private int y;
    private Color color = Color_obj.EMPTY.getColor();

    public Box(int x, int y, World world) {
        this.world = world;
        this.x = x;
        this.y = y;
        this.setBackground(color);
        setFocusable(false);
        this.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(color.equals(Color_obj.EMPTY.getColor())) {
                    String[] possibleValues = {"Antelope", "Fox", "Sheep", "Tortoise", "Wolf", "Belladonna", "Dandelion", "Grass", "Guarana", "Sosnowsky's Hogweed"};

                    Object selectedValue = JOptionPane.showInputDialog(null,
                            "Choose one", "Choose new body",
                            JOptionPane.INFORMATION_MESSAGE, null,
                            possibleValues, possibleValues[0]);
                    if (selectedValue != null) {
                        if (selectedValue.equals("Antelope")) {
                            world.add_body(new Antelope(new Point(x, y), world));
                            world.getNews_panel().add_news("New Antelope at (" + x + "," + y + ")");
                        } else if (selectedValue.equals("Fox")) {
                            world.add_body(new Fox(new Point(x,y), world));
                            world.getNews_panel().add_news("New fox at (" + x + "," + y + ")");
                        } else if (selectedValue.equals("Sheep")) {
                            world.add_body(new Sheep(new Point(x, y), world));
                            world.getNews_panel().add_news("New sheep at (" + x + "," + y + ")");
                        } else if (selectedValue.equals("Tortoise")) {
                            world.add_body(new Tortoise(new Point(x, y), world));
                            world.getNews_panel().add_news("New tortoise at (" + x + "," + y + ")");
                        } else if (selectedValue.equals("Wolf")) {
                            world.add_body(new Wolf(new Point(x, y), world));
                            world.getNews_panel().add_news("New wolf at (" + x + "," + y + ")");
                        } else if (selectedValue.equals("Belladonna")) {
                            world.add_body(new Belladonna(new Point(x, y), world));
                            world.getNews_panel().add_news("New belladonna at (" + x + "," + y + ")");
                        } else if (selectedValue.equals("Dandelion")) {
                            world.add_body(new Dandelion(new Point(x, y), world));
                            world.getNews_panel().add_news("New dandelion at (" + x + "," + y + ")");
                        } else if (selectedValue.equals("Grass")) {
                            world.add_body(new Grass(new Point(x, y), world));
                            world.getNews_panel().add_news("New grass at (" + x + "," + y + ")");
                        } else if (selectedValue.equals("Guarana")) {
                            world.add_body(new Guarana(new Point(x, y), world));
                            world.getNews_panel().add_news("New guarana at (" + x + "," + y + ")");
                        } else if (selectedValue.equals("Sosnowsky's Hogweed")) {
                            world.add_body(new SosnowskysHogweed(new Point(x, y), world));
                            world.getNews_panel().add_news("New Sosnowsky's Hogweed at (" + x + "," + y + ")");
                        } else {
                            world.getNews_panel().add_news("Are (" + x + "," + y + ") is occupied!");
                        }
                    }
                }

            }
        });
    }

    public void setColor(Color_obj color2){
        color=color2.getColor();
        this.setBackground(color);
    }

    public Color getColor() {
        return color;
    }

}
