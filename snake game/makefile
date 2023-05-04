VPATH = %.cpp %.hpp ./concrete/src:./:./framework/include:./concrete/include:

INCL = $(wildcard ./framework/include/*.hpp) $(wildcard ./concrete/include/*.hpp ./*.hpp)

SRCS = $(wildcard ./concrete/src/*.cpp) $(wildcard ./*.cpp)
mkfile_path = $(shell pwd)
# Compiler flags
CPPFLAGS = -fdiagnostics-color=always -ansi -pedantic-errors -Wall 
CC = g++


snake_main : $(SRCS) $(INCL)
	$(CC) $(CPPFLAGS) -o $@.out

.PHONY: clean
clean : 
	rm -f *.hex *.out *.so *.o
	
