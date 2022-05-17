
#ifndef PLAYER_H
#define PLAYER_H 
#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"

class Player:public GameEntity{
    protected:
        // nothing here yet

    public:
        Player(int size, int x, int y,sf::Color color);
        void draw(sf::RenderWindow *window);

};


#endif