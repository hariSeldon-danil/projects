#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <vector>
#include <thread>

#include "ILevel.hpp"

class Game
{
    private:
    std::vector<ILevel *> m_levels;
    int m_current_level;
    bool m_stop_play;
    bool m_pause;
    //std::thread m_thread;

    public:
    Game();
    ~Game();
    void Start();
    //void End();

};


#endif  //__GAME_HPP__