//
//  game.cpp
//  Richers1
//
//  Created by CQQ on 2017/9/18.
//  Copyright © 2017年 CQQ. All rights reserved.
//

#include <iostream>
#include "game.h"

using namespace std;

void Game::init() {
    mf = new MainMenuFactory;
    menu = mf->createMenu();
}

void Game::run() {
    int input = 1;
    while (input) {
        menu->display();
        input = menu->getInput();
        menu->select(input);
    }
}

void Game::term() {
    delete mf;
    delete menu;
}
