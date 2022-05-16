

LIB = -I/usr/local/Cellar/sfml/2.5.1_1/include/ 
ABC = -L/usr/local/Cellar/sfml/2.5.1_1/lib



all: oopgame  
test: 
	g++ sfml.cpp $(LIB)  -o test $(ABC) -lsfml-graphics -lsfml-window -lsfml-system

main:
	g++ main.cpp -o t -lsfml-graphics -lsfml-window -lsfml-system

oopgame:
	g++ oopgame.cpp -o t -lsfml-graphics -lsfml-window -lsfml-system


macmain:
	g++ main.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include/  -o t -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system
testing:
	g++ testing.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include/  -o t -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system

simran:
	g++ newgame.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include/  -o t -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system

simran1:
	g++ newgame.cpp  -o t -lsfml-graphics -lsfml-window -lsfml-system

game1:
	g++ game1.cpp  -o t -lsfml-graphics -lsfml-window -lsfml-system
macgame1:
	g++ game1.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include/  -o t -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system	


clean:
	rm sfml t test