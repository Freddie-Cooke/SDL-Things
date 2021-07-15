# Makefile, Freddie Cooke
# Compiling SDL2 main, SDL2_image

OBJS = main.cpp

CC = g++

INCLUDE = -IF:\Documents\Computing\Languages\C++\Libraries\SDL2\include\SDL2 -IF:\Documents\Computing\Languages\C++\Libraries\SDL2_Image\include\SDL2

LIB = -LF:\Documents\Computing\Languages\C++\Libraries\SDL2\lib -LF:\Documents\Computing\Languages\C++\Libraries\SDL2_Image\lib

CFLAGS = #-w -Wl,-subsystem,windows

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

OBJ_NAME = main

all:
	$(CC) $(OBJS) $(INCLUDE) $(LIB) $(CFLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
