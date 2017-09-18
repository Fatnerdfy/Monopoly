//
//  menu.cpp
//  Richers1
//
//  Created by CQQ on 2017/9/18.
//  Copyright © 2017年 CQQ. All rights reserved.
//

#include "menu.h"

Menu::~Menu() {
    delete submf;
    delete submenu;
}

MainMenu::~MainMenu() {
    
}

void MainMenu::display() {
    cout << "1.New" << endl;
    cout << "2.Load" << endl;
    cout << "3.Save" << endl;
    cout << "4.Option" << endl;
    cout << "5.Play..." << endl;
    cout << "0.Exit" << endl;
}

void MainMenu::select(int n) {
    if (n==1) {
        submf = new NewMenuFactory;
        submenu = submf->createMenu();
        delete submf;
    }
}

NewMenu::~NewMenu() {
    
}

void NewMenu::display() {
    cout << "        Set number of players(2-8)" << endl;
    cout << "2.2" << endl;
    cout << "3.3" << endl;
    cout << "4.4" << endl;
    cout << "5.5" << endl;
    cout << "6.6" << endl;
    cout << "7.7" << endl;
    cout << "8.8" << endl;
    cout << "0.Back" << endl;
}

void NewMenu::select(int n) {
    cout << "Set number of players = " << n << endl;
}


Menu* MainMenuFactory::createMenu() {
    return new MainMenu;
}

Menu* NewMenuFactory::createMenu() {
    return new NewMenu;
}
