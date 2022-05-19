#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include "Game.h"
#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy(int pos) {
    
    // hard-code simple enemy movement
    this->x = 192 + (50*pos);
    this->y = (rand()%450+50);

    this->body = new sf::CircleShape(10.f);

    // this->body = new sf::CircleShape(sf::Vector2f(40,40));
    this->body->setOrigin(sf::Vector2f(10,10));
    this->body->setPosition(sf::Vector2f(x,y));
    this->body->setFillColor(sf::Color::Red);
    std::cout<<"enemy initialised"<<std::endl;
}

// void Enemy::draw(sf::RenderWindow *window){
//     window->draw(*body);    
//std::cout<<"drawn!"<<std::endl;

//}
