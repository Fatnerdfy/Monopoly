//
//  main.cpp
//  Richers1
//
//  Created by CQQ on 2017/9/18.
//  Copyright © 2017年 CQQ. All rights reserved.
//

#include <iostream>
#include "game.h"

int main(int argc, const char * argv[]) {
    Game* game = new Game;
    game->init();
    game->run();
    game->term();
    delete game;
    return 0;
}
