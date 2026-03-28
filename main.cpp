#include <iostream>
#include "constillation.h"
#include "star.h"

int main() {
    Constillation orion("Orion", "Bodies/orion/orion.png"); 
    TDT4102::AnimationWindow win (0,0,300,200); 
    TDT4102::AnimationWindow* ptr = &win;
    while (!win.should_close()){
        orion.drawBody(*ptr);
    }
    

    return 0;
}

