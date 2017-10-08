//
//  menus.cpp
//  Richers3
//
//  Created by CQQ on 2017/10/8.
//  Copyright © 2017年 FatNerd. All rights reserved.
//

#include <iostream>
using namespace std;
#include "menus.h"
#include "game.h"
#include "menufactory.h"
#include "global.h"

///菜单的主处理过程
bool Menu::process()
{
    show();
    int choice = getChoice();
    cout << "Choice=" << choice << endl;
    return doChoice(choice);
}

int Menu::getChoice()
{
    int choice;
    cin >> choice;
    return choice;
}
///-----主菜单------------------------
void MainMenu::show()
{
    cout << "\n\t" << "主菜单" << endl;
    cout << "1: New" << endl;
    cout << "2: Load" << endl;
    cout << "3: Save" << endl;
    cout << "4: Option" << endl;
    cout << "5: Play..." << endl;
    cout << "0: Exit" << endl;
    cout << " Your selected:";
}

bool MainMenu::doChoice(int choice)
{
    Game * game=Game::getInstance();
    switch(choice) {
        case 1:
            game->setMenu(game->getMenuFactory()->getMenu(MenuID::MENU_PLAYERS));
            return true;
            
        case 2:
            game->setMenu(game->getMenuFactory()->getMenu(MenuID::MENU_LOAD));
            return true;
            
        case 3:
            game->setMenu(game->getMenuFactory()->getMenu(MenuID::MENU_SAVE));
            return true;
            
        case 4:
            game->setMenu(game->getMenuFactory()->getMenu(MenuID::MENU_OPTION));
            return true;
            
        case 5:
            cout << "now is playing..." << endl;
            game->show();
            return true;
            
        default:
            return false;
    };
}
///-----玩家数量菜单------------------------
void PlayersMenu::show()
{
    cout << "\n\tSet number of players(2-8):" << endl;
    cout << "2. 2" << endl;
    cout << "3. 3" << endl;
    cout << "4. 4" << endl;
    cout << "5. 5" << endl;
    cout << "6. 6" << endl;
    cout << "7. 7" << endl;
    cout << "8. 8" << endl;
    cout << "0. Back" << endl;
    cout << " Your selected:";
}

bool PlayersMenu::doChoice(int choice)
{
    Game * game=Game::getInstance();
    if(choice >= 2 && choice <= 8) {
        game->setPlayersCount(choice);
    }
    
    game->setMenu(game->getMenuFactory()->getMenu(MenuID::MENU_MAIN));
    return true;
}
///-----Load菜单------------------------
void LoadMenu::show()
{
    cout << "\n\tSelect the Record to be loaded(1-5):" << endl;
    cout << "1. 1" << endl;
    cout << "2. 2" << endl;
    cout << "3. 3" << endl;
    cout << "4. 4" << endl;
    cout << "5. 5" << endl;
    cout << "0. Back" << endl;
    cout << " Your selected:";
}

bool LoadMenu::doChoice(int choice)
{
    Game * game=Game::getInstance();
    if(choice >= 1 && choice <= 5) {
        game->loadRecord(choice);
    }
    
    game->setMenu(game->getMenuFactory()->getMenu(MenuID::MENU_MAIN));
    return true;
}
///-----SAVE菜单------------------------
void SaveMenu::show()
{
    cout << "\n\tSelect the Record to save(1-5):" << endl;
    cout << "1. 1" << endl;
    cout << "2. 2" << endl;
    cout << "3. 3" << endl;
    cout << "4. 4" << endl;
    cout << "5. 5" << endl;
    cout << "0. Back" << endl;
    cout << " Your selected:";
}

bool SaveMenu::doChoice(int choice)
{
    Game * game=Game::getInstance();
    if(choice >= 1 && choice <= 5) {
        game->saveRecord(choice);
    }
    
    game->setMenu(game->getMenuFactory()->getMenu(MenuID::MENU_MAIN));
    return true;
}
///-----Option菜单------------------------
void OptionMenu::show()
{
    cout << "\n\tSet options :" << endl;
    cout << "1.Set the value of Volume(0-100)" << endl;
    cout << "2.Set the resolution" << endl;
    cout << "0. Back" << endl;
    cout << " Your selected:";
}

