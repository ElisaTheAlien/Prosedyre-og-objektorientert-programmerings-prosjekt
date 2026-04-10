#include "startScreen.h"
startScreen::startScreen(std::string textPath, std::string earthPath_, std::string rocketPath_)
        : earthPath{earthPath_},    
      earth{earthPath}, rocketPath{rocketPath_},    
      rocket{rocketPath}          
{
    std::ifstream inputStream{textPath};
    if (inputStream) {
        inputStream >> *this;
    }
}

void startScreen::Callback(){
    begin = true;
}

void startScreen::draw(TDT4102::AnimationWindow& win, TDT4102::Button& startButton){
    TDT4102::Image backgroundImage("background.jpg");
    const int win_width = win.width();
    const int win_height = win.height();
    win.draw_image({0,0}, backgroundImage, win_width, win_height);
    startButton.setCallback(std::bind(Callback, this));
    const int maxRadius = 2*win_width/3;
    TDT4102::Point Position{win_width/2-maxRadius, win_height/2-maxRadius};
    win.draw_image(Position, earth, maxRadius, maxRadius);
    const int textPad = win_width/75;
    const TDT4102::Point nameUpperLeft {win_width/10,win_height/18};
    const int nameSize = win_height/10;
    const int textLeftPad = win_width/2;
    const int textUpperPad = win_height/4;
    const int textSize = textPad;
    win.draw_text(nameUpperLeft, text, TDT4102::Color::white, nameSize, TDT4102::Font::courier_bold);
}

void startScreen::startAnimation(TDT4102::AnimationWindow& win){
    TDT4102::Image backgroundImage("Startscreen/background.jpg");
    const int win_width = win.width();
    const int win_height = win.height();
    TDT4102::Point Position {win_width/2, win_height/2};
    for (int radius = 0; radius < win_width/3; radius++) {
        win.draw_image({0,0}, backgroundImage, win_width, win_height);
        win.draw_image(Position, earth, 2*radius, 2*radius);
        win.next_frame();
    }
}

void startScreen::endAnimation(TDT4102::AnimationWindow& win){
    TDT4102::Image backgroundImage("Startscreen/background.jpg");
    const int win_width = win.width();
    const int win_height = win.height();
    int xPosition = win_width/2; 
    TDT4102::Point startPosition {win_width/2-rocket.width/2, win_height/2-rocket.height/2};
    while(xPosition--){
        win.draw_image({0,0}, backgroundImage, win_width, win_height);
        win.draw_image({win_width/2-rocket.width/2-xPosition, win_height/2-rocket.height/2}, rocket, rocket.width, rocket.height);
        win.next_frame();
    }
}


std::ifstream& operator>> (std::ifstream& inputStream, startScreen& start){
    while(inputStream >> start.text){
    }
    return inputStream;
}