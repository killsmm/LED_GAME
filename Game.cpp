#include "Game.h"
#include <iostream>
#include "Terminal.h"


Game::Game(int number_of_keys, HAL *hal){
    std::cout << "Game constructor called" << std::endl;
    this->numberOfKeys = number_of_keys;
    this->hal = hal;
}

Game::~Game() {
    std::cout << "Game destructor called" << std::endl;
}



void Game::restart() {
    int button_pressed = 0;
    for(int i = 0; i < this->numberOfKeys; i++){
        this->target_sequence.push_back(rand() % 3 + 1);
    }

    std::cout << "Game started: " << std::endl;
    for(int i = 0; i < this->numberOfKeys; i++){
        std::cout << "Key " << i + 1 << std::endl;
        button_pressed = hal->readButtonPressed(true);
        this->button_pressed.push_back(button_pressed);
    }

    if (this->target_sequence == this->button_pressed){
        std::cout << "You won!" << std::endl;
    } else {
        std::cout << "You lost!" << std::endl;
    }
}

