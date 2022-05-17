#ifndef WALLS_H
#define WALLS_H 
#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Game.h"
#include "Player.h"

class Walls:public GameEntity{
    protected:
        // nothing here yet

    public:
        Walls(int l,int b, int x, int y);
        void draw(sf::RenderWindow *window);

};


#endif