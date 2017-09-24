//
//  game.cpp
//  Richers2
//
//  Created by CQQ on 2017/9/24.
//  Copyright © 2017年 CQQ. All rights reserved.
//

#include <iostream>
using namespace std;
#include "game.h"
#include "menu.h"

Game * Game::game = nullptr;

Game * Game::getInstance() {
    if (game == nullptr) {
        int gid = 1;
        GameFactory * gf = new GameFactory;
        game = gf->createGame(gid);
    }
    return game;
}

Game::Game() {
    
}

Game::~Game()
{
}

void Game::init()
{
    mnuCur = Menu::getInstance(MenuID::MENU_MAIN);
    nCountPlayers = 2; //默认2个玩家(电脑和用户)
    nVolume = 50;
    nResolutionX = 1024;
    nResolutionY = 768;
}
void Game::run()
{
    bool goon = true;
    while(goon) {
        goon = mnuCur->process(Game::getInstance()) ;
    }
}
void Game::term()
{
    Menu::releaseAllMenus();
}

void Game::setMenu(Menu * menu)
{
    mnuCur = menu;
}
void Game::setPlayersCount(int num)
{
    nCountPlayers = num;
    cout << "Set number of players = " << nCountPlayers << endl;
}
void Game::loadRecord(int recID)
{
    cout << "Loading record with id=" << recID << endl;
}
void Game::saveRecord(int recID)
{
    cout << "Saving to record with id=" << recID << endl;
}
void Game::setVolume(int vol)
{
    nVolume = vol;
    cout << "Set Volume to " << vol << endl;
}
void Game::setResolution(int xres, int yres)
{
    nResolutionX = xres;
    nResolutionY = yres;
    cout << "Set Resolution to " << nResolutionX << " X " << nResolutionY << endl;
}

Game * GameFactory::createGame(int gid) {
    switch (gid) {
        case 1:
            return new Game();
            break;
            
        default:
            return new Game();
            break;
    }
}
