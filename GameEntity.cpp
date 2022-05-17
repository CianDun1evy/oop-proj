#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"

void GameEntity::move(int x, int y){ 
            // could make this look more complex
            this->body->move(x,y);
            std::cout<<"body moved!"<<std::endl;
        }