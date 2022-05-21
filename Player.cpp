#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"


Player::Player(int psize, int x, int y,sf::Color colour){

     // store the size of the player
    this->size = sf::Vector2f(psize,psize);

    body = new sf::RectangleShape(sf::Vector2f(psize,psize));
    body->setOrigin(sf::Vector2f(psize/2,psize/2));
    body->setPosition(sf::Vector2f(x,y));
    body->setFillColor(colour);
    std::cout<<"player initialised"<<std::endl;
}


void Player::respawn(int x,int y,GameEntity* _enemy){
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
    else{
        l = sf::Keyboard::Left;
        r = sf::Keyboard::Right;
        u = sf::Keyboard::Up;
        d = sf::Keyboard::Down;
    } // can add more movement key configs if needed

    // move player based on user input
    if (sf::Keyboard::isKeyPressed(l)){
        this->move(-.5,0);
    }
    if (sf::Keyboard::isKeyPressed(r)){
        this->move(.5,0);
    }
    if (sf::Keyboard::isKeyPressed(u)){
        this->move(0,-.5);
    }
    if (sf::Keyboard::isKeyPressed(d)){
        this->move(0,.5);
    }
}

