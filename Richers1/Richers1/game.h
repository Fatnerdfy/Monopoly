//
//  game.h
//  Richers1
//
//  Created by CQQ on 2017/9/18.
//  Copyright © 2017年 CQQ. All rights reserved.
//

#ifndef game_h
#define game_h
#include <iostream>
#include "menu.h"

using namespace std;

class Game {
private:
    Menu* menu;
    MenuFactory* mf;
    int getInput();
public:
    void init();
    void run();
    void term();
};

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
#endif /* game_h */
