package World.body.plant;

import GUI.Color_obj;
import World.Point;
import World.World;
import World.body.Plant;

import java.io.Serializable;

public class Guarana extends Plant implements Serializable {
    private static final long serialVersionUID = -987654321L;
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
