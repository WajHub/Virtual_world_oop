//
// Created by hubert on 13.04.2023.
//
#pragma once
#ifndef CPP_ANIMAL_H
#define CPP_ANIMAL_H

#include "Body.h"
#include "World.h"

class Animal: public Body {
public:
    void action() override;
};


#endif //CPP_ANIMAL_H
