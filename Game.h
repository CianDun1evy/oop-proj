
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"

class Game : public GameEntity
{
    // game runs straight from here
protected:
    sf::RenderWindow *window;
    Player *player;

    sf::CircleShape *shape1; // delete this

    // std::vector<GameEntity *> gameEntities;

public:
    Game(int x, int y, std::string title);

    //~Game(){}

    void run();

};
#endif