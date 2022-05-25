#include<iostream>
#include<SFML/Graphics.hpp>

#include "Player.h"
#include "Enemy.h"


Enemy::Enemy(int pos) {

    // hard-code simple enemy movement
    this->x = 202 + (50*pos);
    this->y = (rand()%450+50);

    this->body = new sf::CircleShape(10.f);

    // store the size of the enemy
    this->size = sf::Vector2f(2*10,2*10);

    // this->body = new sf::CircleShape(sf::Vector2f(40,40));
    this->body->setOrigin(sf::Vector2f(10,10));
    this->body->setPosition(sf::Vector2f(x,y));
    this->body->setFillColor(sf::Color::Blue);
    std::cout<<"Enemy initialised"<<std::endl;
}

Enemy::~Enemy(){
    // free body with standard destructor for Shape
    delete this->body;
    std::cout<<"Enemy destructor called"<<std::endl;

}


std::string Enemy::getType(){
    return "Enemy";
}

void Enemy::reset(int x,int y,GameEntity* entity){ // rename
    // if a player overlaps with an enemy (overlaps must take vector containing enemies as input)
    if(this->overlaps(entity)==1){
        this->body->setPosition(x,y);
    }
    else{}
}




void Enemy::update(std::vector <GameEntity *>* gameEnts){
        // float x=(rand()%2+1);
        // float y=(rand()%2+1);
    // int count=0;
//        this->move(0.1,0.2);
    // moving around autonomously 

    for (int i= 0 ; i<gameEnts->size();i++){
            
            
        std::string type = (*gameEnts)[i]->getType();

        if (type == "Wall" || type == "Player"){

            this->reset(250,50,(*gameEnts)[i]);
        }
    }
    this->move(1,1);
    
    // std::cout<<"enemy updated"<<std::endl;
    

}