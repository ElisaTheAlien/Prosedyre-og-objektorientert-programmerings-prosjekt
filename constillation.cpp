#include "constillation.h"

Constillation::Constillation (std::string name_, std::string imagePath_): 
    image_path{imagePath_}, image{image_path}, name{name_}       
{}

void Constillation::drawBody(TDT4102::AnimationWindow& win){
    const int win_width = win.width();
    const int win_height = win.height();
    win.draw_rectangle({0,0}, win_width, win_height, TDT4102::Color::black);
    const TDT4102::Point nameUpperLeft {win_width/10,win_height/18};
    const int nameSize = win_height/10;
    win.draw_text(nameUpperLeft, name, TDT4102::Color::white, nameSize, TDT4102::Font::courier_bold);
    const int image_width = win_width;
    const int image_height = win_height;
    TDT4102::Point imageUpperLeft {win_width/2-image_width/2, win_height/2-image_height/2};
    win.draw_image(imageUpperLeft, image, image_width, image_height);
    win.next_frame();
}