#include "startScreen.h"
startScreen(std::string textPath, std::string eartPath_, std::string rocketPath_)
        : earthPath{earthPath_},    
      image{earthPath}, rocketPath{rocketPath_},    
      image{rocketPath}          
{
    std::ifstream inputStream{textPath};
    if (inputStream) {
        inputStream >> *this;
    }
}

void startScreen::Callback(){
    begin = true;
}

void startScreen::draw(TDT4102::AnimationWindow& win){
    TDT4102::Image backgroundImage("background.jpg");
    const int win_width = win.width();
    const int win_height = win.height();
    win.draw_image({0,0}, backgroundImage, win_width, win_height);
    const TDT4102::Point buttonPosition {win_width/2, win_height/4};
    const int buttonWidth = 100;
    const int buttonHeight = 40;
    const std::string buttonLabel = "Explore the nightsky!";
    TDT4102::Button startButton {buttonPosition, buttonWidth, buttonHeight, buttonLabel};
    startButton.setCallback(std::bind(Callback, this));
    win.add(startButton);
    const int maxRadius = 2*win_width/3;
    TDT4102::Point Position{win_width/2-maxRadius, win_height/2-maxRadius};
    win.draw_image(Position, image, maxRadius, maxRadius);
    const int textPad = win_width/75;
    const TDT4102::Point nameUpperLeft {win_width/10,win_height/18};
    const int nameSize = win_height/10;
    const int textLeftPad = win_width/2;
    const int textUpperPad = win_height/4;
    const int textSize = textPad;
    win.draw_text(nameUpperLeft, text, TDT4102::Color::white, nameSize, TDT4102::Font::courier_bold);
}

void startScreen::animation(TDT4102::AnimationWindow& win){
    TDT4102::Image backgroundImage("Startscreen/background.jpg");
    const int win_width = win.width();
    const int win_height = win.height();
    TDT4102::Point Position {win_width/2, win_height/2};
    for (int radius = 0; radius < win_width/3; radius++) {
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