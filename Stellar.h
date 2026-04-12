#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "startScreen.h"
#include "star.h"
#include "constillation.h"
#include "Grid.h"

class Stellar : public TDT4102::AnimationWindow {
    private: 
    int winWidth;
    int winHeight;

    TDT4102::Image rocket;
    std::filesystem::path rocketPath;

    const TDT4102::Point buttonPosition1 {0, 0};
    const TDT4102::Point buttonPosition2 {winWidth/2, 0};
    const unsigned int buttonWidth = winWidth/2;;
    const unsigned int buttonHeight = winHeight;
    const std::string buttonLabel = "";

    TDT4102::Button OrionButton;
    bool showOrion = false;
    TDT4102::Button BigDipperButton;
    bool showBigDipper = false;
    TDT4102::Button BetegeuseButton;
    bool showBetelguse = false;
    TDT4102::Button RigelButton;
    bool showRigel = false;

    const unsigned int startButtonWidth = 100;
    const unsigned int startButtonHeight = 40;
    const TDT4102::Point startButtonPosition {winWidth/2-50, winHeight/4-20};
    const std::string startButtonLabel = "Begin";
    TDT4102::Button startButton;
    bool begin = false;

    const unsigned int backButtonWidth = 100;
    const unsigned int backButtonHeight = 40;
    const TDT4102::Point backButtonPosition {winWidth-150, winHeight-70};
    const std::string backButtonLabel = "Back";
    TDT4102::Button backButton;

    enum class Screen {
        START,
        CONSTELLATION_SELECT,
        ORION_DETAIL,
        BIGDIPPER_DETAIL,
        STAR_DETAIL
    };
    Screen currentScreen = Screen::START;
    
    public: 
    Stellar(TDT4102::Point position, int width, int height, const std::string& title);
    void setFalse();
    void run();

    void OrionCallback();
    void BigDipperCallback(); 
    void BetelguseCallback(); 
    void RigelCallback();
    void startCallback();
    void backCallback();
    void transition(TDT4102::AnimationWindow& window);
};