package World;

import GUI.*;
import World.body.Body;
import World.body.animal.Wolf;

import javax.swing.*;
import javax.swing.Box;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.List;

public class World implements KeyListener {
    private WorldFrame frame;
    private WorldPanel panel;
    private BoardPanel board_panel;
    private NewsPanel news_panel;
    private List<Body> bodies;
    private GUI.Box boxes [][];
    private int x_size = 20;
    private int y_size = 20;
    private int turn = 0;
    private boolean human_is_alive=true;

    public World() {
        bodies = new java.util.ArrayList<>();
        frame = new WorldFrame();
        panel = new WorldPanel();
        news_panel = new NewsPanel();
        panel.add(news_panel);
        frame.add(panel);
        frame.pack();
        select_size();
    }

    void select_size() {
        // utwórz komponenty
        JLabel label_x = new JLabel("Select width: " + x_size);
        JLabel label_y = new JLabel("Select height: " + y_size);
        JSlider slider_x = new JSlider(JSlider.HORIZONTAL, 5, 50, 20); // ustawienia suwaka: wartość minimalna, wartość maksymalna, wartość początkowa
        JSlider slider_y = new JSlider(JSlider.HORIZONTAL, 5, 50, 20); // ustawienia suwaka: wartość minimalna, wartość maksymalna, wartość początkowa
        JButton button = new JButton("OK");

        // utwórz okno dialogowe
        JFrame dialog = new JFrame("Select board size");
        dialog.setSize(300, 200);
        dialog.setLayout(new BoxLayout(dialog.getContentPane(), BoxLayout.Y_AXIS));

        // dodaj komponenty do okna dialogowego
        dialog.add(label_x);
        dialog.add(slider_x);
        dialog.add(Box.createVerticalStrut(20)); // odstęp między komponentami
        dialog.add(label_y);
        dialog.add(slider_y);
        dialog.add(Box.createVerticalStrut(20)); // odstęp między komponentami
        dialog.add(button);

        // dodaj słuchacza zdarzeń do suwaka
        slider_x.addChangeListener(new ChangeListener() {
            public void stateChanged(ChangeEvent e) {
                x_size = slider_x.getValue();
                label_x.setText("Select width: " + x_size);
            }
        });
        slider_y.addChangeListener(new ChangeListener() {
            public void stateChanged(ChangeEvent e) {
                y_size = slider_y.getValue();
                label_y.setText("Select height: " + y_size);
            }
        });
        // dodaj słuchacza zdarzeń do przycisku OK
        button.addActionListener(e -> {
            x_size = slider_x.getValue();
            y_size = slider_y.getValue();
            // zrobić coś z wartością, na przykład zamknąć okno dialogowe i rozpocząć grę
            dialog.dispose();
            start_game();
        });
        // pokaż okno dialogowe
        dialog.setVisible(true);
    }

    void start_game() {
        board_panel = new BoardPanel(x_size, y_size);
        panel.add(board_panel);
        boxes = new GUI.Box[x_size][y_size];
        for(int i=0;i<x_size;i++){
            for(int j=0;j<y_size;j++){
                boxes[i][j] = new GUI.Box(i ,j);
                board_panel.add(boxes[i][j]);
            }
        }
        frame.pack();
        //Dodawnie organizmow
        Wolf wolf = new Wolf(new Point(1,1),this);
        add_body(wolf);
    }

    void make_turn(){
        for(Body body: bodies){
            if(body.isAble_to_action()){
                body.increment_age();
                body.move();
                if(!body.isAlive()){
                    delete_body(body);
                }
            }
            else{
                body.setAble_to_action(true);
            }
        }
    }
    public void add_body(Body body){
        for(int i=0;i<bodies.size();i++){
            if(bodies.get(i).getInitiative()<body.getInitiative()){
                bodies.add(i,body);
                boxes[body.getPoint_location().getX()-1][body.getPoint_location().getY()-1].setColor(body.getColor().getColor());
                return;
            }
        }
        bodies.add(body);
        boxes[body.getPoint_location().getX()-1][body.getPoint_location().getY()-1].setColor(body.getColor().getColor());
    }

    public void delete_body2(Body body){
        boxes[body.getPoint_location().getX()-1][body.getPoint_location().getY()-1].setColor(Color_obj.EMPTY.color);
        body.setAlive(false);
    }
    public void delete_body(Body body){
        boxes[body.getPoint_location().getX()-1][body.getPoint_location().getY()-1].setColor(Color_obj.EMPTY.color);
        bodies.remove(body);
    }
    public Body get_body(Point point){
        for(Body body : bodies){
            if(body.getPoint_location().equals(point)){
                return body;
            }
        }
        return null;
    }

    public NewsPanel getNews_panel() {
        return news_panel;
    }

    public GUI.Box[][] getBoxes() {
        return boxes;
    }

    public WorldFrame getFrame() {
        return frame;
    }

    public int getX_size() {
        return x_size;
    }

    public int getY_size() {
        return y_size;
    }

    @Override
    public void keyTyped(KeyEvent e) {
        if (e.getKeyCode() == KeyEvent.VK_ENTER) {
            make_turn();
        }
        System.out.println("keyTyped");
    }

    @Override
    public void keyPressed(KeyEvent e) {

    }

    @Override
    public void keyReleased(KeyEvent e) {

    }
}
