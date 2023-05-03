#include <iostream>

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

void Game::Start()
{
    fflush(stdin);
    bool level_success = true;
    char input;
    
    while(1)
    {
        std::cout <<
        "Welcome to Snake!!!\n Hit 'y' to start\n 'q' to quit\n" << std::endl;

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

    /*
    to do
    thread returns bool for running level: 
        if level is finished successfully returns true
        else
        option try again?
    when user hit y for start thread will come into action and run current level
    when level is finished successfuly:
        current level will increase and thread will run next level 
    
   */ 
}
/*
void Game::End()
{
    
    displays scores
    more options needed
    
}*/