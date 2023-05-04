#include "IScore.hpp"

#include <string>
#include <iostream>

void IScore::DisplayScore() const
{
    //\033[0;34m = blue
    std::string display_top =   "\033[0;34m************************************\033[0m\n"
                                "\033[0;34m*                                  *\033[0m\n"
                                "\033[0;34m*          your score is:          *\033[0m\n";


    std::string display_low =   "\033[0;34m*                                  *\033[0m\n"
                                "\033[0;34m************************************\033[0m\n";

    std::cout << display_top << "\033[0;34m*               \033[0m" 
                                << m_score << "                \033[0;34m*\033[0m\n"
                                << display_low;
    
}

