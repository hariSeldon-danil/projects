#include <iostream>

#include "Board.hpp"

int main()
{
    Board board_;
    board_.DrawTable();
    return 0;
}

//g++ -I ./framework/include -I ./concrete/include ./concrete/src/Board.cpp ./concrete/src/Prey.cpp ./concrete/src/Level.cpp ./test/Board_test.cpp 
