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
        bool backConstillation = false;
        bool backStar = false;
        bool mainMenu = false;

    public:
        void callbackQuit();
        void callbackConstillation();
        void callbackStar();
        void callbackMainMenu();
        void run(TDT4102::AnimationWindow& window);
};