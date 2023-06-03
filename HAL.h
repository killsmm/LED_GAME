#ifndef HAL_H
#define HAL_H

#include <cstdint>
#include <vector>

#define LED_OFF    0x00
#define LED_RED    0x01
#define LED_GREEN  0x02
#define LED_ORANGE   0x04

#define BUTTON_A 'A'
#define BUTTON_B 'B'
#define BUTTON_C 'C'

class HAL
{
public:
    virtual void init() = 0;
    virtual char readButtonPressed(bool blocking) = 0;
    virtual void setResult(std::vector<std::uint8_t> result, int keysPressed) = 0;
};

#endif /* HAL_H */
