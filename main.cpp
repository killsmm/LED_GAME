#include <iostream>
#include "Game.h"
#include "Terminal.h"

int main(){
    Game* game = new Game(3, new Terminal());
    game->restart();
}