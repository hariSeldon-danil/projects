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



bool Snake::SearchBody(const std::pair<int, int>& pair)
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

void Snake::AdjustSnake(std::pair<int, int>& prey_position, const std::pair<int, int>& future_head_position)
{
    //place former head in body
        m_snake_body.emplace(m_snake_body.begin(), m_head);

        if(prey_position != future_head_position)
        {
            //delete tail
            m_snake_body.pop_back();
        }
        else
        {
            ++m_body_links;
        }    
}

bool Snake::MoveUp(std::pair<int, int>& prey_position)
{
    //check head not touching border nor self
    if(m_head.first == 1 || SearchBody(std::make_pair(m_head.first -1, m_head.second)))
    {
        return false;
    }
    else    //move snake and update head and tail
    {
        //update head position
        AdjustSnake(prey_position, std::make_pair(m_head.first -1, m_head.second));
        --m_head.first;
    }
    return true;
}

bool Snake::MoveDown(std::pair<int, int>& prey_position)
{
    //check head not touching border nor self
    if(m_head.first == m_rows -2 || SearchBody(std::make_pair(m_head.first +1, m_head.second)))
    {
        return false;
    }
    else    //move snake and update head and tail
    {
        //update head position
        AdjustSnake(prey_position, std::make_pair(m_head.first+1, m_head.second));
        ++m_head.first;
    }
    return true;
}

bool Snake::MoveLeft(std::pair<int, int>& prey_position)
{
    //check head not touching border nor self
    if(m_head.second == 1 || SearchBody(std::make_pair(m_head.first, m_head.second - 1)))
    {
        return false;
    }
    else    //move snake and update head and tail
    {
        //update head position
        AdjustSnake(prey_position, std::make_pair(m_head.first, m_head.second -1));
        --m_head.second;
    }
    return true;
}

bool Snake::MoveRight(std::pair<int, int>& prey_position)
{
    //check head not touching border nor self
    if(m_head.second == m_cols -3 || SearchBody(std::make_pair(m_head.first, m_head.second + 1)))
    {
        return false;
    }
    else    //move snake and update head and tail
    {

        //update head position
        AdjustSnake(prey_position, std::make_pair(m_head.first, m_head.second +1));
        ++m_head.second;
    }
    return true;
}