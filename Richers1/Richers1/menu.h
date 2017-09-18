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
    Menu();
    int getInput();
    virtual ~Menu();
    virtual void display() = 0;
    virtual void select(int n) = 0;
};

class MainMenu : public Menu {

public:
    virtual ~MainMenu(){}
    virtual void display();
    virtual void select(int n);
};


class NewMenu : public Menu {
public:
    virtual ~NewMenu(){}
    virtual void display();
    virtual void select(int n);
};

class LoadMenu : public Menu {
public:
    virtual ~LoadMenu(){}
    virtual void display();
    virtual void select(int n);
};

class SaveMenu : public Menu {
public:
    virtual ~SaveMenu(){}
    virtual void display();
    virtual void select(int n);
};

class OptionMenu : public Menu {
private:
    void setVolume();
    void setResolution();
public:
    virtual ~OptionMenu(){}
    virtual void display();
    virtual void select(int n);
};

class MenuFactory {
public:
    virtual ~MenuFactory(){}
    virtual Menu* createMenu() = 0;
};

class MainMenuFactory : public MenuFactory {
public:
    virtual ~MainMenuFactory(){}
    virtual Menu* createMenu();
    
};

class NewMenuFactory : public MenuFactory {
public:
    virtual ~NewMenuFactory(){}
    virtual Menu* createMenu();
};

class LoadMenuFactory : public MenuFactory {
public:
    virtual ~LoadMenuFactory(){}
    virtual Menu* createMenu();
};

class SaveMenuFactory : public MenuFactory {
public:
    virtual ~SaveMenuFactory(){}
    virtual Menu* createMenu();
};

class OptionMenuFactory : public MenuFactory {
public:
    virtual ~OptionMenuFactory(){}
    virtual Menu* createMenu();
};

#endif /* menu_h */
