#include "../../includes/utils/ButtonFactory.h"

Fl_Button* ButtonFactory::createButton(Fl_Group* parent, const ButtonSpec& spec,
    std::function<void(Fl_Widget*)> callback)
{
    parent->begin();
    Fl_Button* btn = new Fl_Button(spec.x, spec.y, spec.w, spec.h, spec.label);
    btn->color(spec.color);
    btn->labelcolor(spec.labelColor);
    btn->color2(spec.color2);
    btn->selection_color(spec.selectionColor);
    btn->box(spec.boxType);
    btn->align(FL_ALIGN_CENTER);
    btn->clear_visible_focus();

    if(callback) {
        btn->callback([](Fl_Widget* w, void* data){
            auto f = static_cast<std::function<void(Fl_Widget*)>*>(data);
            (*f)(w);
        }, new std::function<void(Fl_Widget*)>(callback));
    }
    parent->end();
    return btn;
}
