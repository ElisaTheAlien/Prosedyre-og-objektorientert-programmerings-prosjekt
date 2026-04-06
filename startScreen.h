#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include "AnimationWindow.h"
#include "widgets/Button.h"

class startScreen{
    private: 
    std::string text;
    std::filesystem::path image_path;
    TDT4102::Image image;

    public: 
    startScreen(std::string textPath, std::string imagePath_);
    friend std::ifstream& operator>>(std::ifstream& inputStream, startScreen& start);
    void animation(TDT4102::AnimationWindow& win);
    void draw(TDT4102::AnimationWindow& win);
    void Callback();
};