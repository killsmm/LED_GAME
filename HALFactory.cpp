#include "HALFactory.h"

HAL* HALFactory::create(int type) {
    switch (type) {
        case TERMINAL:
            return new Terminal();
        case ARDUINO:
            // return new Arduino();
        case RASPBERRY:
            // return new Raspberry();
        default:
            return nullptr;
    }
}