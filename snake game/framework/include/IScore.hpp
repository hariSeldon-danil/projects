#ifndef __ISCORE_HPP__
#define __ISCORE_HPP__

class IScore
{
    public:
    virtual void DisplayScore() const = 0;
    inline virtual const int GetScore() const =0;
    virtual void SetScore(int x) = 0;
    virtual void AddPoints(int points) = 0;
};



#endif  //__ISCORE_HPP__