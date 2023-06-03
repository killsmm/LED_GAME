#include "Terminal.h"
#include <iostream>
#include <vector>

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

char Terminal::readButtonPressed(bool blocking)
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

void Terminal::setResult(std::vector<std::uint8_t> result, int keysPressed)
{
    // Set the result
    
    for (auto i : result)
    {
        switch (i)
        {
        case LED_GREEN:
            std::cout << "\033[1;32mGREEN \033[0m";
            break;
        case LED_RED:
            std::cout << "\033[1;31mRED \033[0m";
            break;
        case LED_ORANGE:
            std::cout << "\033[1;33mORANGE \033[0m ";
            break;
        case LED_OFF:
            std::cout << "\033[1;30mOFF \033[0m";
            break;
        default:
            break;
        }
    }

    std::cout << std::endl;

    if (result == std::vector<std::uint8_t>(result.size(), LED_GREEN))
    {
        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "Result: You tried " << keysPressed << " times to get the correct sequence." << std::endl;
        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "" << std::endl;
    }
}