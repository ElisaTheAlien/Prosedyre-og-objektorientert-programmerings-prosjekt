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
    start.startAnimation(window);
    start.draw(window);
    if(start.begin){
        start.endAnimation(window);
    }
    while(start.begin) {
        {constGrid.GridMaking(window);}
        if(constGrid.show1) {
            constGrid.show1 = false;
            Orion.drawBody(window);
            {orionGrid.GridMaking(window);}
            
            if(orionGrid.show1) {
                orionGrid.show1 = false;
                Betelgeuse.drawBody(window);
                
            }


        }
        if(constGrid.show2) {
            constGrid.show2 = false;
            bigDipper.drawBody(window);
            bigDipperGrid.GridMaking(window);
        }
        window.next_frame();
    }
}