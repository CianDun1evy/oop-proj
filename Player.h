
#ifndef PLAYER_H
#define PLAYER_H 
#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"

class Player:public GameEntity{
//class Player{
    protected:

       // sf::RectangleShape *body;

    public:
        Player(int size, int x, int y);
        // {
        //     body = new sf::RectangleShape(sf::Vector2f(size,size));
        //     body->setOrigin(sf::Vector2f(size/2,size/2));
        //     body->setPosition(sf::Vector2f(x,y));
        //     body->setFillColor(sf::Color::Red);
        //     std::cout<<"player initialised"<<std::endl;
        // }
       // Player(){}
        //~Player(){}

        // void move(int x, int y){
        //     // could make this look more complex
        //     this->body->move(x,y);
        //     std::cout<<"body moved!"<<std::endl;
        // }
        void draw(sf::RenderWindow *window);
        // {
        //     window->draw(*body); 
        //     //std::cout<<"drawn!"<<std::endl;

        // }

};


#endif