#include "star.h"

Star::Star(std::string infoPath, std::string imagePath_) 
    : image_path{imagePath_},    
      image{image_path}          
{
    std::ifstream inputStream{infoPath};
    if (inputStream) {
        inputStream >> *this;
    }
}

std::ifstream& operator>> (std::ifstream& inputStream, Star& star){
    inputStream >> star.name; 
    inputStream >> star.magnitude;
    inputStream >> star.distance;
    inputStream >> star.spectralType;
    inputStream >> star.Ra_Dec;
    inputStream >> star.Az_Alt;
    return inputStream;
}

void Star::drawBody(TDT4102::AnimationWindow& win) {
    TDT4102::Image backgroundImage("background.jpg");
    const int win_width = win.width();
    const int win_height = win.height();
    win.draw_image({0,0}, backgroundImage, win_width, win_height);
    const TDT4102::Point textBoxUpperLeft {win_width/2,win_height/4};
    const int textBox_width = win_width/5; 
    const int textBox_height = win_height/10;
    win.draw_rectangle(textBoxUpperLeft, textBox_width, textBox_height, TDT4102::Color::black);
    const int textPad = win_width/75;
    const TDT4102::Point nameUpperLeft {2*win_width/3,win_height/20};
    const int nameSize = win_height/18;
    const int textLeftPad = win_width/2;
    const int textUpperPad = win_height/4;
    const int textSize = textPad;
    win.draw_text(nameUpperLeft, name, TDT4102::Color::white, nameSize, TDT4102::Font::courier_bold);
    win.draw_text({textLeftPad,textUpperPad}, "Magnitude: " + magnitude, TDT4102::Color::white, textSize,TDT4102::Font::courier_italic);
    win.draw_text({textLeftPad,textUpperPad + textPad}, "Distance: " + distance + " light years", TDT4102::Color::white, textSize,TDT4102::Font::courier_italic);
    win.draw_text({textLeftPad,textUpperPad + 2 * textPad}, "Spectral Type: " + spectralType, TDT4102::Color::white, textSize,TDT4102::Font::courier_italic);
    win.draw_text({textLeftPad,textUpperPad + 3 * textPad}, "Ra/Dec: " + Ra_Dec, TDT4102::Color::white, textSize,TDT4102::Font::courier_italic);
    win.draw_text({textLeftPad,textUpperPad + 4 * textPad}, "Az/Alt: " + Az_Alt, TDT4102::Color::white, textSize,TDT4102::Font::courier_italic);
    TDT4102::Point imageUpperLeft {win_width/8, win_height/6};
    const int image_width = win_width/4;
    win.draw_image(imageUpperLeft, image, image_width, image_width);
}
