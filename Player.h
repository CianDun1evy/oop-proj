#pragma once

#ifndef PLAYER_H
#define PLAYER_H 
#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Enemy.h"

class Player:public GameEntity{
    protected:
        // player config number
        int playerconfig;
        // number of deaths
        int numberofDeaths;
    public:
        // constructor
        Player(int size, int x, int y,sf::Color color,int config);
        
        // destructor
        ~Player();

        // respawn is called after "colliding"/overlap with an enemy 
        void respawn(int _x,int _y,GameEntity* _e); 
        
        // player movement keys
        void inputmove(int type);

        //returns player type
        std::string getType() override;

        
        void update(std::vector <GameEntity *>* gameEnts) override;  

        // returns num deaths
        int getDeaths(); 

};


#endif