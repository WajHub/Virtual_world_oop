package World.body.animal;

import GUI.Color_obj;
import World.Point;
import World.World;
import World.body.Animal;
import World.body.Body;

import java.io.Serializable;

public class Fox extends Animal implements Serializable {
    private static final long serialVersionUID = 123456789L;
    public Fox(Point point_location, World world) {
        super(point_location, world);
        setName("Fox");
        setInitiative(7);
        setPower(3);
        setColor(Color_obj.FOX);
    }

    @Override
    protected boolean repel_attack(Body attacker) {
        return false;
    }

    @Override
    protected void action() {
        Point point = new Point(getPoint_location().getX(), getPoint_location().getY());
        Point new_point = new Point(getPoint_location().getX(), getPoint_location().getY());
        boolean tmp = true;
        int attempt=0;
        while(tmp){
            random_location(new_point);
            tmp=false;
            Body body = getWorld().get_body(new_point);
            if(body instanceof Animal){
                if(body.getPower()>getPower()){
                    new_point.setX(point.getX());
                    new_point.setY(point.getY());
                    tmp = true;
                    attempt++;
                    if(attempt>12){
                        tmp = false;
                    }
                }
            }
        }
        setLast_position(point);
        setPoint_location(new_point);
    }
}
