#include <iostream>
#include "Game.h"
#include "HALFactory.h"

int main(){
    Game* game = new Game(3, HALFactory::create(TERMINAL), true);
    while(true){
        game->restart();
    }
}