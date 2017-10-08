//
//  menufactory.cpp
//  Richers3
//
//  Created by CQQ on 2017/10/8.
//  Copyright © 2017年 FatNerd. All rights reserved.
//

#include "menufactory.h"
#include "menus.h"
#include "global.h"

MenuFactory * MenuFactory::fac = nullptr;
MenuFactory * MenuFactory::getFactory()
{
    if(fac == nullptr) {
        fac = new MenuFactory;
    }
    
    return fac;
}
void MenuFactory::releaseFactory()
{
    delete fac;
    fac = nullptr;
}

MenuFactory::MenuFactory()
{
    //ctor
    for(int id = (int)MenuID::MENU_MAIN; id < (int)MenuID::MENU_COUNT; ++id) {
        menus[id] = nullptr;
    }
}

MenuFactory::~MenuFactory()
{
    //dtor
    for(int id = (int)MenuID::MENU_MAIN; id < (int)MenuID::MENU_COUNT; ++id) {
        delete menus[id];
        menus[id] = nullptr;
    }
}
Menu * MenuFactory::getMenu(MenuID menuid)
{
    int id = (int)menuid;
    
    if(menus[id]) { return menus[id]; }
    
    switch(menuid) {
        case MenuID::MENU_MAIN:
            menus[id] = new MainMenu;
            break;
            
        case MenuID::MENU_PLAYERS:
            menus[id] = new PlayersMenu;
            break;
            
        case MenuID::MENU_LOAD:
            menus[id] = new LoadMenu;
            break;
            
        case MenuID::MENU_SAVE:
            menus[id] = new SaveMenu;
            break;
            
        case MenuID::MENU_OPTION:
            menus[id] = new OptionMenu;
            break;
            
        case MenuID::MENU_VOLUME:
            menus[id] = new VolumeMenu;
            break;
            
        case MenuID::MENU_RESOLUTION:
            menus[id] = new ResolutionMenu;
            break;
            
        default:
            //默认返回主菜单
            id = (int)MenuID::MENU_MAIN;
            
            if(menus[id] == nullptr) {
                menus[id] = new MainMenu;
            }
            
            break;
    }
    
    return menus[id];
}

///----------------
MenuFactory * NetMenuFactory::getFactory()
{
    if(fac == nullptr) {
        fac = new NetMenuFactory;
    }
    
    return fac;
}

Menu * NetMenuFactory::getMenu(MenuID menuid)
{
    int id = (int)menuid;
    
    if(menus[id]) { return menus[id]; }
    
    switch(menuid) {
        case MenuID::MENU_PLAYERS:
        case MenuID::MENU_LOAD:
        case MenuID::MENU_SAVE:
        case MenuID::MENU_OPTION:
        case MenuID::MENU_VOLUME:
        case MenuID::MENU_RESOLUTION:
            menus[id] = MenuFactory::getMenu(menuid);
            break;
        case MenuID::MENU_MAIN:
        default:
            //默认返回主菜单
            id = (int)MenuID::MENU_MAIN;
            
            if(menus[id] == nullptr) {
                menus[id] = new InternetMainMenu;
            }
            break;
    }
    
    return menus[id];
}
///-----------
MenuFactory * SpeedMenuFactory::getFactory()
{
    if(fac == nullptr) {
        fac = new SpeedMenuFactory;
    }
    return fac;
}
Menu * SpeedMenuFactory::getMenu(MenuID menuid)
{
    int id = (int)menuid;
    
    if(menus[id]) { return menus[id]; }
    
    switch(menuid) {
        case MenuID::MENU_OPTION:
            menus[id] = new ExtOptionMenu;
            break;
        case MenuID::MENU_SPEED:
            menus[id] = new SpeedMenu;
            break;
        default:
            //默认返回主菜单
            menus[id] = NetMenuFactory::getMenu(menuid);
            break;
    }
    
    return menus[id];
}

