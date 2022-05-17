#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include "Game.h"

Player::Player(int size, int x, int y,sf::Color colour){
            body = new sf::RectangleShape(sf::Vector2f(size,size));
            body->setOrigin(sf::Vector2f(size/2,size/2));
            body->setPosition(sf::Vector2f(x,y));
            body->setFillColor(colour);
            std::cout<<"player initialised"<<std::endl;
        }

void Player::draw(sf::RenderWindow *window){
            window->draw(*body); 
            //std::cout<<"drawn!"<<std::endl;

        }

void Player::respawn(int x,int y,Enemy* _enemy){
    // if a player overlaps with an enemy (overlaps must take vector containing enemies as input)
    if(this->overlaps(_enemy)==1){
        this->body->setPosition(x,y);
    }
    else{}
}