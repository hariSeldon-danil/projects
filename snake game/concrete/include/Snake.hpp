#ifndef __SNAKE_HPP__
#define __SNAKE_HPP__

#include <vector>

#include "IMonster.hpp"

class Snake : public IMonster
{
    public:

    private:
    int m_body_links;
    int m_rows;
    int m_cols;
    std::pair<int, int> m_head; //@
    std::vector<std::pair<int, int> > m_snake_body;
    bool SearchBody(const std::pair<int, int>& pair);
    void AdjustSnake(std::pair<int, int>& prey_position, const std::pair<int, int>& future_head_position);
   
    
    public:
    Snake(int height, int width);
    ~Snake();
    


    bool MoveUp(std::pair<int, int>& prey_position);
    bool MoveDown(std::pair<int, int>& prey_position);
    bool MoveLeft(std::pair<int, int>& prey_position);
    bool MoveRight(std::pair<int, int>& prey_position);
    inline const std::vector<std::pair<int, int> >& GetMonsterBody() const;
    inline const std::pair<int, int> GetHead() const;
    inline const int GetBodyLinks() const;
    void ResetMonster();

    
};

const std::vector<std::pair<int, int> >& Snake::GetMonsterBody() const
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