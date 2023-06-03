#include "Terminal.h"
#include <iostream>

Terminal::Terminal()
{

}

Terminal::~Terminal()
{

}

void Terminal::init()
{
    // Initialize the terminal
}

void Terminal::setLed1(std::uint8_t color)
{
    // Set the color of LED 1
}

void Terminal::setLed2(std::uint8_t color)
{
    // Set the color of LED 2
}

void Terminal::setLed3(std::uint8_t color)
{
    // Set the color of LED 3
}

int Terminal::readButtonPressed(bool blocking)
{
    // Read the button pressed
    char button_pressed;
    std::cout << "Enter the button to be pressed [A/B/C]: ";
    std::cin >> button_pressed;
    switch (button_pressed)
    {
    case 'a':
    case 'A':
        return BUTTON_A;
    case 'b':
    case 'B':
        return BUTTON_B;
    case 'c':
    case 'C':
        return BUTTON_C;
    default:
        return readButtonPressed(blocking);
    }
}