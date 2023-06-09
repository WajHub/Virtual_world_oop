package World.body.animal;

import GUI.Color_obj;
import World.Point;
import World.World;
import World.body.Animal;
import World.body.Body;

import java.io.Serializable;

public class Wolf extends Animal implements Serializable {
    private static final long serialVersionUID = 42L;
    private static int amount=0;
    public Wolf(Point point_location, World world) {
        super(point_location, world);
        amount ++;
        setName("Wolf");
        setColor(Color_obj.WOLF);
        setPower(9);
        setInitiative(5);
    }
    public static int getAmount_wolf() {
        return amount;
    }

    @Override
    protected boolean repel_attack(Body attacker) {
        return false;
    }
}
