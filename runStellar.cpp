#include "runStellar.h"
#include "startScreen.h"
#include "star.h"
#include "constillation.h"
#include "GridConstillation.h"
#include "GridStar.h"

void runStellar::callbackQuit(){
    quit = true;
}

void runStellar::callbackConstillation(){
    backConstillation = true;
}
void runStellar::callbackStar(){
    backStar = true;
}
void runStellar::callbackMainMenu(){
    mainMenu = true;
}

void runStellar::run(TDT4102::AnimationWindow& window){
    double winWidth = window.width();
    double winHeight = window.height();

    const TDT4102::Point buttonPosition1 {0, 0};
    const TDT4102::Point buttonPosition2 {winWidth/2, 0};
    const unsigned int buttonWidth = winWidth/2;;
    const unsigned int buttonHeight = winHeight;
    const std::string buttonLabel = "";

    TDT4102::Button OrionButton {buttonPosition1, buttonWidth, buttonHeight, buttonLabel};
    TDT4102::Button BigDipperButton {buttonPosition2, buttonWidth, buttonHeight, buttonLabel};
    TDT4102::Button BetegeuseButton {buttonPosition1, buttonWidth, buttonHeight, buttonLabel};
    TDT4102::Button RigelButton {buttonPosition2, buttonWidth, buttonHeight, buttonLabel};
    
    startScreen start("Startscreen/welcome.txt", "Startscreen/earth.png", "Drawing of rocket/Rocket from earth.png");
    GridConstillation constGrid;
    GridStar orionGrid;
    GridStar bigDipperGrid;
    Constillation Orion("Bodies/Orion/orion.txt","Bodies/Orion/orion.png"); 
    Constillation bigDipper("Bodies/Bigdipper/bigdipper.txt","Bodies/Bigdipper/bigdipper.png");
    Star Betelgeuse("Bodies/Betelgeuse.txt", "Bodies/Orion/Betelgeuse.png");
    constGrid.GridMaking(window, OrionButton, BigDipperButton);
    orionGrid.GridMaking(window, BetegeuseButton, RigelButton);
    bigDipperGrid.GridMaking(window);
    start.startAnimation(window);

    while(!start.begin){
        start.draw(window);
    }
    while(start.begin) {

        constGrid.

        window.next_frame();
    }
}