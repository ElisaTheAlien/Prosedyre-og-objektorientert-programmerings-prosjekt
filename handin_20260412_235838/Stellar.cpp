#include "Stellar.h"

Stellar::Stellar(TDT4102::Point position, int width, int height, const std::string& title):
    AnimationWindow(position.x, position.y, width, height, title),
    winWidth{width}, 
    winHeight{height},
    OrionButton {buttonPosition1, buttonWidth, buttonHeight, buttonLabel},
    BigDipperButton {buttonPosition2, buttonWidth, buttonHeight, buttonLabel},
    BetegeuseButton {buttonPosition1, buttonWidth, buttonHeight-200, buttonLabel},
    RigelButton {buttonPosition2, buttonWidth, buttonHeight, buttonLabel},
    startButton {startButtonPosition, startButtonWidth, startButtonHeight, startButtonLabel},
    backButton{backButtonPosition, backButtonWidth, backButtonHeight, backButtonLabel},
    quitButton{quitButtonPosition, quitButtonWidth, quitButtonHeight, quitButtonLabel}

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
    add(backButton);
    backButton.setCallback(std::bind(&Stellar::backCallback, this));
    add(quitButton);
    quitButton.setCallback(std::bind(&Stellar::quitCallback, this));
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

void Stellar::backCallback(){
    switch(currentScreen){
        case Screen::STAR_DETAIL:
            showBetelguse = false;
            showRigel = false;
            currentScreen = Screen::ORION_DETAIL;
            break;

        case Screen::ORION_DETAIL:
            showOrion = false;
            currentScreen = Screen::CONSTELLATION_SELECT;
            break;

        case Screen::BIGDIPPER_DETAIL:
            showBigDipper = false;
            currentScreen = Screen::CONSTELLATION_SELECT;
            break;

        case Screen::CONSTELLATION_SELECT:
            begin = false;
            currentScreen = Screen::START;
            break;

        default:
            break;
    }
}

void Stellar::quitCallback(){
    quit = true;
}

void Stellar::logVisit(const std::string& bodyName){
    std::ofstream logFile("visit_log.txt", std::ios::app); // app = legg til, ikke overskriv
    if(logFile.is_open()){
        // Hent nåværende tid
        std::time_t now = std::time(nullptr);
        std::string timeStr = std::ctime(&now);
        timeStr.pop_back(); // Fjern newline fra ctime
        
        logFile << "[" << timeStr << "] Visited: " << bodyName << "\n";
        logFile.close();
    }
}

void Stellar::transitionRight(TDT4102::AnimationWindow& window){
    TDT4102::Image backgroundImage("Startscreen/background.jpg");
    std::filesystem::path rocketPath = "Drawings of rocket/To right.png";
    TDT4102::Image rocket("Drawings of rocket/To right.png");
    const int win_width = window.width();
    const int win_height = window.height();
    const int maxRadius = win_height/5;
    TDT4102::Point Position{win_width/2-maxRadius, win_height/2-maxRadius};
    for (int xPosition = 0; xPosition < win_height; xPosition += 2){
        window.draw_image({0,0}, backgroundImage, win_width, win_height);
        window.draw_image({win_width/2-rocket.width/2 + xPosition, win_height/2-rocket.height/2}, rocket, 5*rocket.width, 5*rocket.height);
        window.next_frame();
    }
}

void Stellar::transitionUp(TDT4102::AnimationWindow& window){
    TDT4102::Image backgroundImage("Startscreen/background.jpg");
    std::filesystem::path rocketPath = "Drawings of rocket/Up.png";
    TDT4102::Image rocket("Drawings of rocket/Up.png");
    const int win_width = window.width();
    const int win_height = window.height();
    const int maxRadius = win_height/5;
    TDT4102::Point Position{win_width/2-maxRadius, win_height/2-maxRadius};
    for (int yPosition = 0; yPosition < win_height; yPosition += 2){
        window.draw_image({0,0}, backgroundImage, win_width, win_height);
        window.draw_image({win_width/2-rocket.width/2, win_height/2-rocket.height/2-yPosition}, rocket, 5*rocket.width, 5*rocket.height);
        window.next_frame();
    }
}

