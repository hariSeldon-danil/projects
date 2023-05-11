#include <iostream>
#include <stdlib.h>  //system("cls")
#include <unistd.h> //sleep

#include <ctime>    //seed
#include <cstdlib>  //rand
#include <stdio.h>  //fflush

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
        m_table = std::vector<std::vector<char> >(m_rows, std::vector<char>(m_cols, ' '));

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

void Board::ClearTable(std::vector<std::pair<int, int> >& snake_body)
{
    for(auto it : snake_body)
    {
        m_table[it.first][it.second] = ' ';
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

void Board::DrawTable()
{
    //clear table
    system("clear");

    std::cout <<
    "*\tup press w\t\t\t*\n*\tdown press s\t\t*\n*\tleft press a\t\t*\n*\tright press d\t\t*\n*\tquit press q\t\t*\n";

    //place prey
    std::pair<int, int> prey_position = m_prey->GetPosition();
    m_table[prey_position.first][prey_position.second] = '$';
    
    //place snake head
    std::pair<int, int> head = m_snake->GetHead();
    m_table[head.first][head.second] = '@';

    //place snake body
    std::vector<std::pair<int, int> > snake_body = m_snake->GetMonsterBody();
    for (auto it : snake_body)
    {
        m_table[it.first][it.second] = '#';
    }
    
    //print
    std::cout << std::endl;
    for(int i = 0; i < m_rows; ++i)
    {
        for(int j = 0; j < m_cols; ++j)
        {
            std::cout << m_table[i][j];
        }
    }
    std::cout << std::endl;
    
    fflush(stdin);
    
    //clear table
    m_table[prey_position.first][prey_position.second] = ' ';
    m_table[head.first][head.second] = ' ';
    ClearTable(snake_body);

}
