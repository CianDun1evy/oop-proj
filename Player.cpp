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

// void Player::draw(sf::RenderWindow *window){
//             window->draw(*body); 
//             //std::cout<<"drawn!"<<std::endl;

//         }

void Player::respawn(int x,int y,Enemy* _enemy){
    // if a player overlaps with an enemy (overlaps must take vector containing enemies as input)
    if(this->overlaps(_enemy)==1){
        this->body->setPosition(x,y);
    }
    else{}
}

void Player::inputmove(int a){
    sf::Keyboard::Key l,r,u,d; // left, right, up, down

    // setup which keybinds to use for player
    if(a==0){
        l = sf::Keyboard::A;
        r = sf::Keyboard::D;
        u = sf::Keyboard::W;
        d = sf::Keyboard::S;
    }
    else if (a==1){
        l = sf::Keyboard::Left;
        r = sf::Keyboard::Right;
        u = sf::Keyboard::Up;
        d = sf::Keyboard::Down;
    } // can add more movement key configs if needed

    // move player based on user input
    if (sf::Keyboard::isKeyPressed(l)){
        this->move(-1,0);
    }
    if (sf::Keyboard::isKeyPressed(r)){
        this->move(1,0);
    }
    if (sf::Keyboard::isKeyPressed(u)){
        this->move(0,-1);
    }
    if (sf::Keyboard::isKeyPressed(d)){
        this->move(0,1);
    }
}

