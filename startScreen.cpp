#include "startScreen.h"
startScreen::startScreen(std::string textPath, std::string earthPath_, std::string rocketPath_)
        : earthPath{earthPath_},    
      earth{earthPath}, rocketPath{rocketPath_},    
      rocket{rocketPath}          
{
    try {
            std::ifstream inputStream{textPath};
            inputStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

            if (inputStream) {
                inputStream >> *this;
            }

        } catch (const std::ios_base::failure& e) {
            std::cerr << "Feil ved åpning av filen '" << textPath << "': " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Uventet feil: " << e.what() << std::endl;
        }
}


void startScreen::draw(TDT4102::AnimationWindow& win){
    TDT4102::Image backgroundImage("Startscreen/background.jpg");
    const int win_width = win.width();
    const int win_height = win.height();
    win.draw_image({0,0}, backgroundImage, win_width, win_height);
    const int maxRadius = win_height/5;
    TDT4102::Point Position{win_width/2-maxRadius, win_height/2-maxRadius};
    win.draw_image(Position, earth, 2*maxRadius, 2*maxRadius);
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
    for (int radius = 0; radius < win_height/5; radius++) {
        TDT4102::Point Position {win_width/2- radius, win_height/2 - radius};
        win.draw_image({0,0}, backgroundImage, win_width, win_height);
        win.draw_image(Position, earth, 2*radius, 2*radius);
        win.next_frame();
    }
}

void startScreen::endAnimation(TDT4102::AnimationWindow& win){
    TDT4102::Image backgroundImage("Startscreen/background.jpg");
    const int win_width = win.width();
    const int win_height = win.height();
    const int maxRadius = win_height/5;
    TDT4102::Point Position{win_width/2-maxRadius, win_height/2-maxRadius};
    for (int yPosition = 0; yPosition < win_height; yPosition += 2){
        win.draw_image({0,0}, backgroundImage, win_width, win_height);
        win.draw_image({win_width/2-rocket.width/2, win_height/2-rocket.height/2-yPosition}, rocket, 5*rocket.width, 5*rocket.height);
        win.draw_image(Position, earth, 2*maxRadius, 2*maxRadius);
        win.next_frame();
    }
}


std::ifstream& operator>> (std::ifstream& inputStream, startScreen& start){
    while(inputStream >> start.text){
    }
    return inputStream;
}