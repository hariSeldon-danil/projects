#include <iostream>
#include <termios.h>    //termios for terminal interface
#include <unistd.h>     //stdin, null

#include "Game.hpp"
#include "Level.hpp"

Game::Game(): m_current_level(1)
{
    for(int i = 0; i < 5; ++ i)
    {
        //the heigher the level- the smaller the board
        int x = 30 - 3 * i; //num of rows and cols- can be modified later
        int y = 30 - 3 * i;
        m_levels.push_back(new Level(x, y));
    }
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
    std::cout << "Welcome to Snake!!!\n";
    while(1)
    {
        std::cout <<"hit 'y' to start\n 'q' to quit\n" << std::endl;

        std::cin >> input;

        if(input == 'y')
        {
            
            level_success = m_levels[m_current_level]->StartLevel();
            if(level_success == false)
            {
                std::cout << "Wrong move! Game over\n"; //to add try again?
                break;
            }
            else
            {
                ++m_current_level;
            }
        }
        else if(input == 'q')
        {
        
            std::cout << "Sorry to see you go\n";
            break;
        } 

    }
    SetCanonicalMode(0);    //turn back on enter as delimiter
}
/*
void Game::End()
{
    
    displays scores
    more options needed
    
}*/