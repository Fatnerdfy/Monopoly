//
//  menu.h
//  Richers1
//
//  Created by CQQ on 2017/9/18.
//  Copyright © 2017年 CQQ. All rights reserved.
//

#ifndef menu_h
#define menu_h
#include <iostream>

using namespace std;

class MenuFactory;

class Menu {
    
public:
    Menu* submenu;
    MenuFactory* submf;
    virtual ~Menu();
    virtual void display() = 0;
    virtual void select(int n) = 0;
};

class MainMenu : public Menu {

public:
    virtual ~MainMenu();
    virtual void display();
    virtual void select(int n);
};


class NewMenu : public Menu {
public:
    virtual ~NewMenu();
    virtual void display();
    virtual void select(int n);
};


class MenuFactory {
public:
    virtual ~MenuFactory(){};
    virtual Menu* createMenu() = 0;
};


class MainMenuFactory : public MenuFactory {
public:
    virtual ~MainMenuFactory(){};
    virtual Menu* createMenu();
    
};


class NewMenuFactory : public MenuFactory {
public:
    virtual ~NewMenuFactory(){};
    virtual Menu* createMenu();
};

#endif /* menu_h */
