#pragma once
#include "AnimationWindow.h"
#include <iostream>
#include "runStellar.h"

class celestialBody{
    public:
    std::string name;
    int index;

    virtual void drawBody(TDT4102::AnimationWindow& win){

    }
    friend runStellar;
};