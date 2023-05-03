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
    IBoard *m_board;

    int ListenForInput();
    char GetInput();
    bool RespondToInput(char input);
    
    public:
    Level(int height, int width);
    ~Level();
    //will listen for input and execute accordingly
    bool StartLevel();

    //end level and display points
    void EndLevel();
};

#endif //__LEVEL_HPP__