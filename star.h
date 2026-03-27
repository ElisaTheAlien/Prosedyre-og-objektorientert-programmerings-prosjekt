#pragma once
#include <iostream>
#include <fstream>
#include "Celestialbodies.h"

class Star : public virtual celestialBodies{
private:
    // Information
    std::string name;
    std::string magnitude;
    std::string distance;
    std::string spectralType;
    std::string Ra_Dec;
    std::string Az_Alt;

    // Image
    std::filesystem::path image_path;
    TDT4102::Image image;
public: 
    Star(std::string infoPath, std::string imagePath_);
    friend void drawStar(TDT4102::AnimationWindow& win, Star star);
    friend std::ifstream& operator>> (std::ifstream& inputStream, Star& star);
    void drawBody(TDT4102::AnimationWindow& win);
};