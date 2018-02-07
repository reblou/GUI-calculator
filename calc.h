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
    void on_ce_clicked();
    void on_op_clicked(string op);
    void on_eq_clicked();
    void on_dot_clicked();
    string evaluate_float(float x);

    string op;
    int mem;
    float fmem;

    gboolean res;
    gboolean floating;

    Gtk::Grid m_grid;
    Gtk::Button m_buttons [9];
    Gtk::Button m_button0, m_button_dot, m_button_eq, m_button_ce;
    Gtk::Button m_op_buttons [4];

    Gtk::Label m_label;

};

#endif
