//
//  game.cpp
//  Richers3
//
//  Created by CQQ on 2017/10/8.
//  Copyright © 2017年 FatNerd. All rights reserved.
//

#include <iostream>
using namespace std;
#include "game.h"
#include "menus.h"
#include "menufactory.h"
#include "map.h"
#include "mapbuilder.h"
#include "blockmgr.h"
#include "block.h"

Game * Game::game = nullptr;
Game * Game::getInstance()
{
    if(game == nullptr) {
        game = new Game;
    }
    
    return game;
}
void Game::releaseGame()
{
    delete game;
    game = nullptr;
}

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(MenuFactory * fac)
{
    facMenu = fac;
    mnuCur = getMenuFactory()->getMenu(MenuID::MENU_MAIN);
    createMap();
    nCountPlayers = 2; //默认2个玩家(电脑和用户)
    nVolume = 50;
    nResolutionX = 1024;
    nResolutionY = 768;
}
void Game::run()
{
    bool goon = true;
    
    while(goon) {
        goon = mnuCur->process() ;
    }
}
void Game::term()
{
    delete mapCur;
    MenuFactory::releaseFactory();
}
void Game::show()
{
    mapCur->show();
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
MenuFactory * Game::getMenuFactory() const
{
    return facMenu;
    //return NetMenuFactory::getFactory();
}

void Game::createMap()
{
    BlockMgr::getMgr()->setPrototy(BlockID::BLOCK_A,new BlockE);
    BlockMgr::getMgr()->setPrototy(BlockID::BLOCK_C,new BlockF);
    
    MapBuilder * builder = new BasicMapBuilder;
    MapDirector * director = new EasyMapDirector(builder);
    mapCur = director->buildMap();
    delete director;
    delete builder;
}

