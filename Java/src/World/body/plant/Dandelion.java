package World.body.plant;

import GUI.Color_obj;
import World.Point;
import World.World;
import World.body.Plant;

import java.util.concurrent.ThreadLocalRandom;

public class Dandelion extends Plant {
    public Dandelion(Point point_location, World world) {
        super(point_location, world);
        setName("Dandelion");
        setPower(0);
        setColor(Color_obj.DANDELION);
    }

    @Override
    protected void action() {
        int randomNumber;
        for(int i=3;i>0;i--){
            randomNumber = ThreadLocalRandom.current().nextInt(0, 201);
            if(randomNumber%100<8){
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
    }

    @Override
    public int get_stronger() {
        return 0;
    }
}
