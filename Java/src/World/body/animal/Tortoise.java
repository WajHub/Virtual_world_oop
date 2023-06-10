package World.body.animal;

import GUI.Color_obj;
import World.Point;
import World.World;
import World.body.Animal;
import World.body.Body;

import java.io.Serializable;
import java.util.concurrent.ThreadLocalRandom;

public class Tortoise extends Animal implements Serializable {
    private static final long serialVersionUID = 8675309L;
    public Tortoise(Point point_location, World world) {
        super(point_location, world);
        setName("Tortoise");
        setColor(Color_obj.TORTOISE);
        setInitiative(1);
        setPower(2);
    }

    @Override
    protected void action() {
        Point point = new Point(getPoint_location().getX(), getPoint_location().getY());
        Point new_point = new Point(getPoint_location().getX(), getPoint_location().getY());
        int randomNumber = ThreadLocalRandom.current().nextInt(1, 101) % 4;
        if(randomNumber==0){
            random_location(new_point);
        }
        setLast_position(point);
        setPoint_location(new_point);
    }

    @Override
    protected boolean repel_attack(Body attacker) {

        return attacker.getPower() < 5;
    }
}
