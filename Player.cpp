#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include "Game.h"

Player::Player(int size, int x, int y){
            body = new sf::RectangleShape(sf::Vector2f(size,size));
            body->setOrigin(sf::Vector2f(size/2,size/2));
            body->setPosition(sf::Vector2f(x,y));
            body->setFillColor(sf::Color::Red);
            std::cout<<"player initialised"<<std::endl;
        }

void Player::draw(sf::RenderWindow *window){
            window->draw(*body); 
            //std::cout<<"drawn!"<<std::endl;

        }
