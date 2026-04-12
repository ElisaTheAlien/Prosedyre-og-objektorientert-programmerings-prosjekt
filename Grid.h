#pragma once
#include <iostream>
#include "Celestialbodies.h"
#include <vector>
#include "star.h"

class Grid{
    private:
    std::filesystem::path const1_path;
    TDT4102::Image const1;

    std::filesystem::path const2_path;
    TDT4102::Image const2;

    public:
    Grid(std::string const1_path_, std::string const2_path_);
    void draw(TDT4102::AnimationWindow& win);
};