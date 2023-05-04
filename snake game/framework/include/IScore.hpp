#ifndef __ISCORE_HPP__
#define __ISCORE_HPP__

class IScore
{
    private:
    int m_score;

    public:
    virtual void DisplayScore() const = 0;
    inline virtual const int GetScore() const = 0;
    virtual void SetScore(int x) = 0;
};

const int IScore::GetScore() const
{
    return m_score;
}


#endif  //__ISCORE_HPP__