#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <vector>
//#include <thread>

#include "IBoard.hpp"
#include "Snake.hpp"
#include "Prey.hpp"
#include "IMonster.hpp"

class Board : public IBoard
{
    private:
    int m_rows;
    int m_cols;
    std::vector<std::vector<char>> m_table;
    IPrey *m_prey;
    IMonster *m_snake;
    //std::thread m_thread;


    void InitTable();
    void PlacePrey(IPrey* prey);

    public:
    Board(int height, int width): 
                    m_rows(height),
                    m_cols(width),
                    m_prey(new Prey),
                    m_snake(new Snake(height -2, width -3))
    {
        InitTable();
        PlacePrey(m_prey);
        //m_thread = std::thread(&Board::DrawTable, this);
    }
    ~Board();
    IMonster *GetMonster();
    IPrey *GetPrey();
    void DrawTable();
    void CheckFood();
};


#endif //__BOARD_HPP__