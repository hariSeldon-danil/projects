#ifndef __LEVEL_HPP__
#define __LEVEL_HPP__

#include <iostream>

#include "ILevel.hpp"
#include "Board.hpp"

class Level : public ILevel
{
    private:
    bool m_playing;
    int m_rows;
    int m_cols;
    int m_base_score;
    int m_limit;
    IBoard *m_board;
    IScore *m_level_score;

    int ListenForInput();
    char GetInput();
    bool RespondToInput(char input);
    
    public:
    Level(int height, int width, int base_score, int limit);
    ~Level();
    //will listen for input and execute accordingly
    bool StartLevel();
    inline const IScore *GetLevelScore() const;

    //end level and display points
    void EndLevel();
};

const IScore *Level::GetLevelScore() const
{
    return m_level_score;
}

#endif //__LEVEL_HPP__