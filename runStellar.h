#pragma once
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include <iostream>
#include <string>
#include <vector>
class runStellar{

    private:
        bool quit = false;
        bool button1Pressed = false;
        bool button2Pressed = false;

    public:
        void callback();
        void run(TDT4102::AnimationWindow& window);
};