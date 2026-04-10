#pragma once
#include <iostream>
#include "Celestialbodies.h"
#include <vector>
#include "star.h"

class Constillation : public celestialBody{
    protected:
        std::string name;
        std::string distance;

        std::filesystem::path image_path;
        TDT4102::Image image;

        std::vector<Star*> stars;
    
    public:
        Constillation (std::string name_, std::string imagePath_);
        const std::string& getName() const {
            return name;
        }
        void drawBody(TDT4102::AnimationWindow& win) override;
};