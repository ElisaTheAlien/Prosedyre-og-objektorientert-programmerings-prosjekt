#include <iostream>
#include "star.h"

int main() {
    Star star("Bodies/Betelguse/betelguse.txt", "Bodies/Betelguse/betelguse.png"); 
    TDT4102::AnimationWindow win; 
    TDT4102::AnimationWindow* ptr = &win;
    while (!win.should_close()){
        star.drawBody(*ptr);
    }
    

    return 0;
}

