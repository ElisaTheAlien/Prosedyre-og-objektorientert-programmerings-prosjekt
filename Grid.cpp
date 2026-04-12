#include "Grid.h"

Grid::Grid(std::string const1_path_, std::string const2_path_):
    const1_path{const1_path_}, const1{const1_path},
    const2_path{const2_path_}, const2{const2_path}
{}

void Grid::draw(TDT4102::AnimationWindow& win){
    int winWidth = win.width(); 
    int winHeight = win.height();
    const int image_width = winWidth/2;
    const int image_height = winHeight;;
    win.draw_image({0,0}, const1, image_width, image_height);
    win.draw_image({winWidth/2,0}, const1, image_width, image_height);
}