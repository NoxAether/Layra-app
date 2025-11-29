#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include "../includes/screens/MenuScreen.h"
#include "../includes/screens/GameScreen.h"

// Callback for "Dashboard" button
void dashboard_cb(Fl_Widget* w, void* data) {
    auto screens = static_cast<std::pair<MenuScreen*, GameScreen*>*>(data);
    screens->first->hide();   // hide menu
    screens->second->show();  // show game
}

// Callback for "Menu" button
void menu_cb(Fl_Widget* w, void* data) {
  auto screens = static_cast<std::pair<MenuScreen*, GameScreen*>*>(data);
    screens->second->hide(); // hide game
    screens->first->show();  // show menu
}

int main() {
    int win_w = 1280;
    int win_h = 740;

    Fl_Window* window = new Fl_Window(win_w, win_h);
    window->color(fl_rgb_color(20,20,30));

    MenuScreen menu(win_w, win_h);
    GameScreen game(win_w, win_h);

    menu.setup(window);
    game.setup(window);

    game.hide();

    // Create a pair to pass both screens to the callback
    auto screens = new std::pair<MenuScreen*, GameScreen*>(&menu, &game);

    menu.getDashboardBtn()->callback(dashboard_cb, screens);
    game.getMenuBtn()->callback(menu_cb, screens);

    window->show();
    return Fl::run();
}
