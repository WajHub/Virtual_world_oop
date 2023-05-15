package World;

import GUI.*;
import World.body.Body;
import World.body.animal.*;
import World.body.plant.*;

import javax.swing.*;
import javax.swing.Box;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.LinkedList;
import java.util.List;
import java.util.concurrent.ThreadLocalRandom;

public class World implements KeyListener, Serializable {
    private static final long serialVersionUID = 3688349504550707806L;

    private WorldFrame frame=null;
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
        bodies = new LinkedList<>();
        frame = new WorldFrame();
        panel = new WorldPanel(this);
        frame.addKeyListener(this);
        news_panel = new NewsPanel();
        panel.add(news_panel);
        frame.add(panel);
        frame.pack();
        select_size();
    }
    public void new_game(){
        x_size = 20;
        y_size = 20;
        if(board_panel!=null){
            panel.remove(board_panel);
        }
        if(news_panel!=null){
            panel.remove(news_panel);
        }
        frame.repaint();
        select_size();
        news_panel = new NewsPanel();
        panel.add(news_panel);
        panel.refresh();
        bodies.clear();
        turn = 0;
        human_is_alive=true;
        human_special_ability_is_active=false;
    }

    public void load_game(World new_world){
        if(board_panel!=null){
            panel.remove(board_panel);
        }
        if(news_panel!=null){
            panel.remove(news_panel);
        }
        this.turn = new_world.turn;
        this.human_is_alive = new_world.human_is_alive;
        this.human_special_ability_is_active = new_world.human_special_ability_is_active;
        this.x_size=new_world.x_size;
        this.y_size=new_world.y_size;

        board_panel = new BoardPanel(y_size, x_size);
        board_panel.addKeyListener(this);

        news_panel = new NewsPanel();

        panel.add(board_panel);
        panel.add(news_panel);

        boxes = new GUI.Box[y_size][x_size];
        for(int i=0;i<y_size;i++){
            for(int j=0;j<x_size;j++){
                boxes[i][j] = new GUI.Box(j+1 ,i+1,this);
                board_panel.add(boxes[i][j]);
            }
        }
        bodies.clear();
        for(Body body: new_world.bodies){
            add_body(body);
            body.setWorld(this);
        }
        frame.repaint();
        frame.pack();

    }


    void select_size() {
        // utwórz komponenty
        JLabel label_x = new JLabel("Select width: " + x_size);
        JLabel label_y = new JLabel("Select height: " + y_size);
        JSlider slider_x = new JSlider(JSlider.HORIZONTAL, 10, 50, 20); // ustawienia suwaka: wartość minimalna, wartość maksymalna, wartość początkowa
        JSlider slider_y = new JSlider(JSlider.HORIZONTAL, 10, 50, 20); // ustawienia suwaka: wartość minimalna, wartość maksymalna, wartość początkowa
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
        board_panel = new BoardPanel(y_size, x_size);
        board_panel.addKeyListener(this);
        panel.add(board_panel);
        boxes = new GUI.Box[y_size][x_size];
        for(int i=0;i<y_size;i++){
            for(int j=0;j<x_size;j++){
                boxes[i][j] = new GUI.Box(j+1 ,i+1,this);
                board_panel.add(boxes[i][j]);
            }
        }
        frame.pack();
        //Dodawnie organizmow
        add_initial_bodies();
        make_turn();
        //
    }

    public void add_initial_bodies(){
        int amount;
        int random_x = ThreadLocalRandom.current().nextInt(1, x_size+1) ;
        int random_y = ThreadLocalRandom.current().nextInt(1, y_size+1) ;
        Human human = new Human(new Point(random_x,random_y),this);
        add_body(human);
        //antelope
        amount = x_size*y_size/101;
        for(int i=0;i<amount;i++){
            random_x = ThreadLocalRandom.current().nextInt(1, x_size+1) ;
            random_y = ThreadLocalRandom.current().nextInt(1, y_size+1) ;
            if(boxes[random_y-1][random_x-1].getColor()==Color_obj.EMPTY.getColor()){
                Antelope antelope = new Antelope(new Point(random_x,random_y),this);
                add_body(antelope);
            }
            else i--;
        }
        //fox
        amount = x_size*y_size/101;
        for(int i=0;i<amount;i++){
            random_x = ThreadLocalRandom.current().nextInt(1, x_size+1) ;
            random_y = ThreadLocalRandom.current().nextInt(1, y_size+1) ;
            if(boxes[random_y-1][random_x-1].getColor()==Color_obj.EMPTY.getColor()){
                Fox fox = new Fox(new Point(random_x,random_y),this);
                add_body(fox);
            }
            else i--;
        }
        //sheep
        amount = x_size*y_size/101;
        for(int i=0;i<amount;i++){
            random_x = ThreadLocalRandom.current().nextInt(1, x_size+1) ;
            random_y = ThreadLocalRandom.current().nextInt(1, y_size+1) ;
            if(boxes[random_y-1][random_x-1].getColor()==Color_obj.EMPTY.getColor()){
                Sheep sheep = new Sheep(new Point(random_x,random_y),this);
                add_body(sheep);
            }
            else i--;
        }
        //tortoise
        amount = x_size*y_size/101;
        for(int i=0;i<amount;i++){
            random_x = ThreadLocalRandom.current().nextInt(1, x_size+1) ;
            random_y = ThreadLocalRandom.current().nextInt(1, y_size+1) ;
            if(boxes[random_y-1][random_x-1].getColor()==Color_obj.EMPTY.getColor()){
                Tortoise tortoise = new Tortoise(new Point(random_x,random_y),this);
                add_body(tortoise);
            }
            else i--;
        }
        //wolf
        amount = x_size*y_size/101;
        for(int i=0;i<amount;i++){
            random_x = ThreadLocalRandom.current().nextInt(1, x_size+1) ;
            random_y = ThreadLocalRandom.current().nextInt(1, y_size+1) ;
            if(boxes[random_y-1][random_x-1].getColor()==Color_obj.EMPTY.getColor()){
                Wolf wolf = new Wolf(new Point(random_x,random_y),this);
                add_body(wolf);
            }
            else i--;
        }
        //grass
        amount = x_size*y_size/101;
        for(int i=0;i<amount;i++){
            random_x = ThreadLocalRandom.current().nextInt(1, x_size+1) ;
            random_y = ThreadLocalRandom.current().nextInt(1, y_size+1) ;
            if(boxes[random_y-1][random_x-1].getColor()==Color_obj.EMPTY.getColor()){
                Grass grass = new Grass(new Point(random_x,random_y),this);
                add_body(grass);
            }
            else i--;
        }
        //belladonna
        amount = x_size*y_size/101;
        for(int i=0;i<amount;i++){
            random_x = ThreadLocalRandom.current().nextInt(1, x_size+1) ;
            random_y = ThreadLocalRandom.current().nextInt(1, y_size+1) ;
            if(boxes[random_y-1][random_x-1].getColor()==Color_obj.EMPTY.getColor()){
                Belladonna belladonna = new Belladonna(new Point(random_x,random_y),this);
                add_body(belladonna);
            }
            else i--;
        }
        //guarana
        amount = x_size*y_size/101;
        for(int i=0;i<amount;i++){
            random_x = ThreadLocalRandom.current().nextInt(1, x_size+1) ;
            random_y = ThreadLocalRandom.current().nextInt(1, y_size+1) ;
            if(boxes[random_y-1][random_x-1].getColor()==Color_obj.EMPTY.getColor()){
                Guarana guarana = new Guarana(new Point(random_x,random_y),this);
                add_body(guarana);
            }
            else i--;
        }
        //sosnowsky_hogweed
        amount = x_size*y_size/101;
        for(int i=0;i<amount;i++){
            random_x = ThreadLocalRandom.current().nextInt(1, x_size+1) ;
            random_y = ThreadLocalRandom.current().nextInt(1, y_size+1) ;
            if(boxes[random_y-1][random_x-1].getColor()==Color_obj.EMPTY.getColor()){
                SosnowskysHogweed sosnowsky_hogweed = new SosnowskysHogweed(new Point(random_x,random_y),this);
                add_body(sosnowsky_hogweed);
            }
            else i--;
        }
        //dandelion
        amount = x_size*y_size/101;
        for(int i=0;i<amount;i++){
            random_x = ThreadLocalRandom.current().nextInt(1, x_size+1) ;
            random_y = ThreadLocalRandom.current().nextInt(1, y_size+1) ;
            if(boxes[random_y-1][random_x-1].getColor()==Color_obj.EMPTY.getColor()){
                Dandelion dandelion = new Dandelion(new Point(random_x,random_y),this);
                add_body(dandelion);
            }
            else i--;
        }
    }

    public WorldPanel getPanel() {
        return panel;
    }

    public boolean isHuman_special_ability_is_active() {
        return human_special_ability_is_active;
    }

    public int getTurn() {
        return turn;
    }

    public void make_turn() {
        if (turn % 5 == 0) news_panel.clear();
        for (int i = 0; i < bodies.size(); i++) {
            Body body = bodies.get(i);
            if (body != null) {
                if (body.isAble_to_action()) {
                    if (!body.isAlive()) {
                        delete_body(body);
                    } else {
                        body.increment_age();
                        news_panel.add_title_name(body.getName() + "---> ");
                        body.move();
                    }
                } else {
                    body.setAble_to_action(true);
                }
            }
        }
        turn++;
        human_special_ability();
        news_panel.add_news(" ");
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

    public List<Body> getBodies() {
        return bodies;
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

    public void setOrder(int order) {
        this.order = order;
    }

    public boolean order_is_correct(){
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
    public void keyTyped(KeyEvent e) {
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
