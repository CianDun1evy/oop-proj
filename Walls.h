#pragma once

#ifndef WALLS_H
#define WALLS_H 
#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"

class Walls:public GameEntity{
    public:
        // constructor
        Walls(float length,float breadth, int x, int y);
        
        // destructor
        ~Walls();

        // set class type
        std::string getType() override;
        
        // update function
        void update(std::vector <GameEntity *>* gameEnts) override; 
};


#endif