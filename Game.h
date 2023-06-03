#ifndef GAME_H
#define GAME_H

#include <cstdint>
#include <vector>
#include "HAL.h"

#define IS_UNKNOWN LED_OFF
#define IS_EQUAL LED_GREEN
#define IS_EXISTENT LED_ORANGE
#define IS_NOT_EXISTENT LED_RED

class Game
{
public:
    std::vector<char> target_sequence;
    std::vector<char> button_pressed;
    Game(int rounds, HAL *hal, bool is_test = false);
    ~Game();
    void restart();
    std::uint8_t getLastResult(std::vector<char> target_sequence, std::vector<char> button_pressed);
    std::vector<std::uint8_t> getLEDResult(std::vector<uint8_t> results);

private:
    HAL *hal;
    int numberOfKeys;
    bool is_test;
};

#endif /* GAME_H */
