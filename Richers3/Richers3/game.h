//
//  game.h
//  Richers3
//
//  Created by CQQ on 2017/10/8.
//  Copyright © 2017年 FatNerd. All rights reserved.
//

#ifndef game_h
#define game_h

class Map;
class Menu;
class MenuFactory;

class Game
{
public:
    static Game * getInstance();
    static void releaseGame();
protected:
    static Game * game;
protected:
    Game();
    Game(const Game&);
    Game& operator=(const Game&);
public:
    virtual ~Game();
    virtual void init(MenuFactory * fac);
    virtual void run();
    virtual void term();
public:
    void show();
    void createMap();
    void setMenu(Menu * menu);
    void setPlayersCount(int num);
    void loadRecord(int recID);
    void saveRecord(int recID);
    void setVolume(int vol);
    void setSpeed(int n) { }
    void setResolution(int xres,int yres);
    MenuFactory * getMenuFactory() const;
    Map * getMap() { return mapCur;}
protected:
private:
    MenuFactory * facMenu;
    Map  * mapCur;
    Menu * mnuCur;
    int    nCountPlayers;
    int    nVolume;
    int    nResolutionX;
    int    nResolutionY;
};

#endif /* game_h */
