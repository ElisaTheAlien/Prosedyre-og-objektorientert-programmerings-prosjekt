#include "AnimationWindow.h"
#include "widgets/Button.h"

class GridConstillation : public TDT4102::AnimationWindow {
    public:
        void GridMaking(TDT4102::AnimationWindow& window);
        void CallbackButton1(TDT4102::AnimationWindow& window);
        void CallbackButton2(TDT4102::AnimationWindow& window);

    protected:
        TDT4102::Button button1;
        TDT4102::Button button2;

};


