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
    startScreen start("Startscreen/welcome.txt", "Startscreen/earth.png", "Drawing of rocket/Rocket from earth.png");
    GridConstillation constGrid;
    GridStar orionGrid;
    GridStar bigDipperGrid;
    Constillation Orion("Bodies/Orion/orion.txt","Bodies/Orion/orion.png"); 
    Constillation bigDipper("Bodies/Bigdipper/bigdipper.txt","Bodies/Bigdipper/bigdipper.png");
    Star Betelgeuse("Bodies/Betelgeuse.txt", "Bodies/Orion/Betelgeuse.png");
    constGrid.GridMaking(window);
    orionGrid.GridMaking(window);
    bigDipperGrid.GridMaking(window);
    start.startAnimation(window);
    while(!start.begin){
        start.draw(window);
    }
    while(start.begin) {

        if(constGrid.show1) {
            constGrid.show1 = false;
            Orion.drawBody(window);
           
            
            if(orionGrid.show1) {
                orionGrid.show1 = false;
    

            }


        }
        if(constGrid.show2) {
            constGrid.show2 = false;
            bigDipper.drawBody(window);
     
        }
        window.next_frame();
    }
}