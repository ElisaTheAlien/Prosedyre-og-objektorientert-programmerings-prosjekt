#include <iostream>
#include "constillation.h"
#include "star.h"
#include "startScreen.h"

int main() {
    TDT4102::AnimationWindow win (0,0,300,200); 
    TDT4102::AnimationWindow* ptr = &win;
    runStellar Stellar;
    Stellar.run(*ptr);
    return 0;
}

