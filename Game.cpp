#include "Game.h"
#include <iostream>
#include "Terminal.h"
#include <iterator>
#include <algorithm>

Game::Game(int number_of_keys, HAL *hal, bool is_test)
{
    std::cout << "Game constructor called" << std::endl;
    this->numberOfKeys = number_of_keys;
    this->hal = hal;
    this->is_test = is_test;
}

Game::~Game()
{
    std::cout << "Game destructor called" << std::endl;
}

std::uint8_t Game::getLastResult(std::vector<char> target_sequence, std::vector<char> button_pressed)
{

    int count = 0;

    if (button_pressed.size() == 0)
    {
        return IS_UNKNOWN;
    }

    int position = (button_pressed.size() - 1) % this->numberOfKeys;

    if (*button_pressed.rbegin() == target_sequence[position])
    {
        return IS_EQUAL;
    }
    else
    {
        if (std::find(target_sequence.begin(), target_sequence.end(), *button_pressed.rbegin()) != target_sequence.end())
        {
            return IS_EXISTENT;
        }
        else
        {
            return IS_NOT_EXISTENT;
        }
    }
}

std::vector<std::uint8_t> Game::getLEDResult(std::vector<uint8_t> results)
{
    std::vector<std::uint8_t> led_results;
    for (int i = 0; i < this->numberOfKeys - int(results.size()); i++)
    {
        led_results.push_back(IS_UNKNOWN);
    }

    std::copy(results.size() < this->numberOfKeys ? results.begin() : results.end() - this->numberOfKeys,
              results.end(),
              std::back_inserter(led_results));
    return led_results;
}

void Game::restart()
{
    int button_pressed = 0;
    this->button_pressed.clear();
    std::vector<std::uint8_t> results;
    std::vector<std::uint8_t> led_results;
    std::cout << "======Game started====== " << std::endl;
    this->target_sequence.clear();
    for (int i = 0; i < this->numberOfKeys; i++)
    {
        switch (std::rand() % 3 + 1)
        {
        case 1:
            this->target_sequence.push_back(BUTTON_A);
            break;
        case 2:
            this->target_sequence.push_back(BUTTON_B);
            break;
        case 3:
            this->target_sequence.push_back(BUTTON_C);
            break;
        default:
            break;
        }
    }

    if(this->is_test){
        std::cout << "Target sequence: ";
        for (int i = 0; i < this->numberOfKeys; i++)
        {
            std::cout << this->target_sequence[i] << " ";
        }
        std::cout << std::endl;
    }

    while (true)
    {
        for (int i = 0; i < this->numberOfKeys; i++)
        {
            std::cout << "Key " << i + 1 << std::endl;
            button_pressed = hal->readButtonPressed(true);
            this->button_pressed.push_back(button_pressed);

            results.push_back(getLastResult(this->target_sequence, this->button_pressed));

            led_results = getLEDResult(results);

            this->hal->setResult(led_results, results.size());
            if (led_results == std::vector<std::uint8_t>(this->numberOfKeys, IS_EQUAL))
            {
                break;
            }
        }
        if (led_results == std::vector<std::uint8_t>(this->numberOfKeys, IS_EQUAL))
        {
            break;
        }
    }
}
