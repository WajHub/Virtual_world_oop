package World.body.plant;

import GUI.Color_obj;
import World.Point;
import World.World;
import World.body.Plant;

public class Grass extends Plant {
    public Grass(Point point_location, World world) {
        super(point_location, world);
        setName("Grass");
        setPower(0);
        setColor(Color_obj.GRASS);
    }

    @Override
    public int get_stronger() {
        return 0;
    }
}
