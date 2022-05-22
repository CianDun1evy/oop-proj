#pragma once

#ifndef ENEMY_H
#define ENEMY_H 
#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"

class Enemy:public GameEntity{
    protected:
        int x, y;
// nothing here yet

    public:
        Enemy(int pos);
        void move(int x, int y);
        
        std::string getType() override;
        
        void update(std::vector <GameEntity *>* gameEnts) override; 
};

#endif