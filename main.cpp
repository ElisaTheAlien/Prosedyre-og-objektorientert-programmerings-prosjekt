#include <iostream>
#include "constillation.h"
#include "star.h"
#include "startScreen.h"
#include "Stellar.h"

int main() {
    Stellar stellar({0,0}, 3000, 2000, "Stellar");
    stellar.run();
}

