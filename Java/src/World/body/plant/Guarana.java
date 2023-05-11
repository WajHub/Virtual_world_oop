package World.body.plant;

import GUI.Color_obj;
import World.Point;
import World.World;
import World.body.Plant;

public class Guarana extends Plant {
    public Guarana(Point point_location, World world) {
        super(point_location, world);
        setName("Guarana");
        setPower(0);
        setColor(Color_obj.GUARANA);
    }

    @Override
    public int get_stronger() {
        return 3;
    }
}
