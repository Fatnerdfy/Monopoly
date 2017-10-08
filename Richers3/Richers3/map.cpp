//
//  map.cpp
//  Richers3
//
//  Created by CQQ on 2017/10/8.
//  Copyright © 2017年 FatNerd. All rights reserved.
//

#include <iostream>
using namespace std;

#include "map.h"
#include "block.h"

Map::Map(int rs, int cs)
{
    //ctor
    imap = new ImpMap(rs, cs);
}

Map::~Map()
{
    //dtor
    delete imap;
    imap = nullptr;
}

void Map::setBlock(int row, int col, Block * b)
{
    imap->setBlock(row, col, b);
}

Block * Map::getBlock(int row, int col)
{
    return imap->getBlock(row, col);
}

void Map::show()
{
    imap->show();
}

///-------------------ImpMap------------------
ImpMap::ImpMap(int rs, int cs) {
    rows = rs;
    cols = cs;
    
    blocks = new Block ** [rows];
    
    for(int i = 0; i < rows; ++i) {
        blocks[i] = new Block*[cols];
    }
    
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j) {
            blocks[i][j] = nullptr;
        }
}

ImpMap::~ImpMap() {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            delete blocks[i][j];
            blocks[i][j] = nullptr;
        }
    }
    
    for(int i = 0; i < rows; ++i) {
        delete[] blocks[i];
    }
    
    delete[] blocks;
    blocks = nullptr;
}

void ImpMap::setBlock(int row, int col, Block * b) {
    blocks[row][col] = b;
}

Block * ImpMap::getBlock(int row, int col) {
    return blocks[row][col];
}

void ImpMap::show() {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            Block * block = blocks[i][j];
            if (block)
                cout<<block->getName();
            else
                cout<<" ";
        }
        cout<<endl;
    }
}

