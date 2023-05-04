#include <iostream>

#include "Snake.hpp"

Snake::Snake(int height, int width):
        m_body_links(1),
        m_rows(height),
        m_cols(width),
        m_head(std::make_pair<int, int>(height /2, width/2)),   //place snake head at center
        m_tail(std::make_pair<int, int>(height /2+1, width/2))    //tail lower than head
{
    m_snake = std::vector<std::vector<char>>(height, std::vector<char>(width,' '));
    m_snake[m_head.first][m_head.second] = '@';
    m_snake[m_tail.first][m_tail.second] = '#';
}

Snake::~Snake()
{
    for(auto it : m_snake)
    {
        it.clear();
    }
}

void Snake::EatAndGrow()
{
    if(m_tail.second < m_cols)
    {
        ++m_tail.second;
        m_snake[m_tail.first][m_tail.second] = '#';
    }
    else
    {
        ++m_tail.first;
        m_snake[m_tail.first][m_tail.second] = '#';
    }
    ++m_body_links;
}

void Snake::UpdateTail()
{
    //tail goes up
    if(m_tail.first > 0 && m_snake[m_tail.first - 1][m_tail.second] == '#')
    {
        --m_tail.first;
    }

    //tail goes down
    else if(m_tail.first < m_rows-1 && m_snake[m_tail.first + 1][m_tail.second] == '#')
    {
        ++m_tail.first;
    }

    //tail goes left
    else if(m_tail.second > 0 && m_snake[m_tail.first][m_tail.second -1] == '#')
    {
        --m_tail.second;
    }

    //tail goes right
    else if(m_tail.second < m_cols -1 && m_snake[m_tail.first][m_tail.second +1] == '#')
    {
        ++m_tail.second;
    }
}

bool Snake::MoveUp()
{
    //check head not touching border nor self
    if(m_head.first == 0 || m_snake[m_head.first -1][m_head.second] == '#')
    {
        return false;
    }
    else    //move snake and update head and tail
    {
        int x = m_head.first;
        int y = m_head.second;
        m_snake[m_tail.first][m_tail.second] = ' ';
        //where head was- body is :)
        m_snake[m_head.first][m_head.second] = '#';
        //update head
        --m_head.first;
        //set head
        m_snake[m_head.first][m_head.second] = '@';
        
        //tail

        //update tail
        if(m_body_links > 1)
        {
            UpdateTail();
        }
        else
        {
            m_tail = std::make_pair(x, y);
        }
    }
    return true;
}

bool Snake::MoveDown()
{
    if(m_head.first == m_rows-1 || m_snake[m_head.first +1][m_head.second] == '#')
    {
        return false;
    }
    else    //move snake and update head and tail
    {
        int x = m_head.first;
        int y = m_head.second;
        m_snake[m_tail.first][m_tail.second] = ' ';
        //where head was- body is :)
        m_snake[m_head.first][m_head.second] = '#';
        //update head
        ++m_head.first;
        //set head
        m_snake[m_head.first][m_head.second] = '@';
        
        //tail

        //update tail
        if(m_body_links > 1)
        {
            UpdateTail();
        }
        else
        {
            m_tail = std::make_pair(x, y);
        }
    }
    return true;
}

bool Snake::MoveLeft()
{
    //check head not touching border nor self
    if(m_head.second == 0 || m_snake[m_head.first][m_head.second -1] == '#')
    {
        return false;
    }
    else    //move snake and update head and tail
    {
        int x = m_head.first;
        int y = m_head.second;
        m_snake[m_tail.first][m_tail.second] = ' ';
        //head
        m_snake[m_head.first][m_head.second] = '#';
        //tail
        --m_head.second;
        m_snake[m_head.first][m_head.second] = '@';

        //update tail
        if(m_body_links > 1)
        {
            UpdateTail();
        }
        else
        {
            m_tail = std::make_pair(x, y);
        }
    }
    return true;
}

bool Snake::MoveRight()
{
    //check head not touching border nor self
    if(m_head.second == m_cols -2 || m_snake[m_head.first][m_head.second +1] == '#')
    {
        return false;
    }
    else    //move snake and update head and tail
    {
        int x = m_head.first;
        int y = m_head.second;
        //head
        m_snake[m_tail.first][m_tail.second] = ' ';
        m_snake[m_head.first][m_head.second] = '#';
        ++m_head.second;
        m_snake[m_head.first][m_head.second] = '@';

        //tail
        //update tail
        if(m_body_links > 1)
        {
            UpdateTail();
        }
        else
        {
            m_tail = std::make_pair(x, y);
        }
    }
    return true;
}