package World.body.plant;

import GUI.Color_obj;
import World.Point;
import World.World;
import World.body.Animal;
import World.body.Body;
import World.body.Plant;

import java.util.concurrent.ThreadLocalRandom;

public class SosnowskysHogweed extends Plant {
    public SosnowskysHogweed(Point point_location, World world) {
        super(point_location, world);
        setName("SosnowskysHogweed");
        setPower(999);
        setColor(Color_obj.SOSNOWSKYSHOGWEED);
    }
    public void kill_around(){
        Point point = new Point(getPoint_location().getX(), getPoint_location().getY());
        int directions_y[] = {-1, 0, 1, 0,1,-1,1,-1};
        int directions_x[] = {0, 1, 0, -1,1,-1,-1,1};
        for(int i=0; i<8;i++){
            if(point.getX()+directions_x[i]>=1 && point.getX()+directions_x[i]<=getWorld().getX_size()
                    && point.getY()+directions_y[i]>=1 && point.getY()+directions_y[i]<=getWorld().getY_size()){
                Body body = getWorld().get_body(new Point(point.getX()+directions_x[i], point.getY()+directions_y[i]));
                if(body instanceof Animal){
                    getWorld().delete_body2(getWorld().get_body(new Point(point.getX()+directions_x[i], point.getY()+directions_y[i])));
                    getWorld().getBoxes()[point.getY()+directions_y[i]-1][point.getX()+directions_x[i]-1].setColor(Color_obj.EMPTY);
                    getWorld().getNews_panel().add_news(getName() + " has killed " + body.getName() + " on (" + body.getPoint_location().getX() + ", " + body.getPoint_location().getY()+')');
                }
            }
        }
    }
    @Override
    protected void collision(Body attacker) {
        getWorld().getNews_panel().add_news(attacker.getName() + " has eaten " + getName() + "and dies on (" + getPoint_location().getX() + ", " + getPoint_location().getY()+')');
        getWorld().getBoxes()[attacker.getPoint_location().getY()-1][attacker.getPoint_location().getX()-1].setColor(Color_obj.EMPTY);
        getWorld().delete_body2(attacker);
        getWorld().delete_body(this);
    }

    @Override
    protected void action() {
        int randomNumber = ThreadLocalRandom.current().nextInt(1, 101);
        if(randomNumber<2){
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
        kill_around();
    }

    @Override
    public int get_stronger() {
        return 0;
    }
}
