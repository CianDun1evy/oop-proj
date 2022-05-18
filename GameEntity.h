
#ifndef GAMEENTITY_H
#define GAMEENTITY_H 

#include<iostream>
#include<SFML/Graphics.hpp>


class GameEntity{
    protected:
        sf::Shape *body;
 // sf::RectangleShape* body; // okay so having a body doesn't work either
    public:
        void move(int x, int y);

        //virtual void update()=0;

        bool overlaps(GameEntity* _e);//std::vector<GameEntity *> gameEntities; // that should be input
  
    
};


#endif