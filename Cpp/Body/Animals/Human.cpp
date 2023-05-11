
//
// Created by hubert on 19.04.2023.
//
#include "Human.h"

bool Human::repel_attack(Body &attacker) {
    return false;
}

Human::Human(World &world, int xLocation, int yLocation) : Animal(world, xLocation, yLocation) {
    setName("Human");
    setMark('H');
    setInitiative(4);
    setPower(5);
    world.setHumanIsAlive(true);
}

Human::~Human() {
    getWorld().setHumanIsAlive(false);
}

void Human::action() {
    char order = getWorld().getOrder();
    switch (order) {
        case LEFT_ARROW:
            setLastPositionX(getXLocation());
            setLastPositionY(getYLocation());
            setXLocation(getXLocation()-1);
            break;
        case RIGHT_ARROW:
            setLastPositionX(getXLocation());
            setLastPositionY(getYLocation());

            setXLocation(getXLocation()+1);
            break;
        case UP_ARROW:
            setLastPositionX(getXLocation());
            setLastPositionY(getYLocation());
            setYLocation(getYLocation()-1);
            break;
        case DOWN_ARROW:
            setLastPositionX(getXLocation());
            setLastPositionY(getYLocation());
            setYLocation(getYLocation()+1);
            break;
    }
}

int Human::getAdditionalPower() const {
    return additional_power;
}

void Human::setAdditionalPower(int additionalPower) {
    additional_power = additionalPower;
}

int Human::getAgeWhenUsedSpecialSkill() const {
    return age_when_used_special_skill;
}

void Human::setAgeWhenUsedSpecialSkill(int ageWhenUsedSpecialSkill) {
    age_when_used_special_skill = ageWhenUsedSpecialSkill;
}

bool Human::can_use_special_skill() {
    if(age_when_used_special_skill+10<=getAge())return true;
    return false;
}

//void Human::collision(Body *attacker) {
//    Animal::collision(attacker);
//}
