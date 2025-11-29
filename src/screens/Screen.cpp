#include "../../includes/screens/Screen.h"

Screen::Screen(int w, int h) : width(w), height(h), group(nullptr) {}
Screen::~Screen() {}

void Screen::show() { if(group) group->show(); }
void Screen::hide() { if(group) group->hide(); }
Fl_Group* Screen::getGroup() { return group; }
