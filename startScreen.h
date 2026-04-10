#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include "AnimationWindow.h"
#include "widgets/Button.h"

class startScreen{
    private: 
    std::string text;
    std::filesystem::path earthPath;
    std::filesystem::path rocketPath;
    TDT4102::Image earth;
    TDT4102::Image rocket;

    public: 
    startScreen(std::string textPath, std::string earthPath_, std::string rocketPath_);
    friend std::ifstream& operator>>(std::ifstream& inputStream, startScreen& start);
    void startAnimation(TDT4102::AnimationWindow& win);
    void endAnimation(TDT4102::AnimationWindow& win);   
    void startScreen::draw(TDT4102::AnimationWindow& win, TDT4102::Button& startButton);
    void Callback();
    bool begin = false;
};