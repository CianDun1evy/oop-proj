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

};

#endif