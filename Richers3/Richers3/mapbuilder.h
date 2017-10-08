//
//  mapbuilder.h
//  Richers3
//
//  Created by CQQ on 2017/10/8.
//  Copyright © 2017年 FatNerd. All rights reserved.
//

#ifndef mapbuilder_h
#define mapbuilder_h

#include "global.h"
class Map;
class MapBuilder
{
public:
    MapBuilder(){}
    virtual ~MapBuilder(){}
    virtual void buildMap(int rs, int cs) = 0;
    virtual Map * getMap() { return aMap;}
    virtual void buildBlock(BlockID type, int row, int col) = 0;
protected:
    Map * aMap;
private:
};

class BasicMapBuilder: public MapBuilder
{
public:
    BasicMapBuilder(){}
    virtual ~BasicMapBuilder(){}
    virtual void buildMap(int rs, int cs);
    virtual Map * getMap() { return aMap;}
    virtual void buildBlock(BlockID type, int row, int col);
};

class MapDirector
{
public:
    MapDirector(MapBuilder * builder);
    virtual ~MapDirector() {}
    virtual Map * buildMap()=0;
protected:
    MapBuilder * builder;
};
class EasyMapDirector:public MapDirector
{
public:
    EasyMapDirector(MapBuilder * builder);
    virtual ~EasyMapDirector() {}
    virtual Map * buildMap();
};
class HardMapDirector:public MapDirector
{
public:
    HardMapDirector(MapBuilder * builder);
    virtual ~HardMapDirector() {}
    virtual Map * buildMap();
};

#endif /* mapbuilder_h */
