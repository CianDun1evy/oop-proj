#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy(int pos) {

    // hard-code simple enemy movement
    this->x = 192 + (50*pos);
    this->y = (rand()%450+50);

    this->body = new sf::CircleShape(10.f);

    // store the size of the enemy
    this->size = sf::Vector2f(2*10,2*10);

    // this->body = new sf::CircleShape(sf::Vector2f(40,40));
    this->body->setOrigin(sf::Vector2f(10,10));
    this->body->setPosition(sf::Vector2f(x,y));
    this->body->setFillColor(sf::Color::Blue);
    std::cout<<"enemy initialised"<<std::endl;
}

Enemy::~Enemy(){
    // free body with standard destructor for Shape
    delete this->body;
    std::cout<<"Enemy destructor called"<<std::endl;

}


std::string Enemy::getType(){
    return "Enemy";
}


void Enemy::update(std::vector <GameEntity *>* gameEnts){

    // moving around autonomously 

}