package GUI;

import World.World;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class MenuPanel extends JPanel implements ActionListener {
    private World world;
    final static int height = 50;
    private JButton new_game;
    private JButton save_game;
    private JButton load_game;
    public MenuPanel(World world) {
        this.world = world;
        this.setBackground(Color.white);
        this.setBounds(WorldFrame.FREE_SPACE*3+BoardPanel.width, WorldFrame.FREE_SPACE,
                WorldFrame.SCREEN_WIDTH-(WorldFrame.FREE_SPACE*4+BoardPanel.width), height); // ustawienie pozycji i rozmiaru panelu wewnątrz panelu nadrzędnego
        this.setLayout(new FlowLayout(FlowLayout.CENTER));
        new_game = new JButton("New Game");
        new_game.addActionListener(this);
        new_game.setFocusable(false);
        this.add(new_game);
        save_game = new JButton("Save Game");
        save_game.addActionListener(this);
        save_game.setFocusable(false);
        this.add(save_game);
        load_game = new JButton("Load Game");
        load_game.addActionListener(this);
        load_game.setFocusable(false);
        this.add(load_game);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==new_game){
            world.new_game();
        }
        else if(e.getSource()==load_game){

        }else if(e.getSource()==save_game){
            world.save_game();
        }
    }
}
