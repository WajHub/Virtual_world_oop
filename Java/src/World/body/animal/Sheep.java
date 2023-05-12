package World.body.animal;

import GUI.Color_obj;
import World.Point;
import World.World;
import World.body.Animal;
import World.body.Body;

import java.io.Serializable;

public class Sheep extends Animal implements Serializable {

    public Sheep(Point point_location, World world) {
        super(point_location, world);
        setName("Sheep");
        setColor(Color_obj.SHEEP);
        setInitiative(4);
        setPower(4);
    }

    @Override
    protected boolean repel_attack(Body attacker) {
        return false;
    }
}
