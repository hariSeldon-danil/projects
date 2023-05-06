#include <iostream>

#include "Snake.hpp"

Snake::Snake(int height, int width):
        m_body_links(1),
        m_rows(height),
        m_cols(width),
        m_head(std::make_pair<int, int>((height -2) /2, (width -3)/2))   //place snake head at center
{
    m_snake_body.push_back(std::make_pair((height -2) /2 +1, (width -3)/2));//first link of body, right behind head
}

Snake::~Snake()
{
}

void Snake::ResetMonster()
{
    m_snake_body.clear();
    m_head = std::make_pair<int, int>((m_rows -2) /2, (m_cols -3)/2);
    m_snake_body.push_back(std::make_pair((m_rows -2) /2 +1, (m_cols -3)/2));//first link of body, right behind head
}

void Snake::EatAndGrow()
{
    std::pair<int, int> tail = m_snake_body.back();
    
    //tail at top left corner
    if(tail.first == 1 && tail.second == 1)  
    {
        m_snake_body.push_back(std::make_pair(tail.first, tail.second +1));
    }
    //tail at top right corner
    else if(tail.first == 1 && tail.second == m_cols -3)
    {
        m_snake_body.push_back(std::make_pair(tail.first + 1, tail.second));
    }
    //tail at buttom left corner
    else if(tail.first == m_rows - 2 && tail.second == 1)
    {
        m_snake_body.push_back(std::make_pair(tail.first + 1, tail.second));
    }
    //tail at buttom right corner
    else if(tail.first == m_rows - 2 && tail.second == m_cols - 3)
    {
        m_snake_body.push_back(std::make_pair(tail.first, tail.second -1));
    }
    //add below
    else
    {
        m_snake_body.push_back(std::make_pair(tail.first, tail.second +1));
    }

    ++m_body_links;
}

bool Snake::SearchBody(std::pair<int, int> pair)
{
    for(auto it : m_snake_body)
    {
        if (it == pair)
        {
            return true;
        }
    }
    return false;
}

void Snake::AdjustSnake()
{
    //place former head in body
        m_snake_body.emplace(m_snake_body.begin(), m_head);

        //delete tail
        m_snake_body.pop_back();
}

bool Snake::MoveUp()
{
    //check head not touching border nor self
    if(m_head.first == 1 || SearchBody(std::make_pair(m_head.first -1, m_head.second)))
    {
        return false;
    }
    else    //move snake and update head and tail
    {
        AdjustSnake();

        //update head position
        --m_head.first;
    }
    return true;
}

bool Snake::MoveDown()
{
    //check head not touching border nor self
    if(m_head.first == m_rows -2 || SearchBody(std::make_pair(m_head.first +1, m_head.second)))
    {
        return false;
    }
    else    //move snake and update head and tail
    {
        AdjustSnake();

        //update head position
        ++m_head.first;
    }
    return true;
}

bool Snake::MoveLeft()
{
    //check head not touching border nor self
    if(m_head.second == 1 || SearchBody(std::make_pair(m_head.first -1, m_head.second - 1)))
    {
        return false;
    }
    else    //move snake and update head and tail
    {
        AdjustSnake();

        //update head position
        --m_head.second;
    }
    return true;
}

bool Snake::MoveRight()
{
    //check head not touching border nor self
    if(m_head.second == m_cols -3 || SearchBody(std::make_pair(m_head.first, m_head.second + 1)))
    {
        return false;
    }
    else    //move snake and update head and tail
    {
        AdjustSnake();

        //update head position
        ++m_head.second;
    }
    return true;
}