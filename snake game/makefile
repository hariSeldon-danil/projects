VPATH = ./concrete/src:./framework/include:./concrete/include:

INCLUDE = -I ./framework/include/ -I ./concrete/include/

SRCS = ./concrete/src/Board.cpp ./concrete/src/Game.cpp ./concrete/src/GameScore.cpp ./concrete/src/Level.cpp ./concrete/src/LevelScore.cpp ./concrete/src/Snake.cpp
GAME_MAIN = ./snake_main.cpp

NAME = Snake_Game

mkfile_path = $(shell pwd)
# Compiler flags
CPPFLAGS = -fdiagnostics-color=always -ansi -std=c++23 
CC = g++


$(NAME) : $(SRCS) $(GAME_MAIN)
	$(CC) $(CPPFLAGS) $(INCLUDE) $^ -o $(NAME).out

.PHONY: clean
clean : 
	rm -f *.hex *.out *.so *.o
	
