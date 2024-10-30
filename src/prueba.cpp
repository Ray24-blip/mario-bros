#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 0;
    int a;
    a=20;
    auto can = Canvas(200,200);
    can.DrawBlockCircle(10,10,10);
    can.DrawBlockCircle(20,20,10);
    can.DrawBlockCircle(30,10,10);
    can.DrawBlockCircle(40,20,10);
    can.DrawBlockCircle(50,10,10);

    while (true)
    {
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::BlueLight, border(vbox(canvas(&can))));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.1s);
        frame++;
    }

    return 0;
}