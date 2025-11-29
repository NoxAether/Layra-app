#include "../../includes/screens/MenuScreen.h"

MenuScreen::MenuScreen(int w, int h) : Screen(w, h), dashboardBtn(nullptr) {}

void MenuScreen::setup(Fl_Group* parent) {
    parent->begin();
    group = new Fl_Group(0,0,width,height);
    group->color(fl_rgb_color(20,20,30));

    dashboardBtn = ButtonFactory::createButton(group,
        { (width-300)/2, height-80-20, 300, 80, "Dashboard", fl_rgb_color(50,50,80) });

    group->end();
    parent->end();
}

Fl_Button* MenuScreen::getDashboardBtn() { return dashboardBtn; }
