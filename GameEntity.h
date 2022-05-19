
#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <iostream>
#include <SFML/Graphics.hpp>

class GameEntity{
protected:
    sf::Shape *body;

    // put size values for the shape in here, so i guess:
    // set these vals to whatever it is when you initialise in each constructor
    // 
    // int sizex,sizey;
    

    // sf::RectangleShape* body; // okay so having a body doesn't work either
public:
    void move(int x, int y);

    void draw(sf::RenderWindow *window);

    // virtual void update()=0;

    bool overlaps(GameEntity *_enemy); // std::vector<GameEntity *> gameEntities; // that should be input

    // sf::Vector2f getBodySize(){
    //     return sf::Vector2f(this->sizex,this->sizey);
    // }
};

#endif