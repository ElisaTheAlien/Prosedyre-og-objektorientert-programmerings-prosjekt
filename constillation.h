#include <iostream>
#include "Celestialbodies.h"

class Constillation : public celestialBody{
    protected:
        std::string name;
        std::string distance;

        std::filesystem::path image_path;
        TDT4102::Image image;
    
    public:
        Constillation (std::string name_, std::string imagePath_);
        const std::string& getName() const {
            return name;
        }
        void drawBody(TDT4102::AnimationWindow& win) override;
};