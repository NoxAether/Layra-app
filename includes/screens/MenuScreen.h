#ifndef MENU_SCREEN_H_
#define MENU_SCREEN_H_

#include "Screen.h"
#include "../utils/ButtonFactory.h"
#include <FL/Fl_Button.H>

class MenuScreen : public Screen {
    Fl_Button* dashboardBtn;

public:
    MenuScreen(int w, int h);
    void setup(Fl_Group* parent) override;
    Fl_Button* getDashboardBtn();
};

#endif
