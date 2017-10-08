//
//  main.cpp
//  Richers3
//
//  Created by CQQ on 2017/10/8.
//  Copyright © 2017年 FatNerd. All rights reserved.
//

#include <iostream>
using namespace std;
#include "game.h"
#include "menufactory.h"
#include "blockmgr.h"

int main()
{
    Game * game= Game::getInstance();
    game->init(SpeedMenuFactory::getFactory() );
    game->run();
    game->term();
    
    BlockMgr::releaseMgr();
    MenuFactory::releaseFactory();
    
    delete game;
    
    return 0;
}

