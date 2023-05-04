#ifndef __LEVELSCORE_HPP__
#define __LEVELSCORE_HPP__

#include "IScore.hpp"

class LevelScore : public IScore
{
private:
    int m_level_score;
public:
    LevelScore(int base_score);
    void DisplayScore() const;
    inline const int GetScore() const;
    inline void SetScore(int x);
    inline void AddPoints(int points);
};

const int LevelScore::GetScore() const
{
    return m_level_score;
}

void LevelScore::SetScore(int x)
{
    m_level_score = x;
}

void LevelScore::AddPoints(int points)
{
    m_level_score += points;
}

#endif  //__LEVELSCORE_HPP__