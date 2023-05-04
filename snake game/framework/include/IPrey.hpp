#ifndef __IPREY_HPP__
#define __IPREY_HPP__

#include <utility>  //pair


class IPrey
{
    public:
    virtual std::pair<int, int> GetPosition() const = 0;
    virtual void SetPosition(int x, int y) = 0;
};

#endif //__IPREY_HPP__