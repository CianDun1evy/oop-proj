all: ohg1

# Testing / Drafting makefiles
test: 
	g++ sfml.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include/  -o test -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system

readtext:
	g++ ReadingTextTest.cpp -o t

# makefiles to use
ohg1:
	clang++ -Wall OHG.cpp Walls.cpp Player.cpp GameEntity.cpp Game.cpp Enemy.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include/  -o t -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system

ohg:
	clang++ -Wall OHG.cpp Walls.cpp Player.cpp GameEntity.cpp Game.cpp Enemy.cpp -o t  -lsfml-graphics -lsfml-window -lsfml-system


clean:
	rm sfml t test