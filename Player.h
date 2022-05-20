
#ifndef PLAYER_H
#define PLAYER_H 
#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Enemy.h"

class Player:public GameEntity{
    protected:
        // nothing here yet

    public:
        Player(int size, int x, int y,sf::Color color);
        void respawn(int _x,int _y,GameEntity* _e); // respawn is called after "colliding"/overlap with an enemy 
        void inputmove(int type);
        

};


#endif