#include <iostream>
#include "Celestialbodies.h"

class Constillation : public celestialBody{
    protected:
        std::string name;
        std::string distance;
    
    public:
        const std::string& getName() const {
            return name;
        }
        void drawBody(TDT4102::AnimationWindow& win) override;
};