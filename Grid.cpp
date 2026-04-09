#include "Grid.h"

void Grid::GridMaking(TDT4102::AnimationWindow& window){

    double winWidth = window.width();
    double winHeight = window.height();

    const TDT4102::Point buttonPosition1 {0, 0};
    const TDT4102::Point buttonPosition2 {winWidth/2, 0};
    const unsigned int buttonWidth = winWidth/2;;
    const unsigned int buttonHeight = winHeight;
    const std::string buttonLabel = "";

    TDT4102::Button button1 {buttonPosition1, buttonWidth, buttonHeight, buttonLabel};


    TDT4102::Button button2 {buttonPosition2, buttonWidth, buttonHeight, buttonLabel};

    window.wait_for_close();
}