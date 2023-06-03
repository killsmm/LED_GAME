#ifndef HALFACTORY_H
#define HALFACTORY_H

#include "HAL.h"
#include "Terminal.h"

#define TERMINAL 0
#define ARDUINO 1
#define RASPBERRY 2

class HALFactory
{
public:
    static HAL* create(int type);
};

#endif /* HALFACTORY_H */
