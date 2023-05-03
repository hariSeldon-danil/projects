#include <iostream>
#include <stdlib.h>  //system("cls")
#include <unistd.h> //sleep

#include <ctime>    //seed
#include <cstdlib>  //rand

#include "Board.hpp"

Board::~Board()
{
    for(auto it : m_table)
    {
        it.clear();
    }
    delete m_prey;
}

void Board::InitTable()
{
    //set table
        m_table = std::vector<std::vector<char>>(m_rows, std::vector<char>(m_cols, ' '));

        //fill table's borders
        //top and lower rows
        for(int i = 0; i < m_cols -1; ++i)
        {
            m_table[0][i] = '*';
            m_table[m_rows -1][i] = '*';
        }
        for(int i = 1; i < m_rows; ++i)
        {
            m_table[i][0] = '*';
            m_table[i][m_cols - 2] = '*';
        }
        //fill the '\n' at the end of every row
        for(int i = 0; i < m_rows; ++i)
        {
            m_table[i][m_cols-1] = '\n';
        }
}

void Board::PlacePrey(IPrey* prey)
{
    srand(time(0));
    int row = 1+ (rand() % (m_rows-3));
    int col = 1+ (rand() % (m_cols-4));
    prey->SetPosition(row, col);
}

IMonster *Board::GetMonster()
{
    return m_snake;
}

IPrey *Board::GetPrey()
{
    return m_prey;
}

void Board::CheckFood()
{
    std::pair<int, int> prey_position = m_prey->GetPosition();
    //snake position
    std::pair<int, int> snake_head = m_snake->GetHead();

    if(prey_position == snake_head)
    {
        m_snake->EatAndGrow();
        PlacePrey(m_prey);
    }
}

void Board::DrawTable()
{
     
    //clear table
    system("clear");

    std::cout <<
    "*   up press w\t\t\t*\n*   down press s\t\t*\n*   left press a\t\t*\n*   right press d\t\t*\n* 'q' to quit\t\t*\n";

    std::pair<int, int> prey_position = m_prey->GetPosition();
    //snake position
    std::vector<std::vector<char>> snake = m_snake->GetMonsterBody();
    
    //print
    std::cout << std::endl;
    for(int i = 0; i < m_rows; ++i)
    {
        for(int j = 0; j < m_cols; ++j)
        {
            if(i > 0 && i < m_rows -1 && j > 0 && j < m_cols -3)
            {
                if(i-1 == prey_position.first && j-1 == prey_position.second && snake[i-1][j-1] == ' ')
                {
                    std::cout << '$';
                }
                else
                {
                    std::cout << snake[i-1][j-1];   
                }
            }
            else
            {
                std::cout << m_table[i][j];
            }
        }
    }
    std::cout << std::endl;
    fflush(stdin);
}
