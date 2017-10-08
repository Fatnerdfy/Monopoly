//
//  menufactory.h
//  Richers3
//
//  Created by CQQ on 2017/10/8.
//  Copyright © 2017年 FatNerd. All rights reserved.
//

#ifndef menufactory_h
#define menufactory_h

#include "global.h"
class Menu;

class MenuFactory
{
public:
    static MenuFactory * getFactory();
    static void releaseFactory();
protected:
    static MenuFactory * fac;
protected:
    MenuFactory();
    MenuFactory(const MenuFactory &);
    MenuFactory & operator=(const MenuFactory &);
public:
    virtual ~MenuFactory();
    virtual Menu * getMenu(MenuID id);
protected:
    Menu * menus[(int)MenuID::MENU_COUNT];
private:
};


class NetMenuFactory: public MenuFactory
{
public:
    static MenuFactory * getFactory();
protected:
    NetMenuFactory(){}
    NetMenuFactory(const NetMenuFactory &);
    NetMenuFactory & operator=(const NetMenuFactory &);
public:
    virtual Menu * getMenu(MenuID id);
};

class SpeedMenuFactory: public NetMenuFactory
{
public:
    static MenuFactory * getFactory();
protected:
    SpeedMenuFactory(){}
    SpeedMenuFactory(const SpeedMenuFactory &);
    SpeedMenuFactory & operator=(const SpeedMenuFactory &);
public:
    virtual Menu * getMenu(MenuID id);
};

#endif /* menufactory_h */