bool OptionMenu::doChoice(int choice)
{
    Game * game=Game::getInstance();
    if(choice == 1) {
        game->setMenu(game->getMenuFactory()->getMenu(MenuID::MENU_VOLUME));
    }
    else if(choice == 2) {
        game->setMenu(game->getMenuFactory()->getMenu(MenuID::MENU_RESOLUTION));
    }
    else {
        game->setMenu(game->getMenuFactory()->getMenu(MenuID::MENU_MAIN));
    }
    
    return true;
}
///-----Volume菜单------------------------
void VolumeMenu::show()
{
    cout << "\n\tSet Volume" << endl;
    cout << "input value(0-100)：";
}

bool VolumeMenu::doChoice(int choice)
{
    Game * game=Game::getInstance();
    if(choice >= 0 && choice <= 100) {
        game->setVolume(choice);
    }
    
    game->setMenu(game->getMenuFactory()->getMenu(MenuID::MENU_OPTION));
    return true;
}
///-----Resolution菜单------------------------
void ResolutionMenu::show()
{
    cout << "\n\tSet resolution" << endl;
    cout << "1. 640X320" << endl;
    cout << "2. 800X600" << endl;
    cout << "3. 1024X768" << endl;
    cout << " Your selected:";
}

bool ResolutionMenu::doChoice(int choice)
{
    Game * game=Game::getInstance();
    if(choice == 1) {
        game->setResolution(640, 320);
    }
    else if(choice == 2) {
        game->setResolution(800, 600);
    }
    else if(choice == 3) {
        game->setResolution(1024, 768);
    }
    else {
        game->setResolution(800, 600);
    }
    
    game->setMenu(game->getMenuFactory()->getMenu(MenuID::MENU_OPTION));
    return true;
}
///-------新增子类InternetMainMenu----------------------------------
void InternetMainMenu::show()
{
    cout << "\n\t" << "主菜单" << endl;
    cout << "1: New" << endl;
    cout << "2: Load" << endl;
    cout << "3: Save" << endl;
    cout << "4: Option" << endl;
    cout << "5: Play..." << endl;
    cout << "6: InternetPlay..." << endl;
    cout << "0: Exit" << endl;
    cout << " Your selected:";
}
bool InternetMainMenu::doChoice(int choice)
{
    //Game * game=Game::getInstance();
    if(choice == 6) {
        return true;
    }
    else {
        return MainMenu::doChoice(choice);
    }
}
///-------新增子类ExtOptionMenu----------------------------------
void ExtOptionMenu::show()
{
    cout << "\n\tSet options :" << endl;
    cout << "1.Set the value of Volume(0-100)" << endl;
    cout << "2.Set the resolution" << endl;
    cout << "3.Set mouse speed" << endl;
    cout << "0. Back" << endl;
    cout << " Your selected:";
}
bool ExtOptionMenu::doChoice(int choice)
{
    Game * game=Game::getInstance();
    if (choice ==3) {
        game->setMenu(game->getMenuFactory()->getMenu(MenuID::MENU_SPEED));
        return true;
    }else {
        return OptionMenu::doChoice(choice);
    }
}
///-------新增子类SpeedMenu----------------------------------
void SpeedMenu::show()
{
    cout << "\n\tSet speed :" << endl;
    cout << "1.Slow" << endl;
    cout << "2.Normal" << endl;
    cout << "3.Fast" << endl;
    cout << " Your selected:";
}
bool SpeedMenu::doChoice(int choice)
{
    Game * game=Game::getInstance();
    game->setSpeed(choice);
    game->setMenu(game->getMenuFactory()->getMenu(MenuID::MENU_OPTION));
    return true;
}

