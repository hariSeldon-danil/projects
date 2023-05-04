#include "IPrey.hpp"

#include <iostream>

class Prey : public IPrey
{
    private:
    std::pair<int, int> m_location;

    public:
    
    inline std::pair<int, int> GetPosition() const;
    inline void SetPosition(int x, int y);
};

std::pair<int, int> Prey::GetPosition() const
{
    return m_location;
}
void Prey::SetPosition(int x, int y)
{
    m_location = std::make_pair(x, y);
}