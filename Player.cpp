#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"


Player::Player(int psize, int x, int y,sf::Color colour, int playerConf){

     // store the size of the player
    this->size = sf::Vector2f(psize,psize);

    body = new sf::RectangleShape(sf::Vector2f(psize,psize));
    body->setOrigin(sf::Vector2f(psize/2,psize/2));
    body->setPosition(sf::Vector2f(x,y));
    body->setFillColor(colour);

    this->playerconfig = playerConf; // CHANGED

    this->numberofDeaths = 0;
    
    std::cout<<"player initialised"<<std::endl;
}

// Player Destructor
Player::~Player(){
    // free body with standard destructor for Shape0
    delete this->body;
    std::cout<<"Player destructor called"<<std::endl; 
}



void Player::respawn(int x,int y,GameEntity* entity){ // rename
    // if a player overlaps with an enemy (overlaps must take vector containing enemies as input)
    if(this->overlaps(entity)==1){
        this->body->setPosition(x,y);
        this->numberofDeaths++;
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
        this->move(-2,0);
    }
    if (sf::Keyboard::isKeyPressed(r)){
        this->move(2,0);
    }
    if (sf::Keyboard::isKeyPressed(u)){
        this->move(0,-2);
    }
    if (sf::Keyboard::isKeyPressed(d)){
        this->move(0,2);
    }
}

std::string Player::getType(){
    return "Player";
}


void Player::update(std::vector <GameEntity *>* gameEnts){

    this->inputmove(this->playerconfig);

    for (int i= 0 ; i<gameEnts->size();i++){

        std::string type = (*gameEnts)[i]->getType();

        if (type == "Wall" || type == "Enemy"){

            this->respawn(100,200,(*gameEnts)[i]);
        }
    }
    // std::cout<<"player updated"<<std::endl;
}


int Player::getDeaths(){
    return this->numberofDeaths;
}