#pragma once
#include "AnimationWindow.h"
#include <string>

class celestialBody{
    public:
    std::string name;

    virtual void drawBody(TDT4102::AnimationWindow& win){

    }
};