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

int Game::getInput() {
    int input;
    cout << " Your selected:" ;
    cin >> input;
    cout << "Choice=" << input <<endl;
    return input;
}

void Game::init() {
    mf = new MainMenuFactory;
    menu = mf->createMenu();
}

void Game::run() {
    int input;
    while (true) {
        menu->display();
        input = getInput();
        if (input==0) {
            break;
        } else {
            menu->select(input);
            menu->submenu->display();
            menu->submenu->select(getInput());
        }
    }
}

void Game::term() {
    
}
