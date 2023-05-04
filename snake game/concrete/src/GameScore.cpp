#include <string>
#include <iostream>

#include "GameScore.hpp"

GameScore::GameScore(int base_score): m_level_score(base_score)
{
}

void GameScore::DisplayScore() const
{
    //\033[0;34m = blue
    std::string display_top =   "\033[0;36m************************************\033[0m\n"
                                "\033[0;36m*                                  *\033[0m\n"
                                "\033[0;36m*            GAME OVER             *\033[0m\n"
                                "\033[0;36m*          your score is:          *\033[0m\n";


    std::string display_low =   "\033[0;36m*                                  *\033[0m\n"
                                "\033[0;36m************************************\033[0m\n";

    std::cout << display_top << "\033[0;36m*               \033[0m" 
                                << m_level_score << "                \033[0;36m*\033[0m\n"
                                << display_low;
    
}