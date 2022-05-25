#pragma once

#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <iostream>
#include <SFML/Graphics.hpp>

// Abstract class from which Wall, Player and enemies derived
class GameEntity{
protected:
    sf::Shape *body;
    sf::Vector2f size;
    
    // put size values for the shape in here, so i guess:
    // set these vals to whatever it is when you initialise in each constructor
    // 
    
    // sf::RectangleShape* body; // okay so having a body doesn't work either
public:

    // virtual destructor 
    virtual ~GameEntity();

    // move body on screen
    void move(float x, float y);

    // draw function onto screen
    void draw(sf::RenderWindow *window);

    // returns 1 if two gameEntites overlap on screen
    bool overlaps(GameEntity *_entity); 

    // update function that all child classes should have 
    virtual void update(std::vector <GameEntity *>* gameEnts)=0;

    // returns the type of GameEntity in a string format
    virtual std::string getType()=0;

    
};

#endif