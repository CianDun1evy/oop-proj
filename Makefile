
LIB1 = -I/usr/local/Cellar/sfml/2.5.1_1/include/
LIB2 = -L/usr/local/Cellar/sfml/2.5.1_1/lib

all: ohg1

# Testing / Drafting makefiles
test: 
	g++ sfml.cpp -o test -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system

intest:
	g++ ReadingTextTest.cpp -o t

# makefiles to use
ohg1: main.cpp Walls.cpp Player.cpp GameEntity.cpp Game.cpp Enemy.cpp WallPos.txt
	clang++ -fsanitize=address -Wall -Werror --std=c++17 main.cpp Walls.cpp Player.cpp GameEntity.cpp Game.cpp Enemy.cpp $(LIB1) -o t $(LIB2) -lsfml-graphics -lsfml-window -lsfml-system

ohg: main.cpp Walls.cpp Player.cpp GameEntity.cpp Game.cpp Enemy.cpp WallPos.txt
	clang++ -fsanitize=address -Wall -Werror --std=c++17 main.cpp Walls.cpp Player.cpp GameEntity.cpp Game.cpp Enemy.cpp -o t -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm sfml t test

#-fsanitize=address