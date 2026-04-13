#include "GridStar.h"

void GridStar::GridMaking(TDT4102::AnimationWindow& window, TDT4102::Button& button1, TDT4102::Button& button2){

    button1.setVisible(false);
    button1.setCallback(std::bind(&GridStar::CallbackButton1, this));
    window.add(button1);

    button2.setVisible(false);
    button2.setCallback(std::bind(&GridStar::CallbackButton2, this));
    window.add(button2);
}

void GridStar::CallbackButton1(){
    show1 = true;
}

void GridStar::CallbackButton2(){
    show2 = true;
}