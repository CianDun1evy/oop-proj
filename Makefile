
LIB = -I/usr/local/Cellar/sfml/2.5.1_1/include/


all: ohg1

# Testing / Drafting makefiles
test: 
	g++ sfml.cpp   -o test -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system

intest:
	g++ ReadingTextTest.cpp -o t

# makefiles to use
ohg1: OHG.cpp Walls.cpp Player.cpp GameEntity.cpp Game.cpp Enemy.cpp WallPos.txt
	clang++  -Wall -Werror --std=c++17 OHG.cpp Walls.cpp Player.cpp GameEntity.cpp Game.cpp Enemy.cpp $(LIB)  -o t -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system

ohg: OHG.cpp Walls.cpp Player.cpp GameEntity.cpp Game.cpp Enemy.cpp WallPos.txt
	clang++ -fsanitize=address -Wall -Werror OHG.cpp Walls.cpp Player.cpp GameEntity.cpp Game.cpp Enemy.cpp -o t -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm sfml t test