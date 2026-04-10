#include "runStellar.h"
#include "startScreen.h"
#include "star.h"
#include "constillation.h"
#include "GridConstillation.h"
#include "GridStar.h"

void runStellar::callbackQuit(){
    quit = true;
}

void runStellar::callbackConstillation(){
    backConstillation = true;
}
void runStellar::callbackStar(){
    backStar = true;
}
void runStellar::callbackMainMenu(){
    mainMenu = true;
}

void runStellar::run(TDT4102::AnimationWindow& window){
    int winWidth = window.width();
    int winHeight = window.height();

    const TDT4102::Point buttonPosition1 {0, 0};
    const TDT4102::Point buttonPosition2 {winWidth/2, 0};
    const unsigned int buttonWidth = winWidth/2;;
    const unsigned int buttonHeight = winHeight;
    const std::string buttonLabel = "";

    TDT4102::Button OrionButton {buttonPosition1, buttonWidth, buttonHeight, buttonLabel};
    TDT4102::Button BigDipperButton {buttonPosition2, buttonWidth, buttonHeight, buttonLabel};
    TDT4102::Button BetegeuseButton {buttonPosition1, buttonWidth, buttonHeight, buttonLabel};
    TDT4102::Button RigelButton {buttonPosition2, buttonWidth, buttonHeight, buttonLabel};

    const TDT4102::Point startButtonPosition {winWidth/2, winHeight/4};
    const unsigned int startButtonWidth = 100;
    const unsigned int startButtonHeight = 40;
    const std::string startButtonLabel = "Begin";
    TDT4102::Button startButton {startButtonPosition, startButtonWidth, startButtonHeight, startButtonLabel};
    window.add(startButton);
    
    startScreen start("Startscreen/welcome.txt", "Startscreen/earth.png", "Drawing of rocket/Rocket from earth.png");
    GridConstillation constGrid;
    GridStar orionGrid;
    GridStar bigDipperGrid;
    Constillation Orion("Orion","Bodies/Orion/orion.png"); 
    Constillation bigDipper("BigDipper","Bodies/Bigdipper/Big-Dipper-1.jpg");
    Star Betelgeuse("Bodies/Betelgeuse.txt", "Bodies/Orion/Betelgeuse.png");
    Star Rigel("Bodies/Rigel.txt", "Bodies/Rigel/Rigel.png");
    constGrid.GridMaking(window, OrionButton, BigDipperButton);
    orionGrid.GridMaking(window, BetegeuseButton, RigelButton);

    start.startAnimation(window);

    while(!start.begin){
        start.draw(window, startButton);
    }
    while(start.begin) {

        if(constGrid.show1){
            OrionButton.setVisible(false);
            BigDipperButton.setVisible(false);
            Orion.drawBody(window);

            if(orionGrid.show1){
                BetegeuseButton.setVisible(false);
                RigelButton.setVisible(false);
                Betelgeuse.drawBody(window);
            }

            if(orionGrid.show2){
                BetegeuseButton.setVisible(false);
                RigelButton.setVisible(false);
                Rigel.drawBody(window);
            }

        }
        if(constGrid.show2){
            OrionButton.setVisible(false);
            BigDipperButton.setVisible(false);
            bigDipper.drawBody(window);
        }

        window.next_frame();
    }
}