#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <vector>
#include <thread>

#include "ILevel.hpp"
#include "IScore.hpp"

void SetCanonicalMode(int state);

class Game
{
    private:
    std::vector<ILevel *> m_levels;
    IScore *m_game_score;
    bool m_played_flag;


    int m_current_level;
    bool m_stop_play;
    bool m_pause;
    public:
    Game();
    ~Game();

    void Start();
    void End();

};


#endif  //__GAME_HPP__