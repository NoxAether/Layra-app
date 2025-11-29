#include "../../includes/screens/GameScreen.h"

GameScreen::GameScreen(int w, int h) : Screen(w,h), grid(nullptr), menuBtn(nullptr) {}

void GameScreen::setup(Fl_Group* parent) {
    parent->begin();
    group = new Fl_Group(0,0,width,height);
    group->color(fl_rgb_color(20,20,20));

    // Create 10x10 grid
    grid = new Fl_Grid(20,20,width-40,height*0.7);
    grid->layout(10,10,0,0);
    grid->box(FL_FLAT_BOX);
    grid->color(fl_rgb_color(20,20,30));

    for(int i=0;i<100;i++){
        Fl_Button* b = new Fl_Button(0,0,0,0,"N");
        b->color(fl_rgb_color(50,50,80));
        b->labelcolor(FL_WHITE);
        b->clear_visible_focus();
        buttons.push_back(b);
    }

    for(size_t idx=0; idx<buttons.size(); idx++){
        int r = idx/10, c = idx%10;
        grid->widget(buttons[idx], r, c);
    }

    grid->show_grid(1);

    // Back button
    menuBtn = ButtonFactory::createButton(group,
        { (width-300)/2, height-80-20, 300, 80, "Menu", fl_rgb_color(50,50,80) });

    group->end();
    parent->end();
}

Fl_Button* GameScreen::getMenuBtn() { return menuBtn; }
