#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include "Game.h"
#include "Walls.h"

Walls::Walls(int l,int b, int x, int y){
            body = new sf::RectangleShape(sf::Vector2f(l,b));
            body->setOrigin(sf::Vector2f(l/2,b/2));
            body->setPosition(sf::Vector2f(x,y));
            body->setFillColor(sf::Color::White);
            std::cout<<"Wall Initialised"<<std::endl;
        }

void Walls::draw(sf::RenderWindow *window){
            window->draw(*body); 
            //std::cout<<"drawn!"<<std::endl;

        }
