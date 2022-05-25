
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include<fstream>
#include<iostream>

#include "Walls.h"

Walls::Walls(float length,float breadth, int x, int y){

    // store the size of the wall
    this->size = sf::Vector2f(length,breadth);

    // creates new rectangle shape 
    body = new sf::RectangleShape(sf::Vector2f(length,breadth));
    body->setOrigin(sf::Vector2f(length/2,breadth/2));
    body->setPosition(sf::Vector2f(x,y));
    body->setFillColor(sf::Color::White);
    std::cout<<"Wall Initialised"<<std::endl;
}

// Destructor
Walls::~Walls(){
    delete this->body;
    std::cout<<"Wall destructor called"<<std::endl;
}


std::string Walls::getType(){
    return "Wall";
}

void Walls::update(std::vector <GameEntity *>* gameEnts){
    // do nothing
}

