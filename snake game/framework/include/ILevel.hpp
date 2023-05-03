#ifndef __ILEVEL_HPP__
#define __ILEVEL_HPP__


class ILevel
{
    public:
    virtual bool StartLevel() = 0;
    virtual void EndLevel() = 0;

};

#endif //__ILEVEL_HPP__