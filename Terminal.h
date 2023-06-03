#ifndef TERMINAL_H
#define TERMINAL_H

#include "HAL.h"

class Terminal : public HAL
{
public:
    Terminal();
    ~Terminal();
    void init() override;
    char readButtonPressed(bool blocking) override;
    void setResult(std::vector<std::uint8_t> result, int keysPressed) override;
};

#endif /* TERMINAL_H */
