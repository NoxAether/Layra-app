#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Grid.H>
#include <vector>
#include <algorithm>

Fl_Group *screen1;
Fl_Group *screen2;

void switch_to_screen2(Fl_Widget *widget, void *data) {
  screen1->hide();
  screen2->show();
}

void switch_to_screen1(Fl_Widget *widget, void *data) {
  screen2->hide();
  screen1->show();
}

auto main(int argc, char *argv[]) -> int {

  int win_w = 1280;
  int win_h = 740;
  Fl_Window *window = new Fl_Window(win_w, win_h);
  window->color(fl_rgb_color(20, 20, 30));

  // MENU SCREEN
  screen1 = new Fl_Group(0, 0, win_w, win_h);
  screen1->color(fl_rgb_color(20, 20, 30));

  int box_w = 300;
  int box_h = 50;
  Fl_Box *box1 = new Fl_Box((win_w - box_w) / 2, 20, box_w, box_h, "Lyra");
  box1->box(FL_FLAT_BOX);
  box1->labelsize(30);
  box1->labelcolor(FL_WHITE);
  box1->color(fl_rgb_color(20, 20, 30));
  int btn_w = 300;
  int btn_h = 80;
  Fl_Button *button1 =
      new Fl_Button((window->w() - btn_w) / 2, window->h() - btn_h - 20, btn_w,
                    btn_h, "Dashboard");
  button1->clear_visible_focus();
  button1->box(FL_BORDER_BOX);
  button1->color(fl_rgb_color(50, 50, 80));
  button1->labelcolor(FL_WHITE);
  button1->selection_color(fl_rgb_color(30, 60, 120));
  button1->color2(fl_rgb_color(10, 10, 50));
  button1->down_box(FL_FLAT_BOX);
  button1->align(FL_ALIGN_CENTER);
  button1->callback(switch_to_screen2);

  screen1->end();

  // GAME SCREEN
  screen2 = new Fl_Group(0, 0, window->w(), window->h());
  screen2->color(fl_rgb_color(20, 20, 20));
  // start hidden
  screen2->hide();

  Fl_Grid *grid = new Fl_Grid(20, 20, window->w() - 40, window->h() * 0.7);
  int row = 10;
  int cols = 10;
  grid->layout(row, cols, 0, 0);
  grid->color(FL_WHITE);

  // to hold each element in grid
  std::vector<Fl_Button*> buttons;

  // fill the vector with buttons
  for (int i = 0; i < row * cols; i++) {
    Fl_Button *new_button = new Fl_Button(0, 0, 0, 0, "N");
    new_button->clear_visible_focus();
    new_button->box(FL_FLAT_BOX);
    new_button->color(fl_rgb_color(50, 50, 80));
    new_button->labelcolor(FL_WHITE);
    buttons.push_back(new_button);
  }

  for (long unsigned int idx = 0; idx < buttons.size(); idx++) {
    int r = idx / cols;
    int c = idx % cols;
    grid->widget(buttons[idx], r, c);
  }
  grid->color(fl_rgb_color(20, 20, 30));
  grid->box(FL_FLAT_BOX);
  grid->selection_color(fl_rgb_color(10, 10, 50));

  grid->box(FL_BORDER_BOX);
  grid->color(fl_rgb_color(20, 20, 30));
  grid->labelcolor(FL_WHITE);

  grid->show_grid(1);

  grid->end();
  Fl_Button *button2 =
      new Fl_Button((window->w() - btn_w) / 2, window->h() - btn_h - 20, btn_w,
                    btn_h, "Menu");
  button2->clear_visible_focus();
  button2->box(FL_BORDER_BOX);
  button2->color(fl_rgb_color(50, 50, 80));
  button2->labelcolor(FL_WHITE);
  button2->selection_color(fl_rgb_color(30, 60, 120));
  button2->color2(fl_rgb_color(10, 10, 50));
  button2->down_box(FL_FLAT_BOX);
  button2->align(FL_ALIGN_CENTER);
  button2->labelcolor(FL_WHITE);
  button2->callback(switch_to_screen1);

  window->end();
  window->show();

  return Fl::run();
}
