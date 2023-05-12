package World.body;

import GUI.Box;
import GUI.Color_obj;
import World.Point;
import World.World;

import java.io.Serializable;
import java.util.concurrent.ThreadLocalRandom;

public abstract class Animal extends Body implements Serializable {
    private static final long serialVersionUID = 738293893738294L;

    private Point last_position;
    private boolean random_location_born(Point new_point, Body other){
        int free_spaces = getWorld().free_spaces(this);
        int free_spaces_other = getWorld().free_spaces(other);
        if(free_spaces==0 && free_spaces_other==0){
            return false;
        }
        else if(free_spaces==0){
            new_point.setX(other.getPoint_location().getX());
            new_point.setY(other.getPoint_location().getY());
            while(true){
                random_location_empty(other, new_point);
                if(getWorld().getBoxes()[new_point.getY()-1][new_point.getX()-1].getColor().equals(Color_obj.EMPTY.getColor())){
                    return true;
                }
            }
        }
        else if(free_spaces_other==0){
            new_point.setX(getPoint_location().getX());
            new_point.setY(getPoint_location().getY());
            while(true){
                random_location_empty(this, new_point);
                if(getWorld().getBoxes()[new_point.getY()-1][new_point.getX()-1].getColor().equals(Color_obj.EMPTY.getColor())){
                    return true;
                }
            }
        }
        else{
            int randomNumber = ThreadLocalRandom.current().nextInt(1, 101) % 2;
            if(randomNumber==0){
                new_point.setX(getPoint_location().getX());
                new_point.setY(getPoint_location().getY());
                while(true){
                    random_location_empty(this, new_point);
                    if(getWorld().getBoxes()[new_point.getY()-1][new_point.getX()-1].getColor().equals(Color_obj.EMPTY.getColor())){
                        return true;
                    }
                }
            }
            else{
                new_point.setX(other.getPoint_location().getX());
                new_point.setY(other.getPoint_location().getY());
                while(true){
                    random_location_empty(other, new_point);
                    if(getWorld().getBoxes()[new_point.getY()-1][new_point.getX()-1].getColor().equals(Color_obj.EMPTY.getColor())){
                        return true;
                    }
                }
            }
        }
    }
    private void born(Body attacker){
        if(getAge()>3 && attacker.getAge()>3){
            Point new_point = new Point(getPoint_location().getX(), getPoint_location().getY());
            if(random_location_born(new_point, attacker)){
                new_body(new_point);
                getWorld().getNews_panel().add_news("Born new animal ("+new_point.getX()+","+new_point.getY()+")");
            }
            else{
                getWorld().getNews_panel().add_news("No place to born new animal");
            }
        }
        else{
            getWorld().getNews_panel().add_news("Animals are to young to born new animal");
        }
    }
    private void back_move(){
        int x = getPoint_location().getX();
        int y = getPoint_location().getY();
        setPoint_location(getLast_position());
        setLast_position(new Point(x,y));
        getWorld().getBoxes()[getPoint_location().getY()-1][getPoint_location().getX()-1].setColor(getColor());
    }
    protected boolean changed_position(){
        return !getLast_position().equals(getPoint_location());
    }

    public Animal() {
    }

    public Animal(Point point_location, World world) {
        super(point_location, world);
        setLast_position(point_location);
    }

    @Override
    public void move() {
        World world = getWorld();
        action();
        if(changed_position()){
            // jesli to pole jest puste
            if(!world.getBoxes()[getPoint_location().getY()-1][getPoint_location().getX()-1].getColor().equals(Color_obj.EMPTY.color)){
                //kolizja
                this.back_move();
                world.getBoxes()[getPoint_location().getY()-1][getPoint_location().getX()-1].setColor(Color_obj.EMPTY);
                Body tmp = world.get_body(getLast_position());
                if(tmp!=null){
                    this.back_move();
                    tmp.collision(this);
                }
            }
            else{
                world.getNews_panel().add_news("Move to ("+getPoint_location().getX()+","+getPoint_location().getY()+")");
                world.getBoxes()[getPoint_location().getY()-1][getPoint_location().getX()-1].setColor(getColor());
                world.getBoxes()[getLast_position().getY()-1][getLast_position().getX()-1].setColor(Color_obj.EMPTY);
            }
        }
        else{
            world.getNews_panel().add_news("Remains in place");
        }
    }

    @Override
    protected void collision(Body attacker) {
        if(attacker instanceof Animal){
            Animal other_animal = (Animal) attacker;
            if(other_animal.getColor().equals(getColor())){
                other_animal.back_move();;
                born(other_animal);
            }
            else{
                if(repel_attack(other_animal)){
                    getWorld().getNews_panel().add_news("Repel attack");
                }
                else{
                    if(getPower() > other_animal.getPower()){
                        getWorld().getNews_panel().add_news(this.getName()+" are killing "+other_animal.getName());
                        getWorld().delete_body2(other_animal);
                        getWorld().getBoxes()[getPoint_location().getY()-1][getPoint_location().getX()-1].setColor(this.getColor());
                    }
                    else{
                        getWorld().getNews_panel().add_news(other_animal.getName()+" are killing "+this.getName());
                        getWorld().delete_body(this);
                        getWorld().getBoxes()[other_animal.getPoint_location().getY()-1][other_animal.getPoint_location().getX()-1].setColor(other_animal.getColor());
                    }
                }
            }
        }
        else{
            if(getPower() > attacker.getPower()){
                getWorld().getNews_panel().add_news(attacker.getName()+" are eating "+this.getName()+" and die");
                getWorld().delete_body2(attacker);
                getWorld().getBoxes()[attacker.getPoint_location().getY()-1][attacker.getPoint_location().getX()-1].setColor(this.getColor());
            }
            else{
                getWorld().getNews_panel().add_news(this.getName()+" are eating "+attacker.getName());
                getWorld().delete_body(this);
                getWorld().getBoxes()[getPoint_location().getY()-1][getPoint_location().getX()-1].setColor(attacker.getColor());
            }
        }
    }

    @Override
    protected void action() {
        int x = getPoint_location().getX();
        int y = getPoint_location().getY();
        Point point = new Point(x ,y);
        random_location(point);
        setLast_position(getPoint_location());
        setPoint_location(point);
    }

    protected abstract boolean repel_attack(Body attacker);

    public void setLast_position(Point last_position) {
        this.last_position = last_position;
    }

    public Point getLast_position() {
        return last_position;
    }
}
