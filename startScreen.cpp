#include "startScreen.h"

startScreen::startScreen(std::string textPath, std::string imagePath_)
        : image_path{imagePath_},    
      image{image_path}          
{
    std::ifstream inputStream{textPath};
    if (inputStream) {
        inputStream >> *this;
    }
}

void startScreen::draw(TDT4102::AnimationWindow& win){
    TDT4102::Image backgroundImage("background.jpg");
    const int win_width = win.width();
    const int win_height = win.height();
    win.draw_image({0,0}, backgroundImage, win_width, win_height);
}

void startScreen::animation(TDT4102::AnimationWindow& win){
    TDT4102::Image backgroundImage("Startscreen/background.jpg");
    const int win_width = win.width();
    const int win_height = win.height();
    TDT4102::Point Position {win_width/2, win_height/2};
    for (int radius = 0; radius < 300; radius++) {
        win.draw_image({0,0}, backgroundImage, win_width, win_height);
        win.draw_image(Position, image, 2*radius, 2*radius);
        win.next_frame();
    }
}


std::ifstream& operator>> (std::ifstream& inputStream, startScreen& start){
    while(inputStream >> start.text){
    }
    return inputStream;
}