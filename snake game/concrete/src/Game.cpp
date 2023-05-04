#include <iostream>
#include <termios.h>    //termios for terminal interface
#include <unistd.h>     //stdin, null

#include "Game.hpp"
#include "Level.hpp"
#include "GameScore.hpp"

Game::Game():   m_current_level(1),
                m_game_score(new GameScore(0)),
                m_played_flag(false)
{
    for(int i = 0; i < 5; ++ i)
    {
        //the heigher the level- the smaller the board
        int x = 30 - 3 * i; //num of rows and cols- can be modified later
        int y = 30 - 3 * i;
        m_levels.push_back(new Level(x,y,i*i, 4));
    }
}

Game::~Game()
{
    for(int i = 0; i < m_levels.size(); ++i)
    {
        delete m_levels[i];
    }
    delete m_game_score;
}

void SetCanonicalMode(int state) //set off input mode without enter key
{
    struct termios ttystate;
 
    //get the terminal state
    tcgetattr(STDIN_FILENO, &ttystate);
 
    if (state== 1)  //NB_ENABLE
    {
        //turn off canonical mode
        ttystate.c_lflag &= ~ICANON;
        //minimum of number input read.
        ttystate.c_cc[VMIN] = 1;
    }
    else if (state==0)  //NB_DISABLE
    {
        //turn on canonical mode
        ttystate.c_lflag |= ICANON;
    }
    //set the terminal attributes.
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

void Game::Start()
{
    fflush(stdin);
    bool level_success = true;
    char input;
    SetCanonicalMode(1);    //turn off enter as delimiter
    std::cout << "\n\033[0;32mWelcome to Snake!!!\033[0m\n";
    while(1)
    {
        std::cout <<"\033[0;33mhit 'y' to start\n 'q' to quit\033[0m\n" << std::endl;
        if(m_played_flag == true)
        {
            std::cout << "\033[00;34mLEVEL " << m_current_level << "\033[0m" << std::endl;
        }
        std::cin >> input;

        if(input == 'y')
        {
            m_played_flag = true;
            level_success = m_levels[m_current_level]->StartLevel();
            m_game_score->AddPoints(m_levels[m_current_level]->GetLevelScore()->GetScore());
            if(level_success == false)
            {
                std::cout << "\033[0;31mWrong move!\033[0m\n";
            }
            else
            {               
                m_levels[m_current_level]->EndLevel();
                ++m_current_level;
            }
        }
        else if(input == 'q')
        {
            //maybe print summary?
            break;
        } 
    }
    SetCanonicalMode(0);    //turn back on enter as delimiter
}

void Game::End()
{
    m_game_score->DisplayScore();
    std::cout << "\033[0;37mSorry to see you go\033[0m\n";

    
}