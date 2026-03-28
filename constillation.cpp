#include "constillation.h"

Constillation::Constillation (std::string name_, std::string imagePath_): 
    image_path{imagePath_}, image{image_path}, name{name_}       
{}

void Constillation::drawBody(TDT4102::AnimationWindow& win){
    TDT4102::Image backgroundImage("background.jpg");
    const int win_width = win.width();
    const int win_height = win.height();
    win.draw_image({0,0}, backgroundImage, win_width, win_height);
    const TDT4102::Point textBoxUpperLeft {win_width/2,win_height/4};
    const int textBox_width = win_width/5; 
    const int textBox_height = win_height/10;
    win.draw_rectangle(textBoxUpperLeft, textBox_width, textBox_height, TDT4102::Color::black);
    const TDT4102::Point nameUpperLeft {2*win_width/3,win_height/20};
    const int nameSize = win_height/18;
    win.draw_text(nameUpperLeft, name, TDT4102::Color::white, nameSize, TDT4102::Font::courier_bold);
    TDT4102::Point imageUpperLeft {win_width/2, win_height/2};
    const int image_width = win_width/4;
    win.draw_image(imageUpperLeft, image, image_width, image_width);
}