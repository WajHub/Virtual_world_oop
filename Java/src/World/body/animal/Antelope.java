package World.body.animal;

import GUI.Color_obj;
import World.Point;
import World.World;
import World.body.Animal;
import World.body.Body;

import java.util.concurrent.ThreadLocalRandom;

public class Antelope extends Animal {

    public Antelope(Point point_location, World world) {
        super(point_location, world);
        setName("Antelope");
        setColor(Color_obj.ANTELOPE);
        setInitiative(4);
        setPower(4);
    }
    @Override
    protected void action(){
        Point point = new Point(getPoint_location().getX(), getPoint_location().getY());
        Point new_point = new Point(getPoint_location().getX(), getPoint_location().getY());
        int range = 2;
        while(range > 0){
            random_location(new_point);
            setPoint_location(new_point);
            if(point.getX() == new_point.getX() && point.getY() == new_point.getY()){
                range=2;
            }
            else range--;
        }
        setLast_position(point);
        setPoint_location(new_point);
    }

    @Override
    protected void collision(Body attacker) {
        int randomNumber = ThreadLocalRandom.current().nextInt(1, 101) % 2;
        if(randomNumber==0 || getWorld().free_spaces(this)==0){
            collision(attacker);
        }
        else{
            Point new_point = new Point(getPoint_location().getX(), getPoint_location().getY());
            random_location_empty(this, new_point);
            getWorld().getNews_panel().add_news("Move to ("+getPoint_location().getX()+", "+getPoint_location().getY()+")");
            getWorld().getBoxes()[getPoint_location().getY()-1][getPoint_location().getX()-1].setColor(attacker.getColor());
            setLast_position(getPoint_location());
            setPoint_location(new_point);
            getWorld().getNews_panel().add_news("Run away to ("+getPoint_location().getX()+", "+getPoint_location().getY()+")");
            getWorld().getBoxes()[getPoint_location().getY()-1][getPoint_location().getX()-1].setColor(getColor());
        }
    }

    @Override
    protected boolean repel_attack(Body attacker) {
        return false;
    }
}
