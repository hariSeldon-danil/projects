#ifndef __SNAKE_HPP__
#define __SNAKE_HPP__

#include <vector>

#include "IMonster.hpp"

class Snake : public IMonster
{
    private:
    int m_body_links;
    int m_rows;
    int m_cols;
    std::pair<int, int> m_head; //@
    std::pair<int, int> m_tail; //row, col
    std::vector<std::vector<char>> m_snake;
    void UpdateTail();
    
    public:
    Snake(int height, int width);
    ~Snake();

    
    bool MoveUp();
    bool MoveDown();
    bool MoveLeft();
    bool MoveRight();
    void EatAndGrow();
    inline const std::vector<std::vector<char>>& GetMonsterBody() const;
    inline const std::pair<int, int> GetHead() const;
};

const std::vector<std::vector<char>>& Snake::GetMonsterBody() const
{
    return m_snake;
}

const std::pair<int, int> Snake::GetHead() const
{
    return m_head;
}

#endif  //__SNAKE_HPP__