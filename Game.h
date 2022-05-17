
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include "Walls.h"
#include "Enemy.h"

class Game : public GameEntity 
{
    // game runs straight from here
protected:
    sf::RenderWindow *window;

    Player *player1;
    Player *player2;
    
    Walls *boundary_top;
    Walls *boundary_bottom;
    Walls *boundary_left;
    Walls *boundary_right;
    Walls *wall11;
    Walls *wall12;
    Walls *wall21;
    Walls *wall22;
    Enemy *e1;
    Enemy *e2;
    Enemy *e3;
    Enemy *e4;
    Enemy *e5;
    Enemy *e6;
    Enemy *e7;
    Enemy *e8;
    Enemy *e9;
    Enemy *e10;
//    sf::CircleShape *shape1; // delete this

    // std::vector<GameEntity *> gameEntities; // add walls into a vector for easy looping through to detect for intersection

public:
    Game(int x, int y, std::string title);

    //~Game(){}

    void run();

};
#endif