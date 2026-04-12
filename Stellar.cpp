#include "Stellar.h"

Stellar::Stellar(TDT4102::Point position, int width, int height, const std::string& title):
    AnimationWindow(position.x, position.y, width, height, title),
    winWidth{width}, 
    winHeight{height},
    OrionButton {buttonPosition1, buttonWidth, buttonHeight, buttonLabel},
    BigDipperButton {buttonPosition2, buttonWidth, buttonHeight, buttonLabel},
    BetegeuseButton {buttonPosition1, buttonWidth, buttonHeight, buttonLabel},
    RigelButton {buttonPosition2, buttonWidth, buttonHeight, buttonLabel},
    startButton {startButtonPosition, startButtonWidth, startButtonHeight, startButtonLabel}

{
    add(OrionButton);
    OrionButton.setCallback(std::bind(&Stellar::OrionCallback, this));
    OrionButton.setButtonColor(TDT4102::Color::transparent);
    add(BigDipperButton);
    BigDipperButton.setCallback(std::bind(&Stellar::BigDipperCallback, this));
    OrionButton.setButtonColor(TDT4102::Color::transparent);
    add(BetegeuseButton);
    BetegeuseButton.setCallback(std::bind(&Stellar::BetelguseCallback, this));
    BetegeuseButton.setButtonColor(TDT4102::Color::transparent);
    add(RigelButton);
    RigelButton.setCallback(std::bind(&Stellar::RigelCallback, this));
    RigelButton.setButtonColor(TDT4102::Color::transparent);
    add(startButton);
    startButton.setCallback(std::bind(&Stellar::startCallback, this));

}

void Stellar::OrionCallback(){
    showOrion = true;
}

void Stellar::BigDipperCallback(){
    showBigDipper = true;
}

void Stellar::BetelguseCallback(){
    showBetelguse = true;
}

void Stellar::RigelCallback(){
    showRigel = true;
}

void Stellar::startCallback(){
    begin = true;
}

void Stellar::setFalse(){
    OrionButton.setVisible(false);
    BigDipperButton.setVisible(false);
    BetegeuseButton.setVisible(false);
    RigelButton.setVisible(false);
    startButton.setVisible(false);
}

void Stellar::run(){
    //Screens
    startScreen start("Startscreen/welcome.txt", "Startscreen/earth.png", "Drawings of rocket/Up.png");

    //Bodies
    Constillation Orion("Orion","Bodies/Orion/orion.png"); 
    Constillation bigDipper("BigDipper","Bodies/Bigdipper/Big-Dipper-1.jpg");
    Star Betelgeuse("Bodies/Betelgeuse.txt", "Bodies/Orion/Betelgeuse.png");
    Star Rigel("Bodies/Rigel.txt", "Bodies/Rigel/Rigel.png");

    this -> setFalse();
    start.startAnimation(*this);
    while(!(this->should_close())){
        startButton.setVisible(true);
        while(!begin){
            start.draw(*this);
            this->next_frame();
        }
        startButton.setVisible(false);
        start.endAnimation(*this);
        while(begin) {
            startButton.setVisible(false);
            OrionButton.setVisible(true);
            BigDipperButton.setVisible(true);

            if(showOrion){
                OrionButton.setVisible(false);
                BigDipperButton.setVisible(false);
                Orion.drawBody(*this);

                if(showBetelguse){
                    BetegeuseButton.setVisible(false);
                    RigelButton.setVisible(false);
                    Betelgeuse.drawBody(*this);
                }

                if(showRigel){
                    BetegeuseButton.setVisible(false);
                    RigelButton.setVisible(false);
                    Rigel.drawBody(*this);
                }

            }
            if(showBigDipper){
                OrionButton.setVisible(false);
                BigDipperButton.setVisible(false);
                bigDipper.drawBody(*this);
            }

            this->next_frame();
        }
    }
}
