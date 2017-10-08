//
//  menus.h
//  Richers3
//
//  Created by CQQ on 2017/10/8.
//  Copyright © 2017年 FatNerd. All rights reserved.
//

#ifndef menus_h
#define menus_h

class Game;

///----菜单的基类(抽象类)------------------------
class Menu
{
public:
    Menu() {}
    virtual ~Menu() {}
    bool process() ;
protected:
    virtual void show( )=0;
    virtual int  getChoice( );
    virtual bool doChoice(int choice)=0;
    
};
///------主菜单-----------------------------------
class MainMenu:public Menu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice);
};

///------玩家人数菜单--------------------------------
class PlayersMenu:public Menu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice);
};
///-------载入菜单----------------------------------
class LoadMenu: public Menu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice);
};
///-------保存菜单----------------------------------
class SaveMenu: public Menu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice);
};
///-------选项菜单----------------------------------
class OptionMenu: public Menu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice);
};
///-------音量选项菜单----------------------------------
class VolumeMenu: public Menu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice);
};
///-------分辨率选项菜单----------------------------------
class ResolutionMenu: public Menu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice);
};

///-------新增子类InternetMainMenu----------------------------------
class InternetMainMenu:public MainMenu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice);
};
///-------新增子类ExtOptionMenu----------------------------------
class ExtOptionMenu:public OptionMenu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice);
};
///-------新增子类SpeedMenu----------------------------------
class SpeedMenu:public Menu
{
protected:
    virtual void show( );
    virtual bool doChoice(int choice);
};

#endif /* menus_h */
