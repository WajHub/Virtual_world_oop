//
// Created by hubert on 18.04.2023.
//

#ifndef CPP_PINE_HOGWEED_H
#define CPP_PINE_HOGWEED_H


#include "../Plant.h"

class Pine_hogweed:public Plant {
private:
    static int amount;
protected:
    void action()override;
public:
    Pine_hogweed(World &world, int xLocation, int yLocation);
    static int getAmount_Pine_hogweed();
    void collision(Body *attacker) override;
    int get_stronger() override;
    void kill_around();
    ~Pine_hogweed() override;
};


#endif //CPP_PINE_HOGWEED_H
