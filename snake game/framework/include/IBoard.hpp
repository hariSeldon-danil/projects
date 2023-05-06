#ifndef __IBOARD_HPP__
#define __IBOARD_HPP__

#include "IMonster.hpp"
#include "IPrey.hpp"

class IBoard
{
    
    public:
    void virtual DrawTable() = 0;
    virtual IMonster *GetMonster() = 0;
    virtual IPrey *GetPrey() = 0;
    virtual void CheckFood() = 0;
};


#endif //__IBOARD_HPP__