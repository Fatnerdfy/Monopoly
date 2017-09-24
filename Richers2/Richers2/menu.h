//
//  menu.h
//  Richers2
//
//  Created by CQQ on 2017/9/24.
//  Copyright © 2017年 CQQ. All rights reserved.
//

#ifndef menu_h
#define menu_h

enum class MenuID {
    MENU_MAIN=0,
    MENU_PLAYERS=1,
    MENU_LOAD=2,
    MENU_SAVE=3,
    MENU_OPTION=4,
    MENU_VOLUME=5,
    MENU_RESOLUTION=6,
    MENU_COUNT=7
};

class Game;
class MenuFactory;
///----菜单的基类(抽象类)------------------------
class Menu
{
public:
    friend MenuFactory;
    static Menu * getInstance(MenuID menuid);
    static void   releaseAllMenus();
public:
    Menu() {}
    virtual ~Menu() {}
    bool process(Game * game);
protected:
    virtual void show( )=0;
    virtual int  getChoice( );
    virtual bool doChoice(int choice,Game * game)=0;
private:
    static Menu * menus[(int)MenuID::MENU_COUNT];
};
///------主菜单-----------------------------------
class MainMenu:public Menu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice,Game * game);
};

///------玩家人数菜单--------------------------------
class PlayersMenu:public Menu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice,Game * game);
};
///-------载入菜单----------------------------------
class LoadMenu: public Menu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice,Game * game);
};
///-------保存菜单----------------------------------
class SaveMenu: public Menu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice,Game * game);
};
///-------选项菜单----------------------------------
class OptionMenu: public Menu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice,Game * game);
};
///-------音量选项菜单----------------------------------
class VolumeMenu: public Menu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice,Game * game);
};
///-------分辨率选项菜单----------------------------------
class ResolutionMenu: public Menu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice,Game * game);
};
///-------菜单工厂-----------------------------------
class MenuFactory {
public:
    Menu * createMenu(int mid);
};

#endif /* menu_h */
