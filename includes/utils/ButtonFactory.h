#ifndef BUTTON_FACTORY_H_
#define BUTTON_FACTORY_H_

#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Enumerations.H>
#include <functional>

struct ButtonSpec {
    int x, y, w, h;
    const char* label;
    Fl_Color color = FL_GRAY;
    Fl_Color labelColor = FL_WHITE;
    Fl_Color color2 = FL_GRAY;
    Fl_Color selectionColor = FL_WHITE;
    Fl_Boxtype boxType = FL_FLAT_BOX;
};

class ButtonFactory {
public:
    static Fl_Button* createButton(Fl_Group* parent, const ButtonSpec& spec,
        std::function<void(Fl_Widget*)> callback = nullptr);
};

#endif
