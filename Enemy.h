#pragma once

#ifndef ENEMY_H
#define ENEMY_H 

#include<iostream>
#include<SFML/Graphics.hpp>

#include "GameEntity.h"

class Enemy:public GameEntity{
    protected:
        int x, y;
// nothing here yet

    public:
        // constructor
        Enemy(int pos);

        // destructor
        ~Enemy();

        // void move(int x, int y);
        
        std::string getType() override;
        void reset(int x,int y,GameEntity* entity);
        void update(std::vector <GameEntity *>* gameEnts) override; 
};

#endif