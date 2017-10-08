//
//  map.h
//  Richers3
//
//  Created by CQQ on 2017/10/8.
//  Copyright © 2017年 FatNerd. All rights reserved.
//

#ifndef map_h
#define map_h

#include "player.h"

class Block;
class ImpMap;
class Map
{
public:
    Map(int rs,int cs);
    virtual ~Map();
    void setBlock(int row,int col,Block * b);
    Block * getBlock(int row,int col);
    void show();
protected:
    ImpMap * imap;
};

class ImpMap {
public:
    ImpMap(int rs, int cs);
    virtual ~ImpMap();
    virtual void setBlock(int row, int col, Block * b);
    virtual Block * getBlock(int row, int col);
    virtual void show();
protected:
    int rows;
    int cols;
    Block *** blocks;
private:
};

class NewMap : public Map {
public:
    void enter(Player * p);
};

class NewImpMap : public ImpMap {
public:
    NewImpMap(int row, int col);
    virtual void show();
};

#endif /* map_h */
