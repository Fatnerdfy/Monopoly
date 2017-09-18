//
//  menu.cpp
//  Richers1
//
//  Created by CQQ on 2017/9/18.
//  Copyright © 2017年 CQQ. All rights reserved.
//

#include "menu.h"

Menu::Menu() {
    submf = NULL;
    submenu = NULL;
}

Menu::~Menu() {
    if (submf!=NULL) delete submf;
    if (submenu!=NULL) delete submenu;
}

int Menu::getInput() {
    int input;
    cout << " Your selected:" ;
    cin >> input;
    cout << "Choice=" << input <<endl;
    return input;
}

void MainMenu::display() {
    cout << "        主菜单" << endl;
    cout << "1.New" << endl;
    cout << "2.Load" << endl;
    cout << "3.Save" << endl;
    cout << "4.Option" << endl;
    cout << "5.Play..." << endl;
    cout << "0.Exit" << endl;
}

void MainMenu::select(int n) {
    if (n==0) {
        return ;
    } else if (n==1) {
        submf = new NewMenuFactory;
    } else if (n==2) {
        submf = new LoadMenuFactory;
    } else if (n==3) {
        submf = new SaveMenuFactory;
    } else if (n==4) {
        submf = new OptionMenuFactory;
    } else if (n==5) {
        cout << "now is playing..." << endl;
        return ;
    }
    submenu = submf->createMenu();
    delete submf;
    submenu->display();
    submenu->select(getInput());
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
    if (n==0) {
        return ;
    } else {
        cout << "Set number of players = " << n << endl;
    }
}

void LoadMenu::display() {
    cout << "        Select the Record to be loaded(1-5)" << endl;
    cout << "1.1" << endl;
    cout << "2.2" << endl;
    cout << "3.3" << endl;
    cout << "4.4" << endl;
    cout << "5.5" << endl;
    cout << "0.Back" << endl;
}

void LoadMenu::select(int n) {
    if (n==0) {
        return ;
    } else {
        cout << "Loading record with id=" << n << endl;
    }
}

void SaveMenu::display() {
    cout << "        Select the Record to save(1-5)" << endl;
    cout << "1.1" << endl;
    cout << "2.2" << endl;
    cout << "3.3" << endl;
    cout << "4.4" << endl;
    cout << "5.5" << endl;
    cout << "0.Back" << endl;
}

void SaveMenu::select(int n) {
    if (n==0) {
        return ;
    } else {
        cout << "Save record with id=" << n << endl;
    }
}

void OptionMenu::display() {
    cout << "        Set options :" << endl;
    cout << "1.Set the value of Volume(1-100)" << endl;
    cout << "2.Set the resolution" << endl;
    cout << "0.Back" << endl;
}

void OptionMenu::select(int n) {
    if (n==0) {
        return ;
    } else if (n==1) {
        setVolume();
    } else if (n==2) {
        setResolution();
    }
    this->display();
    this->select(getInput());
}

void OptionMenu::setVolume() {
    cout << "        Set Volume" << endl;
    cout << "input value(0-100): ";
    int volume;
    cin >> volume;
    cout << "Choice=" << volume << endl;
    cout << "Set Volumn to " << volume << endl;
}

void OptionMenu::setResolution() {
    cout << "        Set resolution" << endl;
    cout << "1.640X320" << endl;
    cout << "2.800X600" << endl;
    cout << "3.1024X768" << endl;
    cout << " Your selected: ";
    int rno;
    cin >> rno;
    cout << "Choice=" << rno << endl;
    cout << "Set Resolution to ";
    if (rno==1) {
        cout << "640X320" << endl;
    } else if (rno==2) {
        cout << "800X600" <<endl;
    } else if (rno==3) {
        cout << "1024X768" << endl;
    }
}

Menu* MainMenuFactory::createMenu() {
    return new MainMenu;
}

Menu* NewMenuFactory::createMenu() {
    return new NewMenu;
}

Menu* LoadMenuFactory::createMenu() {
    return new LoadMenu;
}

Menu* SaveMenuFactory::createMenu() {
    return new SaveMenu;
}

Menu* OptionMenuFactory::createMenu() {
    return new OptionMenu;
}
