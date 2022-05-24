#pragma once

#ifndef PLAYER_H
#define PLAYER_H 
#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Enemy.h"

class Player:public GameEntity{
    protected:
        // nothing here yet
        int playerconfig;
    public:
        // constructor
        Player(int size, int x, int y,sf::Color color,int config);
        
        // destructor
        ~Player();

        void respawn(int _x,int _y,GameEntity* _e); // respawn is called after "colliding"/overlap with an enemy 
        
        void inputmove(int type);

        std::string getType() override;

        bool endgame(GameEntity* green);
        
        void update(std::vector <GameEntity *>* gameEnts) override;    

};


#endif