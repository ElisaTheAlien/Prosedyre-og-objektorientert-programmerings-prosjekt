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
    startScreen start("Startscreen/welcome.txt", "Startscreen/earth.png");
    GridConstillation constGrid;
    GridStar orionGrid;
    GridStar bigDipperGrid;
    Constillation Orion("Bodies/Orion/orion.txt","Bodies/Orion/orion.png"); 
    Constillation bigDipper("Bodies/Bigdipper/bigdipper.txt","Bodies/Bigdipper/bigdipper.png");
    start.animation(window);
    start.draw(window);
    while(start.begin) {
        constGrid.GridMaking(window);
        while(constGrid.show1) {
            Orion.drawBody(window);
            orionGrid.GridMaking(window);
        }
        while(constGrid.show2) {
            bigDipper.drawBody(window);
            bigDipperGrid.GridMaking(window);
        }
        window.next_frame();
    }
}