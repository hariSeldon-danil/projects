#ifndef __ILEVEL_HPP__
#define __ILEVEL_HPP__

#include "IScore.hpp"

class ILevel
{  
    public:
    virtual bool StartLevel() = 0;
    virtual void EndLevel() = 0;
    virtual const IScore *GetLevelScore() const = 0;
    virtual void ResetLevel() = 0;
};

#endif //__ILEVEL_HPP__