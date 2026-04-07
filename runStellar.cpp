#include "runStellar.h"
#include "startScreen.h"
#include "star.h"
#include "constillation.h"

void runStellar::run(TDT4102::AnimationWindow& window){
    startScreen start("Startscreen/welcome.txt", "Startscreen/earth.png");
    start.animation(window);
    while(!quit){
        start.draw(window);
    }
}