void Stellar::transitionDown(TDT4102::AnimationWindow& window){
    TDT4102::Image backgroundImage("Startscreen/background.jpg");
    std::filesystem::path rocketPath = "Drawings of rocket/Down.png";
    TDT4102::Image rocket("Drawings of rocket/Down.png");
    const int win_width = window.width();
    const int win_height = window.height();
    const int maxRadius = win_height/5;
    TDT4102::Point Position{win_width/2-maxRadius, win_height/2-maxRadius};
    for (int yPosition = 0; yPosition < win_height; yPosition += 2){
        window.draw_image({0,0}, backgroundImage, win_width, win_height);
        window.draw_image({win_width/2-rocket.width/2, win_height/2-rocket.height/2+yPosition}, rocket, 5*rocket.width, 5*rocket.height);
        window.next_frame();
    }
}

void Stellar::transitionLeft(TDT4102::AnimationWindow& window){
    TDT4102::Image backgroundImage("Startscreen/background.jpg");
    std::filesystem::path rocketPath = "Drawings of rocket/To left.png";
    TDT4102::Image rocket("Drawings of rocket/To left.png");
    const int win_width = window.width();
    const int win_height = window.height();
    const int maxRadius = win_height/5;
    TDT4102::Point Position{win_width/2-maxRadius, win_height/2-maxRadius};
    for (int xPosition = 0; xPosition < win_height; xPosition += 2){
        window.draw_image({0,0}, backgroundImage, win_width, win_height);
        window.draw_image({win_width/2-rocket.width/2 - xPosition, win_height/2-rocket.height/2}, rocket, 5*rocket.width, 5*rocket.height);
        window.next_frame();
    }
}

void Stellar::setFalse(){
    OrionButton.setVisible(false);
    BigDipperButton.setVisible(false);
    BetegeuseButton.setVisible(false);
    RigelButton.setVisible(false);
    startButton.setVisible(false);
    backButton.setVisible(false);
    quitButton.setVisible(false);
}

void Stellar::run(){
    startScreen start("Startscreen/welcome.txt", "Startscreen/earth.png", "Drawings of rocket/Up.png");
    Constillation Orion("Orion","Bodies/Orion/orion.png"); 
    Constillation bigDipper("BigDipper","Bodies/Bigdipper/Big-Dipper-1.jpg");
    Star Betelgeuse("Bodies/Betelguse/betelgeuse.txt", "Bodies/Betelguse/betelgeuse.png");
    Star Rigel("Bodies/rigel.txt", "Bodies/Rigel/rigel.png");
    Grid grid("Bodies/Orion/orion.png", "Bodies/Bigdipper/Big-Dipper-1.jpg");

    this->setFalse();
    start.startAnimation(*this);

    while(!(this->should_close())){
        this -> setFalse();
        switch(currentScreen){
            case Screen::START:
                startButton.setVisible(true);
                quitButton.setVisible(true);
                start.draw(*this);
                if(quit){
                    this -> close(); 
                }
                if(begin){
                    start.endAnimation(*this);
                    begin = false;
                    startButton.setVisible(false);
                    quitButton.setVisible(false);
                    currentScreen = Screen::CONSTELLATION_SELECT;
                }
                break;

            case Screen::CONSTELLATION_SELECT:
                grid.draw(*this);         
                OrionButton.setVisible(true);
                BigDipperButton.setVisible(true);
                backButton.setVisible(true);
                if(showOrion){    
                    currentScreen = Screen::ORION_DETAIL;
                    logVisit("Orion");
                } else if(showBigDipper){
                    currentScreen = Screen::BIGDIPPER_DETAIL;
                    logVisit("Big Dipper");
                }
                break;

            case Screen::ORION_DETAIL:
                Orion.drawBody(*this);
                BetegeuseButton.setVisible(true);
                RigelButton.setVisible(true);
                backButton.setVisible(true);
                if(showBetelguse || showRigel){
                    currentScreen = Screen::STAR_DETAIL;
                }
                break;

            case Screen::BIGDIPPER_DETAIL:
                bigDipper.drawBody(*this);
                backButton.setVisible(true);
                break;

            case Screen::STAR_DETAIL:
                if(showBetelguse){  
                    Betelgeuse.drawBody(*this);
                    logVisit("Betelgeuse");
                } else if(showRigel){ 
                    Rigel.drawBody(*this);
                    logVisit("Rigel");   
                }
                backButton.setVisible(true);
                break;
        }

        this->next_frame();
    }
}
