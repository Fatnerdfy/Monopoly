//
//  map.h
//  Richers3
//
//  Created by CQQ on 2017/10/8.
//  Copyright © 2017年 FatNerd. All rights reserved.
//

#ifndef map_h
#define map_h

class Block;
class Map
{
public:
    Map(int rs,int cs);
    virtual ~Map();
    void setBlock(int row,int col,Block * b);
    Block * getBlock(int row,int col);
    void show();
protected:
    int rows;
    int cols;
    Block *** blocks;
private:
};

#endif /* map_h */
