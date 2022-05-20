#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include "Game.h"


void GameEntity::move(float x, float y){ 
            // could make this look more complex
            this->body->move(x,y);
            //std::cout<<"body moved!"<<std::endl;
        }

void GameEntity::draw(sf::RenderWindow *window){
    window->draw(*body);    
//std::cout<<"drawn!"<<std::endl;

}



// OVERLAP DETECTION --> COLLISIONS

/*// overlaps should take a Shape vector as input
 (can take list of enemies vector and list of walls vector
  - maybe split into vert walls and horiz walls)

  std::vector<GameEntity *> gameEntities; // that should be input type?
*/
bool GameEntity::overlaps(GameEntity* entity){ // this should then become a vector/array of enemies, and then also used for walls 
    
   // std::cout<<"overlaps running"<<std::endl;

    sf::Vector2f p1pose= this->body->getPosition();
    sf::Vector2f epose= entity->body->getPosition();

    sf::Vector2f entsize = entity->size;
    // trying aabb collision 
    if ( abs(p1pose.x - epose.x) < ((this->size.x+entsize.x)/2)){ // 10 + 10 -> player->getSize().x + enemy->getSize().x
        if ( abs(p1pose.y - epose.y) < ((this->size.y+entsize.y)/2)){

            std::cout<<"COLLISION!!!"<<std::endl;

            return 1;
        }else{
            return 0;
            }
    }  

    else{
      //  std::cout<<"no collision ay"<<std::endl;
        return 0;
    }
}

