
#include "Game.hpp"



int main()
{
    Game snake_game;
    
    snake_game.Start();
    
}
/* 
g++ -I ./framework/include -I ./concrete/include ./concrete/src/Board.cpp ./concrete/src/Level.cpp ./concrete/src/Snake.cpp ./concrete/src/Game.cpp ./snake_game.cpp -o snake_game

*/
