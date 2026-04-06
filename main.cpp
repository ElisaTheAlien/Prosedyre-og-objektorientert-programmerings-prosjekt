#include <iostream>
#include "constillation.h"
#include "star.h"
#include "startScreen.h"

int main() {
    startScreen screen("Startscreen/welcome.txt", "Startscreen/earth.png");
    TDT4102::AnimationWindow win (0,0,300,200); 
    TDT4102::AnimationWindow* ptr = &win;
    while (!win.should_close()){
          screen.animation(*ptr);
    }
    

    return 0;
}

