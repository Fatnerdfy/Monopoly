//
//  game.h
//  Richers2
//
//  Created by CQQ on 2017/9/24.
//  Copyright © 2017年 CQQ. All rights reserved.
//

#ifndef game_h
#define game_h

class Menu;
class GameFactory;
class Game
{
public:
    friend GameFactory;
    ~Game();
    void init();
    void run();
    void term();
    static Game * getInstance();
public:
    void setMenu(Menu * menu);
    void setPlayersCount(int num);
    void loadRecord(int recID);
    void saveRecord(int recID);
    void setVolume(int vol);
    void setResolution(int xres,int yres);
protected:
    Game();
private:
    static Game * game;
    Menu * mnuCur;
    int    nCountPlayers;
    int    nVolume;
    int    nResolutionX;
    int    nResolutionY;
};

class GameFactory {
public:
    Game * createGame(int gid);
};

#endif /* game_h */
