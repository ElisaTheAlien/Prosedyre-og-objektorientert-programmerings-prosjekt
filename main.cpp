#include <iostream>
#include "constillation.h"
#include "star.h"
#include "startScreen.h"
#include "Stellar.h"

int main() {
    Stellar stellar({0,0}, 700, 800, "Stellar");
    stellar.run();

    return 0;
}

