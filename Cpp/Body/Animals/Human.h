//
// Created by hubert on 19.04.2023.
//

#ifndef CPP_HUMAN_H
#define CPP_HUMAN_H


#include "../Animal.h"


class Human: public Animal {
private:
    int additional_power=0;
    int age_when_used_special_skill=-10;
    bool repel_attack(Body &attacker) override;
protected:
    void action() override;
public:
    int getAdditionalPower() const;
    void setAdditionalPower(int additionalPower);
    void setAgeWhenUsedSpecialSkill(int ageWhenUsedSpecialSkill);
    int getAgeWhenUsedSpecialSkill() const;
    bool can_use_special_skill();
    Human(World &world, int xLocation, int yLocation);
    ~Human();
};


#endif //CPP_HUMAN_H
