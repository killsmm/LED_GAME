#ifndef GAME_H
#define GAME_H

#include <cstdint>
#include <vector>
#include "HAL.h"


class Game
{
public:
    std::vector<std::uint8_t> target_sequence;
    std::vector<std::uint8_t> button_pressed;
    Game(int rounds, HAL *hal);
    ~Game();
    void restart();
private:
    HAL *hal;
    int numberOfKeys;
};

#endif /* GAME_H */
