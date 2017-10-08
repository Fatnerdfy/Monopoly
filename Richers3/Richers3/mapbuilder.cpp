//
//  mapbuilder.cpp
//  Richers3
//
//  Created by CQQ on 2017/10/8.
//  Copyright © 2017年 FatNerd. All rights reserved.
//

#include "mapbuilder.h"
#include "map.h"
#include "block.h"
#include "blockmgr.h"

void BasicMapBuilder::buildMap(int rs, int cs)
{
    aMap = new Map(rs, cs);
}

void BasicMapBuilder::buildBlock(BlockID type, int row, int col)
{
    BlockMgr * mgr = BlockMgr::getMgr();
    Block * block = mgr->createBlock(type);
    
    aMap->setBlock(row, col, block);
}
///------------------------------
MapDirector::MapDirector(MapBuilder * builder)
{
    this->builder = builder;
}

EasyMapDirector::EasyMapDirector(MapBuilder * builder)
: MapDirector(builder)
{
}

Map * EasyMapDirector::buildMap()
{
    static const int layout[5][5] = {
        {1, 1, 1, 1, 1},
        {2, 0, 0, 0, 2},
        {3, 0, 0, 0, 3},
        {4, 0, 0, 0, 4},
        {1, 1, 1, 1, 1},
    };
    
    builder->buildMap(5, 5);
    
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            builder->buildBlock((BlockID)layout[i][j], i, j);
        }
    }
    
    return builder->getMap();
}
///--------------
HardMapDirector::HardMapDirector(MapBuilder * builder)
: MapDirector(builder)
{
}

Map * HardMapDirector::buildMap()
{
    static const int layout[5][5] = {
        {1, 1, 1, 1, 1},
        {2, 0, 0, 0, 2},
        {3, 3, 3, 3, 3},
        {4, 0, 0, 0, 4},
        {1, 1, 1, 1, 1},
    };
    
    builder->buildMap(5, 5);
    
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            builder->buildBlock((BlockID)layout[i][j], i, j);
        }
    }
    
    return builder->getMap();
}

