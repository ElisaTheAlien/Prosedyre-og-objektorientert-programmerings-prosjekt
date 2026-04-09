#include "runStellar.h"
#include "startScreen.h"
#include "star.h"
#include "constillation.h"
#include "GridConstillation.h"
#include "GridStar.h"

void runStellar::run(TDT4102::AnimationWindow& window){
    startScreen start("Startscreen/welcome.txt", "Startscreen/earth.png");
    GridConstillation constGrid;
    GridStar orionGrid;
    GridStar bigDipperGrid;
    Constillation Orion("",""); 
    Constillation bigDipper("","");
    start.animation(window);
    while(!quit){
        start.draw(window);
        while(start.begin) {
            constGrid.GridMaking(window);
            Orion.show = constGrid.show1;
            bigDipper = constGrid.show2;
            while(Orion.show) {
                Orion.drawBody(window);
                orionGrid.GridMaking(window);
            }
            while(bigDipper.show) {
                bigDipper.drawBody(window);
                bigDipperGrid.GridMaking(window);
            }
        }
    }
}