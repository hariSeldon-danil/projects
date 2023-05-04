#include "Level.hpp"

int main()
{
    Level one(25, 25);
    one.StartLevel();

    return 0;
}
/*
g++ -I ./framework/include -I ./concrete/include ./concrete/src/Board.cpp ./concrete/src/Level.cpp ./concrete/src/Snake.cpp ./test/Level_test.cpp
*/