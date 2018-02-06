#include "calc.h"
#include <iostream>
#include <string>
#include <gtkmm.h>

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
          },
    m_label ("0"),
    m_button0 ("0"),
    m_button_dot ("."),
    m_button_eq  ("="),
    m_op_buttons {
        Gtk::Button ("+"),
        Gtk::Button ("-"),
        Gtk::Button ("*"),
        Gtk::Button ("/")
    },
    m_button_ce ("CE")
{
    res = FALSE;
    set_title("Calc");
    set_border_width(10);

    add(m_grid);
    m_grid.set_hexpand(TRUE);
    m_grid.set_vexpand(TRUE);

    m_label.set_hexpand(TRUE);
    m_label.set_vexpand(TRUE);

    m_button0.set_hexpand(TRUE);
    m_button0.set_vexpand(TRUE);

    m_button_dot.set_hexpand(TRUE);
    m_button_dot.set_vexpand(TRUE);

    m_button_eq.set_hexpand(TRUE);
    m_button_eq.set_hexpand(TRUE);

    m_button_ce.set_hexpand(TRUE);
    m_button_ce.set_vexpand(TRUE);

    m_grid.attach(m_label, 0, 0, 3, 1);
    m_grid.attach(m_button0, 0, 4, 1, 1);
    m_grid.attach(m_button_dot, 1, 4, 1, 1);
    m_grid.attach(m_button_eq, 2, 4, 1, 1);
    m_grid.attach(m_button_ce, 4, 0, 1, 1);



    int i = 1;
    for (Gtk::Button &button : m_op_buttons) {
        button.set_hexpand(TRUE);
        button.set_vexpand(TRUE);

        button.signal_clicked().connect(sigc::bind<string>(
            sigc::mem_fun(*this,
            &Calc::on_op_clicked), button.get_label()));
        m_grid.attach(button, 4, i++, 1, 1);
    }


    m_button_ce.signal_clicked().connect(sigc::mem_fun(*this, &Calc::on_ce_clicked));
    m_button_eq.signal_clicked().connect(sigc::mem_fun(*this, &Calc::on_eq_clicked));

    int row, column, num;

    for (Gtk::Button &button : m_buttons) {
        button.set_hexpand(TRUE);
        button.set_vexpand(TRUE);

        num = stoi(button.get_label(), nullptr, 10);

        column = (num-1) % 3;
        row = 3 - ((num-1) /  3);
        button.signal_clicked().connect(sigc::bind<string>(
            sigc::mem_fun(*this,
             &Calc::on_number_button_clicked), button.get_label()));
        m_grid.attach(button, column, row, 1, 1);
    }
    m_button0.signal_clicked().connect(sigc::bind<string>(
        sigc::mem_fun(*this, &Calc::on_number_button_clicked), "0"));
    m_button_dot.signal_clicked().connect(sigc::bind<string>(
        sigc::mem_fun(*this, &Calc::on_number_button_clicked), "."));

    const Gdk::RGBA my_col ("#505050");
    m_label.override_background_color(my_col, Gtk::STATE_FLAG_NORMAL);

    show_all_children();
};

Calc::~Calc()
{
    //cout << mem << endl;
}

void Calc::on_number_button_clicked(string data)
{
    //std::cout << data << std::endl;
    string ci = m_label.get_label();
    if (ci != "0" && !res) {
        m_label.set_label(ci + data);
    } else {
        m_label.set_label(data);
        res = FALSE;
    }
}

void Calc::on_ce_clicked()
{
    m_label.set_label("0");
    mem = 0;
    op = "";
}

void Calc::on_op_clicked(string oper)
{
    mem = stoi(m_label.get_label(), nullptr, 10);
    op = oper;
    m_label.set_label("0");
}

void Calc::on_eq_clicked()
{
    int ans;
    int x = stoi(m_label.get_label() ,nullptr, 10);

    if (op == "+") {
        ans = mem + x;
    } else if (op == "-") {
        ans = mem - x;
    } else if (op == "*") {
        ans = mem * x;
    } else if (op == "/") {
        ans = mem / x;
    } else {
        m_label.set_label("ERR");
        res = TRUE;
        op = "";
        return;
    }

    m_label.set_label(to_string(ans));
    res = TRUE;
    op = "";
}

string evaluate(int x)
{

}
