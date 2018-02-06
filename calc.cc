#include "calc.h"
#include <iostream>
#include <string>

using namespace std;

Calc::Calc()
: m_button1("1"),
    m_button2 ("2"),
    m_button3 ("3"),
    m_button4 ("4"),
    m_button5 ("5"),
    m_button6 ("6"),
    m_button7 ("7"),
    m_button8 ("8"),
    m_button9 ("9")
{
    set_title("Calc");
    set_border_width(10);

    add(m_grid);

    m_button1.signal_clicked().connect(sigc::bind<string>(
        sigc::mem_fun(*this,
         &Calc::on_number_button_clicked), m_button1.get_label()));
    m_grid.attach(m_button1, 0, 2, 1, 1);

    m_button2.signal_clicked().connect(sigc::bind<string>(
        sigc::mem_fun(*this,
         &Calc::on_number_button_clicked), m_button2.get_label()));
    m_grid.attach(m_button2, 1, 2, 1, 1);

    m_button3.signal_clicked().connect(sigc::bind<string>(
        sigc::mem_fun(*this,
         &Calc::on_number_button_clicked), m_button3.get_label()));
    m_grid.attach(m_button3, 2, 2, 1, 1);

    m_button4.signal_clicked().connect(sigc::bind<string>(
        sigc::mem_fun(*this,
         &Calc::on_number_button_clicked), m_button4.get_label()));
    m_grid.attach(m_button4, 0, 1, 1, 1);

    m_button5.signal_clicked().connect(sigc::bind<string>(
        sigc::mem_fun(*this,
         &Calc::on_number_button_clicked), m_button5.get_label()));
    m_grid.attach(m_button5, 1, 1, 1, 1);

    m_button6.signal_clicked().connect(sigc::bind<string>(
        sigc::mem_fun(*this,
         &Calc::on_number_button_clicked), m_button6.get_label()));
    m_grid.attach(m_button6, 2, 1, 1, 1);

    m_button7.signal_clicked().connect(sigc::bind<string>(
        sigc::mem_fun(*this,
         &Calc::on_number_button_clicked), m_button7.get_label()));
    m_grid.attach(m_button7, 0, 0, 1, 1);

    m_button8.signal_clicked().connect(sigc::bind<string>(
        sigc::mem_fun(*this,
         &Calc::on_number_button_clicked), m_button8.get_label()));
    m_grid.attach(m_button8, 1, 0, 1, 1);

    m_button9.signal_clicked().connect(sigc::bind<string>(
        sigc::mem_fun(*this,
         &Calc::on_number_button_clicked), m_button9.get_label()));
    m_grid.attach(m_button9, 2, 0, 1, 1);

    show_all_children();
};

Calc::~Calc()
{
}

void Calc::on_number_button_clicked(string data)
{
    std::cout << data << std::endl;
}
