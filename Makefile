
LIB1 = -I/usr/local/Cellar/sfml/2.5.1_1/include/
LIB2 = -L/usr/local/Cellar/sfml/2.5.1_1/lib
SFML = -lsfml-graphics -lsfml-window -lsfml-system
debug = -fsanitize=address -Wall -Werror

all: project1

# Testing / Drafting makefiles
test: 
	g++ sfml.cpp -o test -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system

intest:
	g++ ReadingTextTest.cpp -o t

# makefiles to use:
project: main.cpp Game.o Player.o Walls.o Enemy.o GameEntity.o
	clang++ $(debug) main.cpp Game.o Player.o Walls.o Enemy.o GameEntity.o $(LIB1) -o t $(LIB2) $(SFML)

project1: main.cpp Game.o Player.o Walls.o Enemy.o GameEntity.o
	clang++ $(debug) main.cpp Game.o Player.o Walls.o Enemy.o GameEntity.o -o t $(SFML)

clean:
	rm t test *.o proj

#-fsanitize=address