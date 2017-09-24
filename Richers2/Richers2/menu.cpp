//
//  menu.cpp
//  Richers2
//
//  Created by CQQ on 2017/9/24.
//  Copyright © 2017年 CQQ. All rights reserved.
//

#include <iostream>
using namespace std;
#include "menu.h"
#include "game.h"

Menu * Menu::menus[(int)MenuID::MENU_COUNT] =
{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

///Lazy实例化各菜单单例
Menu * Menu::getInstance(MenuID menuid)
{
    int id = (int)menuid;
    MenuFactory * mf = new MenuFactory;
    return mf->createMenu(id);
}

///回收各菜单实例
void Menu::releaseAllMenus()
{
    for(int id = (int)MenuID::MENU_MAIN; id < (int)MenuID::MENU_COUNT; ++id) {
        delete menus[id];
        menus[id] = nullptr;
    }
}
///菜单的主处理过程
bool Menu::process(Game * game)
{
    show();
    int choice = getChoice();
    cout<<"Choice="<<choice<<endl;
    return doChoice(choice, game);
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
    cout << "6: InternetPlay" << endl;
    cout << "0: Exit" << endl;
    cout << " Your selected:";
}

bool MainMenu::doChoice(int choice, Game * game)
{
    switch(choice) {
        case 1:
            game->setMenu(Menu::getInstance(MenuID::MENU_PLAYERS));
            return true;
            
        case 2:
            game->setMenu(Menu::getInstance(MenuID::MENU_LOAD));
            return true;
            
        case 3:
            game->setMenu(Menu::getInstance(MenuID::MENU_SAVE));
            return true;
            
        case 4:
            game->setMenu(Menu::getInstance(MenuID::MENU_OPTION));
            return true;
            
        case 5:
            cout << "now is playing..." << endl;
            return true;
        case 6:
            cout << "Internet Playing..." << endl;
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

bool PlayersMenu::doChoice(int choice, Game * game)
{
    if(choice >= 2 && choice <= 8) {
        game->setPlayersCount(choice);
    }
    
    game->setMenu(Menu::getInstance(MenuID::MENU_MAIN));
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

bool LoadMenu::doChoice(int choice, Game * game)
{
    if(choice >= 1 && choice <= 5) {
        game->loadRecord(choice);
    }
    
    game->setMenu(Menu::getInstance(MenuID::MENU_MAIN));
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

bool SaveMenu::doChoice(int choice, Game * game)
{
    if(choice >= 1 && choice <= 5) {
        game->saveRecord(choice);
    }
    
    game->setMenu(Menu::getInstance(MenuID::MENU_MAIN));
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

bool OptionMenu::doChoice(int choice, Game * game)
{
    if(choice == 1) {
        game->setMenu(Menu::getInstance(MenuID::MENU_VOLUME));
    }
    else if(choice == 2) {
        game->setMenu(Menu::getInstance(MenuID::MENU_RESOLUTION));
    }
    else {
        game->setMenu(Menu::getInstance(MenuID::MENU_MAIN));
    }
    
    return true;
}
///-----Volume菜单------------------------
void VolumeMenu::show()
{
    cout << "\n\tSet Volume" << endl;
    cout << "input value(0-100)：";
}

bool VolumeMenu::doChoice(int choice, Game * game)
{
    if(choice >= 0 && choice <= 100) {
        game->setVolume(choice);
    }
    
    game->setMenu(Menu::getInstance(MenuID::MENU_OPTION));
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

bool ResolutionMenu::doChoice(int choice, Game * game)
{
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
    
    game->setMenu(Menu::getInstance(MenuID::MENU_OPTION));
    return true;
}

Menu * MenuFactory::createMenu(int mid) {
    if(Menu::menus[mid]) { return Menu::menus[mid]; }
    
    switch(mid) {
        case 0:
            Menu::menus[mid] = new MainMenu;
            break;
            
        case 1:
            Menu::menus[mid] = new PlayersMenu;
            break;
            
        case 2:
            Menu::menus[mid] = new LoadMenu;
            break;
            
        case 3:
            Menu::menus[mid] = new SaveMenu;
            break;
            
        case 4:
            Menu::menus[mid] = new OptionMenu;
            break;
            
        case 5:
            Menu::menus[mid] = new VolumeMenu;
            break;
            
        case 6:
            Menu::menus[mid] = new ResolutionMenu;
            break;
            
        default:
            //默认返回主菜单
            mid = (int)MenuID::MENU_MAIN;
            
            if(Menu::menus[mid] == nullptr) {
                Menu::menus[mid] = new MainMenu;
            }
            
            break;
    }
    
    return Menu::menus[mid];
}
