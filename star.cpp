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

void Star::drawStar(TDT4102::AnimationWindow& win) {
    TDT4102::Image backgroundImage("background.jpg");
    const int win_width = win.width();
    const int win_height = win.height();
    win.draw_image({0,0}, backgroundImage, win_width, win_height);
    const TDT4102::Point textBoxUpperLeft {1480,470};
    const int textBox_width = 650; 
    const int textBox_height = 260;
    win.draw_rectangle(textBoxUpperLeft, textBox_width, textBox_height, TDT4102::Color::black);
    const int textPad = 40;
    const TDT4102::Point nameUpperLeft {200,100};
    const int nameSize = 170;
    const int textLeftPad = 1500;
    const int textUpperPad = 500;
    const int textSize = 40;
    win.draw_text(nameUpperLeft, star.name, TDT4102::Color::white, nameSize, TDT4102::Font::courier_bold);
    win.draw_text({textLeftPad,textUpperPad}, "Magnitude: " + star.magnitude, TDT4102::Color::white, textSize,TDT4102::Font::courier_italic);
    win.draw_text({textLeftPad,textUpperPad + textPad}, "Distance: " + star.distance + " light years", TDT4102::Color::white, textSize,TDT4102::Font::courier_italic);
    win.draw_text({textLeftPad,textUpperPad + 2 * textPad}, "Spectral Type: " + star.spectralType, TDT4102::Color::white, textSize,TDT4102::Font::courier_italic);
    win.draw_text({textLeftPad,textUpperPad + 3 * textPad}, "Ra/Dec: " + star.Ra_Dec, TDT4102::Color::white, textSize,TDT4102::Font::courier_italic);
    win.draw_text({textLeftPad,textUpperPad + 4 * textPad}, "Az/Alt: " + star.Az_Alt, TDT4102::Color::white, textSize,TDT4102::Font::courier_italic);
    TDT4102::Point imageUpperLeft {400, 350};
    const int image_width = 800;
    win.draw_image(imageUpperLeft, star.image, image_width, image_width);
}
