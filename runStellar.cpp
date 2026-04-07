#include "runStellar.h"

void run(TDT4102::AnimationWindow& window){
    startScreen start("Startscreen/welcome.txt", "Startscreen/earth.png");
    start.animate(window);
    while(!quit){
        start.draw(window);
    }
}