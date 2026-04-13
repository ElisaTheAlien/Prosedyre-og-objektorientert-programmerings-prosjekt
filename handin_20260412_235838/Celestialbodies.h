#pragma once
#include "AnimationWindow.h"
#include <iostream>
#include "runStellar.h"

/*
Her lager vi en forelderklasse til de ulike objektene som kommer senere. Det skal da være 
stjerner og konstillasjoner. Denne klassen skal ikke være stor, da vi trenger bare en generell
tegne funksjon (drawBody)
*/
class celestialBody{
    public:
    std::string name;

    virtual void drawBody(TDT4102::AnimationWindow& win){

    }
    friend runStellar;
};