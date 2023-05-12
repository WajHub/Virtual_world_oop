package World.body.animal;

import GUI.Color_obj;
import World.Point;
import World.World;
import World.body.Animal;
import World.body.Body;

import java.awt.event.KeyEvent;
import java.io.Serializable;

public class Human extends Animal implements Serializable {
    private static final long serialVersionUID = -1534372028747757553L;

    private int additional_power = 0;
    int age_when_used_special_skill = -10;

    public Human() {
    }

    public Human(Point point_location, World world) {
        super(point_location, world);
        setName("Human");
        setColor(Color_obj.HUMAN);
        setInitiative(4);
        setPower(5);
    }

    @Override
    protected boolean repel_attack(Body attacker) {
        return false;
    }

    @Override
    protected void action() {
        switch(getWorld().getOrder()){
            case KeyEvent.VK_UP:
                setLast_position(getPoint_location());
                setPoint_location(new Point(getPoint_location().getX(), getPoint_location().getY()-1));
                break;
            case KeyEvent.VK_DOWN:
                setLast_position(getPoint_location());
                setPoint_location(new Point(getPoint_location().getX(), getPoint_location().getY()+1));
                break;
            case KeyEvent.VK_LEFT:
                setLast_position(getPoint_location());
                setPoint_location(new Point(getPoint_location().getX()-1, getPoint_location().getY()));
                break;
            case KeyEvent.VK_RIGHT:
                setLast_position(getPoint_location());
                setPoint_location(new Point(getPoint_location().getX()+1, getPoint_location().getY()));
                break;
        }

    }

    public boolean can_use_ability() {
        if(age_when_used_special_skill+10<=getAge()){
            return true;
        }
        return false;
    }

    public void setAdditionalPower(int i) {
        additional_power=i;
    }

    public int getAdditionalPower() {
        return additional_power;
    }

    public void setAgeWhenUsedSpecialSkill(int age) {
        age_when_used_special_skill=age;
    }
}
