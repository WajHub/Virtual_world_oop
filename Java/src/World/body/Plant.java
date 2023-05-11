package World.body;

import GUI.Color_obj;
import World.Point;
import World.World;

import java.util.concurrent.ThreadLocalRandom;

public abstract class Plant extends Body{

    public Plant(Point point_location, World world) {
        super(point_location, world);
        setInitiative(0);
    }

    @Override
    public void move() {
        action();
    }
    public abstract int get_stronger();
    @Override
    protected void action() {
        int randomNumber = ThreadLocalRandom.current().nextInt(1, 101);
        if(randomNumber<7){
            int free_spaces = getWorld().free_spaces(this);
            if(free_spaces>0){
                Point new_point = new Point(getPoint_location().getX(), getPoint_location().getY());
                random_location_empty(this, new_point);
                new_body(new_point);
                getWorld().getNews_panel().add_news(getName() + " has grown on (" + new_point.getX() + ", " + new_point.getY()+')');
            }
            else{
                getWorld().getNews_panel().add_news("Nothing happened");
            }
        }
        else{
            getWorld().getNews_panel().add_news("Nothing happened");
        }
    }

    @Override
    protected void collision(Body attacker) {
        if(this.getPower()>attacker.getPower()){
            getWorld().getNews_panel().add_news(attacker.getName() + " has eaten " + getName() + " and dies on (" + attacker.getPoint_location().getX() + ", " + attacker.getPoint_location().getY()+')');
            getWorld().getBoxes()[attacker.getPoint_location().getY()-1][attacker.getPoint_location().getX()-1].setColor(Color_obj.EMPTY);
            getWorld().delete_body2(attacker);
            getWorld().delete_body(this);
        }
        else{
            getWorld().getNews_panel().add_news(attacker.getName() + " has eaten " + getName() + " on (" + getPoint_location().getX() + ", " + getPoint_location().getY()+')');
            if(get_stronger()>0){
                attacker.setPower(attacker.getPower()+get_stronger());
                getWorld().getNews_panel().add_news(attacker.getName() + " has grown stronger and now has " + attacker.getPower() + " power");
            }
            getWorld().delete_body(this);
            getWorld().getBoxes()[getPoint_location().getY()-1][getPoint_location().getX()-1].setColor(attacker.getColor());
        }
    }


}
