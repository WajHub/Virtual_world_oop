package World;

import GUI.*;
import World.body.Body;
import World.body.animal.*;

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
    private int order;
    private boolean human_special_ability_is_active=false;

    public World() {
        bodies = new java.util.ArrayList<>();
        frame = new WorldFrame();
        panel = new WorldPanel();
        frame.addKeyListener(this);
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
        JSlider slider_x = new JSlider(JSlider.HORIZONTAL, 2, 50, 5); // ustawienia suwaka: wartość minimalna, wartość maksymalna, wartość początkowa
        JSlider slider_y = new JSlider(JSlider.HORIZONTAL, 2, 50, 5); // ustawienia suwaka: wartość minimalna, wartość maksymalna, wartość początkowa
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
        Wolf wolf = new Wolf(new Point(5,5),this);
        Wolf wolf2 = new Wolf(new Point(2,1),this);
        add_body(wolf);
        add_body(wolf2);
        Human human = new Human(new Point(5,1),this);
        add_body(human);
    }

    void make_turn(){
        for(int i=0;i<bodies.size();i++){
            if(bodies.get(i).isAble_to_action()){
                bodies.get(i).increment_age();
                news_panel.add_title_name(bodies.get(i).getName());
                bodies.get(i).move();
                if(!bodies.get(i).isAlive()){
                    delete_body(bodies.get(i));
                }
            }
            else{
                bodies.get(i).setAble_to_action(true);
            }
        }
        turn++;
        human_special_ability();
    }

    private void human_special_ability() {
        if (human_is_alive && human_special_ability_is_active) {
            Human human;
            for (Body body : bodies) {
                if (body instanceof Human) {
                    human = (Human) body;
                    if (human.getAdditionalPower() > 0) {
                        human.setAdditionalPower(human.getAdditionalPower() - 1);
                        human.setPower(human.getPower() -1);
                        break;
                    } else {
                        human_special_ability_is_active = false;
                    }
                }
            }
        }

    }

    public void add_body(Body body){
        for(int i=0;i<bodies.size();i++){
            if(bodies.get(i).getInitiative()<body.getInitiative()){
                bodies.add(i,body);
                boxes[body.getPoint_location().getY()-1][body.getPoint_location().getX()-1].setColor(body.getColor());
                return;
            }
        }
        bodies.add(body);
        boxes[body.getPoint_location().getY()-1][body.getPoint_location().getX()-1].setColor(body.getColor());
    }

    public void delete_body2(Body body){
        if(body instanceof Human){
            human_is_alive=false;
        }
//        boxes[body.getPoint_location().getY()-1][body.getPoint_location().getX()-1].setColor(Color_obj.EMPTY);
        body.setAlive(false);
    }
    public void delete_body(Body body){
        if(body instanceof Human){
            human_is_alive=false;
        }
//        boxes[body.getPoint_location().getY()-1][body.getPoint_location().getX()-1].setColor(Color_obj.EMPTY);
        bodies.remove(body);
    }

    public int free_spaces(Body body){
        int result = 0;
        Point point = body.getPoint_location();
        if(point.getX()==1){
            if(boxes[point.getY()-1][point.getX()].getColor().equals(Color_obj.EMPTY.color)){
                result++;
            }
        }
        else if (point.getX()==x_size){
            if(boxes[point.getY()-1][point.getX()-2].getColor().equals(Color_obj.EMPTY.color)){
                result++;
            }
        }
        else{
            if(boxes[point.getY()-1][point.getX()].getColor().equals(Color_obj.EMPTY.color)){
                result++;
            }
            if(boxes[point.getY()-1][point.getX()-2].getColor().equals(Color_obj.EMPTY.color)){
                result++;
            }
        }
        if(point.getY()==1){
            if(boxes[point.getY()][point.getX()-1].getColor().equals(Color_obj.EMPTY.color)){
                result++;
            }
        }
        else if (point.getY()==y_size){
            if(boxes[point.getY()-2][point.getX()-1].getColor().equals(Color_obj.EMPTY.color)){
                result++;
            }
        }
        else{
            if(boxes[point.getY()][point.getX()-1].getColor().equals(Color_obj.EMPTY.color)){
                result++;
            }
            if(boxes[point.getY()-2][point.getX()-1].getColor().equals(Color_obj.EMPTY.color)){
                result++;
            }
        }
        return result;
    }


    public Body get_body(Point point){
        for(Body body : bodies){
            if(body.getPoint_location().equals(point)){
                return body;
            }
        }
        return null;
    }

    public int getOrder() {
        return order;
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
    }

    private boolean order_is_correct(){
        if(human_is_alive){
            Human human = null;
            for(Body body : bodies){
                if(body instanceof Human){
                    human = (Human) body;
                    break;
                }
            }
            switch (order){
                case KeyEvent.VK_UP:
                    if(human.getPoint_location().getY()>1) return true;
                    return false;
                case KeyEvent.VK_DOWN:
                    if(human.getPoint_location().getY()<y_size) return true;
                    return false;
                case KeyEvent.VK_LEFT:
                    if(human.getPoint_location().getX()>1) return true;
                    return false;
                case KeyEvent.VK_RIGHT:
                    if(human.getPoint_location().getX()<x_size) return true;
                    return false;
                case KeyEvent.VK_1:
                    if(human.can_use_ability()){
                        human_special_ability_is_active=true;
                        human.setAdditionalPower(5);
                        human.setPower(human.getPower()+human.getAdditionalPower());
                        news_panel.add_news("Human use special ability!!!");
                        human.setAgeWhenUsedSpecialSkill(human.getAge());
                        return false;
                    }
                    else{
                        news_panel.add_news("Human can't use special ability!");
                        return false;
                    }
            }
            return false;
        }
        return true;
    }

    @Override
    public void keyPressed(KeyEvent e) {
        order = e.getKeyCode();
        if(order_is_correct()){
            make_turn();
            panel.description("Turn: " + turn+" |  Human ability active: "+human_special_ability_is_active);
        }

    }

    @Override
    public void keyReleased(KeyEvent e) {

    }
}
