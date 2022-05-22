#pragma once

#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <iostream>
#include <SFML/Graphics.hpp>

class GameEntity{
protected:
    sf::Shape *body;
    sf::Vector2f size;
    
    // put size values for the shape in here, so i guess:
    // set these vals to whatever it is when you initialise in each constructor
    // 
    

    // sf::RectangleShape* body; // okay so having a body doesn't work either
public:
    void move(float x, float y);

    void draw(sf::RenderWindow *window);


    bool overlaps(GameEntity *_entity); // std::vector<GameEntity *> gameEntities; // that should be input


    virtual void update(std::vector <GameEntity *>* gameEnts)=0;

    virtual std::string getType()=0;

    // sf::Vector2f getBodySize(){
    //     return sf::Vector2f(this->sizex,this->sizey);
    // }
};

#endif