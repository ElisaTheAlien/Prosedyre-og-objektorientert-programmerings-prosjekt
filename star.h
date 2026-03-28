#pragma once

#include <fstream>
#include <filesystem>
#include "Celestialbodies.h"


class Star : public celestialBody {
private:
    std::string magnitude;
    std::string distance;
    std::string spectralType;
    std::string Ra_Dec;
    std::string Az_Alt;

    std::filesystem::path image_path;
    TDT4102::Image image;

public:
    Star(std::string infoPath, std::string imagePath_);
    friend std::ifstream& operator>>(std::ifstream& inputStream, Star& star);
    void drawBody(TDT4102::AnimationWindow& win) override;
};
