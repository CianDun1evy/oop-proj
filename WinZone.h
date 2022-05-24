#pragma once

#ifndef WINZONE_H
#define WINZONE_H

#include<SFML/Graphics.hpp>
#include<iostream>

#include "GameEntity.h"

class WinZone:public GameEntity{
    public:
        // constructor
        WinZone(float length,float breadth, int x, int y);
        
        // destructor
        ~WinZone();

        // set class type
        std::string getType() override;
        
        // update function
        void update(std::vector <GameEntity *>* gameEnts) override; 
};


#endif