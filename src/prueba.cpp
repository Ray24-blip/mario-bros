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

    while (true && frame < 100)
    {
        auto can = Canvas(200, 200);
        can.DrawBlockCircle(0 + frame, 10, 10, Color::Blue1);
        can.DrawBlockCircle(10 + frame, 20, 10, Color::Yellow1);
        can.DrawBlockCircle(20 + frame, 10, 10, Color::Black);
        can.DrawBlockCircle(30 + frame, 20, 10, Color::Green1);
        can.DrawBlockCircle(40 + frame, 10, 10, Color::Red1);
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::BlueLight, border(vbox(canvas(&can))));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.09s);
        frame++;
    }

    while (true && frame > 0)
    {
        auto can = Canvas(200, 200);
        can.DrawBlockCircle(0 +  frame, 10, 10, Color::Blue1);
        can.DrawBlockCircle(10 + frame, 20, 10, Color::Yellow1);
        can.DrawBlockCircle(20 + frame, 10, 10, Color::Black);
        can.DrawBlockCircle(30 + frame, 20, 10, Color::Green1);
        can.DrawBlockCircle(40 + frame, 10, 10, Color::Red1);
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::BlueLight, border(vbox(canvas(&can))));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.09s);
        frame--;
    }

    return 0;
}
