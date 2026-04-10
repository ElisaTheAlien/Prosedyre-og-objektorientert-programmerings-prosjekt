#include "GridConstillation.h"

void GridConstillation::GridMaking(TDT4102::AnimationWindow& window, TDT4102::Button& button1, TDT4102::Button& button2){

    button1.setVisible(false);
    button1.setCallback(std::bind(&GridConstillation::CallbackButton1, this));
    window.add(button1);

    button2.setVisible(false);
    button2.setCallback(std::bind(&GridConstillation::CallbackButton2, this));
    window.add(button2);
}

void GridConstillation::CallbackButton1(){
    show1 = true;
}

void GridConstillation::CallbackButton2(){
    show2 = true;
}