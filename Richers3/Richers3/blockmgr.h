//
//  blockmgr.h
//  Richers3
//
//  Created by CQQ on 2017/10/8.
//  Copyright © 2017年 FatNerd. All rights reserved.
//

#ifndef blockmgr_h
#define blockmgr_h

#include "global.h"
class Block;
class BlockMgr
{
public:
    static BlockMgr * getMgr();
    static void releaseMgr();
protected:
    static BlockMgr * mgr;
protected:
    BlockMgr();
    BlockMgr(const BlockMgr&);
    BlockMgr& operator=(const BlockMgr&);
public:
    virtual ~BlockMgr();
    virtual Block * createBlock(BlockID id);
    void setPrototy(BlockID id,Block * b);
protected:
    Block * prototyBlocks[(int)BlockID::BLOCK_COUNT];
private:
};

#endif /* blockmgr_h */
