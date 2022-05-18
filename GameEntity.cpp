#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include "Game.h"


void GameEntity::move(int x, int y){ 
            // could make this look more complex
            this->body->move(x,y);
            //std::cout<<"body moved!"<<std::endl;
        }



// OVERLAP DETECTION --> COLLISIONS

/*// overlaps should take a Shape vector as input
 (can take list of enemies vector and list of walls vector
  - maybe split into vert walls and horiz walls)

  std::vector<GameEntity *> gameEntities; // that should be input type?
*/
bool GameEntity::overlaps(GameEntity* _enemy){ // this should then become a vector/array of enemies, and then also used for walls 
    
   // std::cout<<"overlaps running"<<std::endl;

    sf::Vector2f p1pose= this->body->getPosition();
    sf::Vector2f epose= _enemy->body->getPosition();

    
    int pxmax,pxmin,pymax,pymin;

    
    int exmax,exmin,eymax,eymin;

    // for now, +15, but in future have this be specific to each Game Entity object
    pxmax=p1pose.x+15;   //this->body->getLength();// add getLength to GameEntity  
    pxmin=p1pose.x-15;
    pymax=p1pose.y+15;   
    pymin=p1pose.y-15;

    // for the future vector/array of enemies, have for loop do this and test simultaneously

    exmax=epose.x+15;
    exmin=epose.x-15;
    eymax=epose.y+15;   
    eymin=epose.y-15;
    // if overlap, return 1, else:

    /* this if statement currently only looks at the player box overlapping with
        the enemies center point, this will be expanded to see if player box overlaps with enemy box (from exmax etc)
    */
    if (pxmin<=epose.x && epose.x<=pxmax && (pymin<=epose.y && epose.y<=pymax)){
        
        std::cout<<"COLLISION!!!"<<std::endl;
        _enemy->body->setFillColor(sf::Color::Green);
        return 1;
    }
    
    else{
       // std::cout<<"no collision ay"<<std::endl;
        return 0;
        }
}