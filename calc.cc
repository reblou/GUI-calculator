#include "calc.h"
#include <iostream>
#include <string>

using namespace std;

Calc::Calc()
:
    m_buttons {
                Gtk::Button ("1"),
                Gtk::Button ("2"),
                Gtk::Button ("3"),
                Gtk::Button ("4"),
                Gtk::Button ("5"),
                Gtk::Button ("6"),
                Gtk::Button ("7"),
                Gtk::Button ("8"),
                Gtk::Button ("9")
          }
{
    set_title("Calc");
    set_border_width(10);

    add(m_grid);
    m_grid.set_hexpand(TRUE);
    m_grid.set_vexpand(TRUE);

    for (Gtk::Button &button : m_buttons) {
        button.set_hexpand(TRUE);
        button.set_vexpand(TRUE);
    }

    int row, column, num;

    for (Gtk::Button &button : m_buttons) {
        num = stoi(button.get_label(), nullptr, 10);

        column = (num-1) % 3;
        row = 2 - ((num-1) /  3);
        button.signal_clicked().connect(sigc::bind<string>(
            sigc::mem_fun(*this,
             &Calc::on_number_button_clicked), button.get_label()));
        m_grid.attach(button, column, row, 1, 1);
    }

    show_all_children();
};

Calc::~Calc()
{
}

void Calc::on_number_button_clicked(string data)
{
    std::cout << data << std::endl;
}
