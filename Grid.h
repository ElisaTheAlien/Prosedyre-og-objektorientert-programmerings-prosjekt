#include "AnimationWindow.h"
#include "widgets/Button.h"

class Grid : public TDT4102::AnimationWindow {
    public:
        Grid(int width, int height, const std::string& title) : TDT4102::AnimationWindow(width, height, title){

        }

};

void Grid(TDT4102::AnimationWindow& window);
