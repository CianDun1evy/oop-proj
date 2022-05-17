#ifndef ENEMY_H
#define ENEMY_H 
#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"

class Enemy:public GameEntity{
protected:
int x=0, y=0;
// nothing here yet

public:
Enemy(int pos);
void draw(sf::RenderWindow *window);
};

#endif