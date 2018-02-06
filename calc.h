#ifndef CALC_H
#define CALC_H

#include <gtkmm.h>
#include <string>

using namespace std;

class Calc : public Gtk::Window
{

public:
    Calc();
    virtual ~Calc();

private:
    void on_number_button_clicked(string data);

    Gtk::Grid m_grid;
    Gtk::Button m_button1,
    m_button2,
    m_button3,
    m_button4,
    m_button5,
    m_button6,
    m_button7,
    m_button8,
    m_button9;
    Gtk::Button m_buttons [9];
};

#endif
