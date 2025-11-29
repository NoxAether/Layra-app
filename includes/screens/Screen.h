#ifndef SCREEN_H_
#define SCREEN_H_

#include <FL/Fl_Group.H>

class Screen {
protected:
    Fl_Group* group;
    int width, height;

public:
    Screen(int w, int h);
    virtual ~Screen();

    virtual void setup(Fl_Group* parent) = 0;

    void show();
    void hide();
    Fl_Group* getGroup();
};

#endif
