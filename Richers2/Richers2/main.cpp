//
//  main.cpp
//  Richers2
//
//  Created by CQQ on 2017/9/24.
//  Copyright © 2017年 CQQ. All rights reserved.
//

#include <iostream>
using namespace std;
#include "game.h"

int main()
{
    Game * game = Game::getInstance();
    game->init();
    game->run();
    game->term();
    delete game;
    return 0;
}

