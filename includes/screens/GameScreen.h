#ifndef GAME_SCREEN_H_
#define GAME_SCREEN_H_

#include "Screen.h"
#include "../utils/ButtonFactory.h"
#include <FL/Fl_Grid.H>
#include <vector>
#include <FL/Fl_Button.H>

class GameScreen : public Screen {
    Fl_Grid* grid;
    std::vector<Fl_Button*> buttons;
    Fl_Button* menuBtn;

public:
    GameScreen(int w, int h);
    void setup(Fl_Group* parent) override;
    Fl_Button* getMenuBtn();
};

#endif
