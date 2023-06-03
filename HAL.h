#ifndef HAL_H
#define HAL_H

#include <cstdint>

#define LED_OFF    0x00
#define LED_RED    0x01
#define LED_GREEN  0x02
#define LED_ORANGE   0x04

#define BUTTON_A 0x01
#define BUTTON_B 0x02
#define BUTTON_C 0x04

class HAL
{
public:
    virtual void init() = 0;
    virtual void setLed1(std::uint8_t color) = 0;
    virtual void setLed2(std::uint8_t color) = 0;
    virtual void setLed3(std::uint8_t color) = 0;
    virtual int readButtonPressed(bool blocking) = 0;
};

#endif /* HAL_H */
