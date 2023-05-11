package World.body.plant;

import GUI.Color_obj;
import World.Point;
import World.World;
import World.body.Plant;

public class Belladonna extends Plant {
    public Belladonna(Point point_location, World world) {
        super(point_location, world);
        setName("Belladonna");
        setPower(999);
        setColor(Color_obj.BELLADONNA);
    }

    @Override
    public int get_stronger() {
        return 0;
    }
}
