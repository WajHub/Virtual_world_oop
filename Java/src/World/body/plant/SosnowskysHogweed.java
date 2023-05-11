package World.body.plant;

import World.Point;
import World.World;
import World.body.Body;
import World.body.Plant;

public class SosnowskysHogweed extends Plant {
    public SosnowskysHogweed(Point point_location, World world) {
        super(point_location, world);
        setName("SosnowskysHogweed");
        setPower(999);
    }
    public void kill_around(){

    }
    @Override
    protected void collision(Body attacker) {
        super.collision(attacker);
    }

    @Override
    protected void action() {
        super.action();
    }

    @Override
    public int get_stronger() {
        return 0;
    }
}
