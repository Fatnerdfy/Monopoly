//
//  block.h
//  Richers3
//
//  Created by CQQ on 2017/10/8.
//  Copyright © 2017年 FatNerd. All rights reserved.
//

#ifndef block_h
#define block_h

class Block
{
public:
    Block();
    virtual ~Block();
    virtual char getName() const = 0;
    virtual Block * clone() = 0;
protected:
private:
};

class BlockA: public Block
{
public:
    virtual char getName() const {return 'A';}
    virtual Block * clone() { return new BlockA;}
};
class BlockB: public Block
{
public:
    virtual char getName() const {return 'B';}
    virtual Block * clone() { return new BlockB;}
};
class BlockC: public Block
{
public:
    virtual char getName() const {return 'C';}
    virtual Block * clone() { return new BlockC;}
};
class BlockD: public Block
{
public:
    virtual char getName() const {return 'D';}
    virtual Block * clone() { return new BlockD;}
};

class BlockE: public Block
{
public:
    virtual char getName() const {return 'E';}
    virtual Block * clone() { return new BlockE;}
};

class BlockF: public Block
{
public:
    virtual char getName() const {return 'F';}
    virtual Block * clone() { return new BlockF;}
};

#endif /* block_h */
