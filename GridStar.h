#include "AnimationWindow.h"
#include "widgets/Button.h"

class GridStar : public TDT4102::AnimationWindow {
    public:
        void GridMaking(TDT4102::AnimationWindow& window);
        void CallbackButton1();
        void CallbackButton2();
        bool show1 = false;
        bool show2 = false;

};


