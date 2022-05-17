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

    this->body = new sf::RectangleShape(sf::Vector2f(40,40));
    this->body->setOrigin(sf::Vector2f(25,25));
    this->body->setPosition(sf::Vector2f(x,y));
    this->body->setFillColor(sf::Color::Yellow);
    std::cout<<"enemy initialised"<<std::endl;
}

void Enemy::draw(sf::RenderWindow *window){
    window->draw(*body);    
//std::cout<<"drawn!"<<std::endl;

}
