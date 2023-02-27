
LIB1 = -I/usr/local/Cellar/sfml/2.5.1_1/include/
LIB2 = -L/usr/local/Cellar/sfml/2.5.1_1/lib
SFML = -lsfml-graphics -lsfml-window -lsfml-system 
debug = --std=c++17 -fsanitize=address -Wall -Werror

all: project

# Testing / Drafting makefiles

intest:
	g++ ReadingTextTest.cpp -o test1

# makefiles to use:

# used on mac
project: main.cpp OHG_Game.o Player.o Walls.o Enemy.o GameEntity.o WinZone.o ScreenText.o
	clang++ $(debug) main.cpp OHG_Game.o Player.o Walls.o Enemy.o GameEntity.o WinZone.o ScreenText.o $(LIB1) -o t $(LIB2) $(SFML)

# used on windows
project1: main.cpp OHG_Game.o Player.o Walls.o Enemy.o  GameEntity.o WinZone.o ScreenText.o
	clang++ $(debug) main.cpp OHG_Game.o Player.o Walls.o Enemy.o GameEntity.o WinZone.o ScreenText.o -o t $(SFML)

chat: ChatGPTGame.cpp
	clang++ $(debug) ChatGPTGame.cpp $(LIB1) -o chat $(LIB2) $(SFML)

c2: GPTTest2.cpp
	clang++ $(debug) GPTTest2.cpp $(LIB1) -o c $(LIB2) $(SFML)
flap: flappy.cpp
	clang++ $(debug) flappy.cpp $(LIB1) -o f $(LIB2) $(SFML)
	


clean:
	rm t test1 *.o proj chat c f

#look into .a files, basically an archive 
#this is good for some reason, cleans things?
#.PHONY: all clean project1
