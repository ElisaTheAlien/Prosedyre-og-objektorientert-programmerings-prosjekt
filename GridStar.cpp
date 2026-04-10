#include "GridStar.h"

void GridStar::GridMaking(TDT4102::AnimationWindow& window){

    double winWidth = window.width();
    double winHeight = window.height();

    const TDT4102::Point buttonPosition1 {0, 0};
    const TDT4102::Point buttonPosition2 {winWidth/2, 0};
    const unsigned int buttonWidth = winWidth/2;;
    const unsigned int buttonHeight = winHeight;
    const std::string buttonLabel = "";

    TDT4102::Button button1 {buttonPosition1, buttonWidth, buttonHeight, buttonLabel};
    button1.isVisible = false;
    button1.setCallback(std::bind(&GridStar::CallbackButton1, this));
    window.add(button1);

    TDT4102::Button button2 {buttonPosition2, buttonWidth, buttonHeight, buttonLabel};
    button2.isVisible = false;
    button2.setCallback(std::bind(&GridStar::CallbackButton2, this));
    window.add(button2);
}

void GridStar::CallbackButton1(){
    show1 = true;
}

void GridStar::CallbackButton2(){
    show2 = true;
}