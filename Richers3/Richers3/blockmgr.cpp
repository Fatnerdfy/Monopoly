//
//  blockmgr.cpp
//  Richers3
//
//  Created by CQQ on 2017/10/8.
//  Copyright © 2017年 FatNerd. All rights reserved.
//

#include "blockmgr.h"
#include "block.h"

BlockMgr * BlockMgr::mgr =nullptr;
BlockMgr * BlockMgr::getMgr()
{
    if (mgr ==nullptr)
        mgr = new BlockMgr;
    return mgr;
}


void BlockMgr::releaseMgr()
{
    delete mgr;
    mgr = nullptr;
}

BlockMgr::BlockMgr()
{
    //ctor
    for(int i=0;i<(int)BlockID::BLOCK_COUNT;++i)
        prototyBlocks[i] = nullptr;
    setPrototy(BlockID::BLOCK_A,new BlockA);
    setPrototy(BlockID::BLOCK_B,new BlockB);
    setPrototy(BlockID::BLOCK_C,new BlockC);
    setPrototy(BlockID::BLOCK_D,new BlockD);
}

BlockMgr::~BlockMgr()
{
    //dtor
    for(int i=0;i<(int)BlockID::BLOCK_COUNT;++i){
        delete  prototyBlocks[i];
        prototyBlocks[i] = nullptr;
    }
}

void BlockMgr::setPrototy(BlockID id,Block * b)
{
    delete prototyBlocks[(int)id];
    prototyBlocks[(int)id] = b;
}

Block * BlockMgr::createBlock(BlockID id)
{
    if(id==BlockID::BLOCK_NULL || id>=BlockID::BLOCK_COUNT)
        return nullptr;
    else
        return prototyBlocks[(int)id]->clone();
}

