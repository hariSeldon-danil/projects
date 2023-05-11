#ifndef __IMONSTER_HPP__
#define __IMONSTER_HPP__

#include <vector>

class IMonster
{
    public:
    virtual void ResetMonster() = 0;
    virtual const std::vector<std::pair<int, int> >& GetMonsterBody() const = 0;
    virtual const std::pair<int, int> GetHead() const = 0;
    virtual const int GetBodyLinks() const = 0;
    virtual bool MoveUp(std::pair<int, int>& prey_position) = 0;
    virtual bool MoveDown(std::pair<int, int>& prey_position) = 0;
    virtual bool MoveLeft(std::pair<int, int>& prey_position) = 0;
    virtual bool MoveRight(std::pair<int, int>& prey_position) = 0;
};


#endif  //__IMONSTER_HPP__