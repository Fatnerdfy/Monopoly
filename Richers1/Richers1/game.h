//
//  game.h
//  Richers1
//
//  Created by CQQ on 2017/9/18.
//  Copyright © 2017年 CQQ. All rights reserved.
//

#ifndef game_h
#define game_h
#include "menu.h"

class Game {
private:
    Menu* menu;
    MenuFactory* mf;
public:
    void init();
    void run();
    void term();
};

#endif /* game_h */
