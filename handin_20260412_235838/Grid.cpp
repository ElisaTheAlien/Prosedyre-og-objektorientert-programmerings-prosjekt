#include "Grid.h"

Grid::Grid(std::string const1_path_, std::string const2_path_):
    const1_path{const1_path_}, const1{const1_path},
    const2_path{const2_path_}, const2{const2_path}
{
    if(!std::filesystem::exists(const1_path)){
        throw std::runtime_error("Grid: finner ikke fil");
    }
    if(!std::filesystem::exists(const2_path)){
        throw std::runtime_error("Grid: finner ikke fil");
    }
}

void Grid::draw(TDT4102::AnimationWindow& win){
    int winWidth = win.width(); 
    int winHeight = win.height();
    const int image_width = winWidth/2;
    const int image_height = winHeight;;
    win.draw_image({0,0}, const1, image_width, image_height);
    win.draw_image({winWidth/2,0}, const1, image_width, image_height);
}