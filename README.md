# snake game
## Description
A simple classic snake game built using C++ programming language

## Game Overview

The objective of the game is to control the snake ,eat the food and grow longer. 
As the snake grows longer, it becomes harder to control it without colliding with the walls or the snake's own body. If this happens the game is over

## How to Play

1.  Download or clone the repository to your local machine
2.  open terminal and navigate into snake_game folder and type compilation command:
```sh
g++ -I ./framework/include -I ./concrete/include ./concrete/src/Board.cpp ./concrete/src/Level.cpp ./concrete/src/Snake.cpp ./concrete/src/Game.cpp ./snake_main.cpp -o snake_game
```
3.  Run from terminal with the command:
```sh
./snake_game
```
4.  chose the option y, hit enter and start playing
5.  Use the arrow keys on your keyboard to control the direction of the snake
6.  Eat the food to grow longer and try to avoid colliding with the walls or your own body

## Keys action

'w' - go up
's' - go down
'a' - go left
'd' - go right
'q' - quit game

## Future Improvements
* implement pause option
* add score to eack body link added
* set score per body link per level
* use threads for game and/or display
