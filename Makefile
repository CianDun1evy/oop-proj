all: oopgame  
test: 
	g++ sfml.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include/  -o test -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system

main:
	g++ main.cpp -o t -lsfml-graphics -lsfml-window -lsfml-system

oopgame:
	g++ oopgame.cpp -o t -lsfml-graphics -lsfml-window -lsfml-system


macmain:
	g++ main.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include/  -o t -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system



mc:
	g++ OHG.cpp Walls.cpp Player.cpp GameEntity.cpp Game.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include/  -o t -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system

mc1:
		g++ OHG.cpp Walls.cpp Player.cpp GameEntity.cpp Game.cpp   -o t  -lsfml-graphics -lsfml-window -lsfml-system

as:
	g++ game1.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include/  -o t -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system



clean:
	rm sfml t test