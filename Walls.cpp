#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include "Game.h"
#include "Walls.h"

Walls::Walls(int length,int breadth, int x, int y){

    // store the size of the wall
    this->size = sf::Vector2f(length,breadth);

    body = new sf::RectangleShape(sf::Vector2f(length,breadth));
    body->setOrigin(sf::Vector2f(length/2,breadth/2));
    body->setPosition(sf::Vector2f(x,y));
    body->setFillColor(sf::Color::White);
    std::cout<<"Wall Initialised"<<std::endl;
        }

// void Walls::draw(sf::RenderWindow *window){
//             window->draw(*body); 
//             //std::cout<<"drawn!"<<std::endl;

//         }
