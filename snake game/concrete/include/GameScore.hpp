#ifndef __GAMESCORE_HPP__
#define __GAMESCORE_HPP__

#include "IScore.hpp"

class GameScore : public IScore
{
private:
    int m_level_score;
public:
    GameScore(int base_score);
    void DisplayScore() const;
    inline const int GetScore() const;
    inline void SetScore(int x);
    inline void AddPoints(int points);
};

const int GameScore::GetScore() const
{
    return m_level_score;
}

void GameScore::SetScore(int x)
{
    m_level_score = x;
}

void GameScore::AddPoints(int points)
{
    m_level_score += points;
}

#endif  //__GAMESCORE_HPP__