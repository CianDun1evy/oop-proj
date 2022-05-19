
#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <iostream>
#include <SFML/Graphics.hpp>

class GameEntity{
protected:
    sf::Shape *body;
    // sf::RectangleShape* body; // okay so having a body doesn't work either
public:
    void move(int x, int y);

    void draw(sf::RenderWindow *window);

    // have draw func in here
    // void draw(sf::RenderWindow *window);

    // virtual void update()=0;

    bool overlaps(GameEntity *_e); // std::vector<GameEntity *> gameEntities; // that should be input

    // draw the game entity to the window
};

#endif