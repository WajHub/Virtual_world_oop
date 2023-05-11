package World.body;

import GUI.Color_obj;
import World.World;
import World.Point;
import World.body.animal.*;
import World.body.plant.*;

import java.util.concurrent.ThreadLocalRandom;

public abstract class  Body {
    private String name;
    private Color_obj color;
    private int power;
    private int initiative;
    private int age = 0;
    //Value starts form 1
    private Point point_location;
    boolean able_to_action = false;
    boolean alive = true;
    private World world;

    protected void random_location_empty(Body body, Point new_point){
        int x = body.getPoint_location().getX();
        int y = body.getPoint_location().getY();
        int randomNumber;
        boolean tmp = true;
        while(tmp){
            randomNumber = ThreadLocalRandom.current().nextInt(1, 101) % 4 + 1;
            switch (randomNumber){
                case 1:
                    if(x<world.getX_size() && world.getBoxes()[y-1][x].getColor().equals(Color_obj.EMPTY.getColor())){
                        new_point.setX(new_point.getX()+1);
                        tmp=false;
                    }
                    break;
                case 2:
                    if(x > 1 && world.getBoxes()[y-1][x-2].getColor().equals(Color_obj.EMPTY.getColor())){
                        new_point.setX(new_point.getX()-1);
                        tmp = false;
                    }
                    break;
                case 3:
                    if(y<world.getY_size() && world.getBoxes()[y][x-1].getColor().equals(Color_obj.EMPTY.getColor())){
                        new_point.setY(new_point.getY()+1);
                        tmp=false;
                    }
                    break;
                case 4:
                    if(y > 1 && world.getBoxes()[y-2][x-1].getColor().equals(Color_obj.EMPTY.getColor())){
                        new_point.setY(new_point.getY()-1);
                        tmp = false;
                    }
                    break;
            }
        }
    }
    protected  void random_location(Point new_point){
        int x = getPoint_location().getX();
        int y = getPoint_location().getY();
        new_point.setX(x);
        new_point.setY(y);
        int randomNumber;
        boolean tmp = true;
        while(tmp){
            randomNumber = ThreadLocalRandom.current().nextInt(1, 101) % 4 + 1;
            switch (randomNumber){
                case 1:
                    if(x<world.getX_size()){
                        new_point.setX(new_point.getX()+1);
                        tmp=false;
                    }
                    break;
                case 2:
                    if(x > 1){
                        new_point.setX(new_point.getX()-1);
                        tmp = false;
                    }
                    break;
                case 3:
                    if(y<world.getY_size() ){
                        new_point.setY(new_point.getY()+1);
                        tmp=false;
                    }
                    break;
                case 4:
                    if(y > 1){
                        new_point.setY(new_point.getY()-1);
                        tmp = false;
                    }
                    break;
            }
        }
    }

    public void new_body(Point point){
        switch (color){
            case WOLF:
                getWorld().add_body(new Wolf(point, getWorld()));
                break;
            case SHEEP:
                getWorld().add_body(new Sheep(point, getWorld()));
                break;
            case ANTELOPE:
                getWorld().add_body(new Antelope(point, getWorld()));
                break;
            case FOX:
                getWorld().add_body(new Fox(point, getWorld()));
                break;
            case TORTOISE:
                getWorld().add_body(new Tortoise(point, getWorld()));
                break;
            case GRASS:
                getWorld().add_body(new Grass(point, getWorld()));
                break;
            case DANDELION:
                getWorld().add_body(new Dandelion(point, getWorld()));
                break;
            case GUARANA:
                getWorld().add_body(new Guarana(point, getWorld()));
                break;
            case BELLADONNA:
                getWorld().add_body(new Belladonna(point, getWorld()));
                break;
            case SOSNOWSKYSHOGWEED:
                getWorld().add_body(new SosnowskysHogweed(point, getWorld()));
                break;
        }
    }

    public void increment_age(){
        age++;
    }

    public Body(Point point_location, World world) {
        this.point_location = point_location;
        this.world = world;
    }

    public abstract void move();
    protected abstract void collision(Body other);
    protected abstract void action();
    //Getters and setters

    public void setName(String name) {
        this.name = name;
    }

    public void setColor(Color_obj color) {
        this.color = color;
    }

    public void setPower(int power) {
        this.power = power;
    }

    public void setInitiative(int initiative) {
        this.initiative = initiative;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setPoint_location(Point point_location) {
        this.point_location = point_location;
    }

    public void setAble_to_action(boolean able_to_action) {
        this.able_to_action = able_to_action;
    }

    public void setAlive(boolean alive) {
        this.alive = alive;
    }

    public void setWorld(World world) {
        this.world = world;
    }

    public String getName() {
        return name;
    }

    public Color_obj getColor() {
        return color;
    }

    public int getPower() {
        return power;
    }

    public int getInitiative() {
        return initiative;
    }

    public int getAge() {
        return age;
    }

    public Point getPoint_location() {
        return point_location;
    }

    public boolean isAble_to_action() {
        return able_to_action;
    }

    public boolean isAlive() {
        return alive;
    }

    public World getWorld() {
        return world;
    }
}
