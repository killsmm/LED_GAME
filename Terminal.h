#ifndef TERMINAL_H
#define TERMINAL_H

#include "HAL.h"

class Terminal : public HAL
{
public:
    Terminal();
    ~Terminal();
    void init() override;
    void setLed1(std::uint8_t color) override;
    void setLed2(std::uint8_t color) override;
    void setLed3(std::uint8_t color) override;
    int readButtonPressed(bool blocking) override;
};

#endif /* TERMINAL_H */
