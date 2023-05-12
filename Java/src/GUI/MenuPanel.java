package GUI;

import World.World;
import World.body.Body;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

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
            JFrame dialog = new JFrame("Select file to load");
            dialog.setSize(300, 200);

            JFileChooser fileChooser = new JFileChooser();
            fileChooser.setCurrentDirectory(new java.io.File("./saves"));
            int result = fileChooser.showOpenDialog(dialog);

            if(result==JFileChooser.APPROVE_OPTION){
                File file = fileChooser.getSelectedFile();
                try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(file))) {
                    // Deserialize the object from the selected file
                    Object deserializedObject = in.readObject();
                    // Do something with the deserialized object
                    if(deserializedObject instanceof World){
                        world.load_game((World) deserializedObject);
                        world.getNews_panel().add_news("Game loaded from file: "+file.getName());
                    }
                } catch (IOException | ClassNotFoundException er) {
                    // Handle any exceptions that occur during deserialization
                    er.printStackTrace();
                }
            }


        }else if(e.getSource()==save_game){
            LocalDateTime currentTime = LocalDateTime.now();
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd-HH-mm-ss");
            String fileName = currentTime.format(formatter)+ ".ser";
            try {
                // Utwórz obiekt ObjectOutputStream
                ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream("saves/"+fileName));

                // Zapisz obiekt do pliku
                outputStream.writeObject(world);
                world.getNews_panel().add_news("Game saved to file: "+fileName);


                // Zamknij strumień wyjściowy
                outputStream.close();
            } catch (IOException er) {
                er.printStackTrace();
            }
        }
    }
}
