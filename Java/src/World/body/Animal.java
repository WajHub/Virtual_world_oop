package World.body;

import GUI.Color_obj;
import World.Point;
import World.World;

public abstract class Animal extends Body {
    private Point last_position;
    private boolean random_location_born(Point new_point, Body other){
        return true;
    }
    private void born(Body attakcer){
        if(getAge()>3 && attakcer.getAge()>3){
            Point new_point = new Point(getPoint_location().getX(), getPoint_location().getY());
            if(random_location_born(new_point, attakcer)){
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
        getWorld().getBoxes()[getPoint_location().getX()-1][getPoint_location().getY()-1].setColor(getColor().getColor());

    }
    protected boolean changed_position(){
        return !getLast_position().equals(getPoint_location());
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
            if(world.getBoxes()[getPoint_location().getX()-1][getPoint_location().getY()-1].getColor().equals(Color_obj.EMPTY)){
                //kolizja
                this.back_move();
                world.getBoxes()[getPoint_location().getX()-1][getPoint_location().getY()-1].setColor(Color_obj.EMPTY.color);
                Body tmp = world.get_body(getLast_position());
                this.back_move();
                tmp.collision(this);
            }
            else{
                world.getNews_panel().add_news("Move to ("+getPoint_location().getX()+","+getPoint_location().getY()+")");
                world.getBoxes()[getPoint_location().getX()-1][getPoint_location().getY()-1].setColor(getColor().getColor());
                world.getBoxes()[getLast_position().getX()-1][getLast_position().getY()-1].setColor(Color_obj.EMPTY.color);
            }
        }
        world.getNews_panel().add_news("Remains in place");
    }

    @Override
    protected void collision(Body other) {
        if(other instanceof Animal){
            Animal other_animal = (Animal) other;
            if(other_animal.getColor().equals(getColor())){
                born(other_animal);
            }
            else{
                if(repel_attack(other_animal)){
                    getWorld().getNews_panel().add_news("Repel attack");
                }
                else{
                    getWorld().getNews_panel().add_news("Attack");
                    if(getPower() > other_animal.getPower()){
                        getWorld().getNews_panel().add_news("Killed");
                        getWorld().getBoxes()[other_animal.getPoint_location().getX()-1][other_animal.getPoint_location().getY()-1].setColor(Color_obj.EMPTY.color);
                        getWorld().delete_body2(other_animal);
                    }
                    else{
                        getWorld().getNews_panel().add_news("Killed");
                        getWorld().getBoxes()[getPoint_location().getX()-1][getPoint_location().getY()-1].setColor(Color_obj.EMPTY.color);
                        getWorld().delete_body(this);
                    }
                }
            }
        }
        else{
            getWorld().getNews_panel().add_news("Attack");
            if(getPower() > other.getPower()){
                getWorld().getNews_panel().add_news("Killed");
                getWorld().getBoxes()[other.getPoint_location().getX()-1][other.getPoint_location().getY()-1].setColor(Color_obj.EMPTY.color);
                getWorld().delete_body2(other);
            }
            else{
                getWorld().getNews_panel().add_news("Killed");
                getWorld().getBoxes()[getPoint_location().getX()-1][getPoint_location().getY()-1].setColor(Color_obj.EMPTY.color);
                getWorld().delete_body(this);
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
