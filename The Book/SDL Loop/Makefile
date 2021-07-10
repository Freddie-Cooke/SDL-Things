# Makefile, Freddie Cooke
# Compiling SDL2 hello_sdl.cpp

OBJS = sdl_loop.cpp

CC = g++

INCLUDE = -IF:\Documents\Computing\Languages\C++\Libraries\SDL2\include\SDL2

LIB = -LF:\Documents\Computing\Languages\C++\Libraries\SDL2\lib

CFLAGS = -w -Wl,-subsystem,windows

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

OBJ_NAME = main

all:
	$(CC) $(OBJS) $(INCLUDE) $(LIB) $(CFLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
