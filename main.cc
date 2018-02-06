#include "calc.h"
#include <gtkmm/application.h>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    Calc c;

    return app->run(c);
}
