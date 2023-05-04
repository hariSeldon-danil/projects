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
    std::vector<std::pair<int, int>> m_snake_body;
    bool SearchBody(std::pair<int, int> pair);
    void AdjustSnake();
   
    
    public:
    Snake(int height, int width);
    ~Snake();

    bool MoveUp();
    bool MoveDown();
    bool MoveLeft();
    bool MoveRight();
    void EatAndGrow();
    inline const std::vector<std::pair<int, int>>& GetMonsterBody() const;
    inline const std::pair<int, int> GetHead() const;
    inline const int GetBodyLinks() const;

    
};

const std::vector<std::pair<int, int>>& Snake::GetMonsterBody() const
{
    return m_snake_body;
}

const std::pair<int, int> Snake::GetHead() const
{
    return m_head;
}

const int Snake::GetBodyLinks() const
{
    return m_body_links;
}

#endif  //__SNAKE_HPP__