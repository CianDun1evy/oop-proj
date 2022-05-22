#pragma once

#ifndef WALLS_H
#define WALLS_H 
#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"

class Walls:public GameEntity{
    protected:
        

    public:
        Walls(float length,float breadth, int x, int y);
        
        std::string getType() override;
        
        void update(std::vector <GameEntity *>* gameEnts) override; 

    //   ~Walls();
};


#endif