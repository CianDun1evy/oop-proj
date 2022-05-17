
#ifndef GAME_H
#define GAME_H 
#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"

class Game: public GameEntity{
    // game runs straight from here
    protected:
        sf::RenderWindow *window;
        Player *player;
        
        sf::CircleShape *shape1; // delete this

        //std::vector<GameEntity *> gameEntities;

    public:
        Game(int x,int y,std::string title){
            window = new sf::RenderWindow(sf::VideoMode(x,y),title);
            player = new Player(50,420,520);

           // gameEntities.push_back(player);

            // delete this:
            shape1 = new sf::CircleShape(15.f);
            shape1->setOrigin(sf::Vector2f(15,15));
            shape1->setPosition(sf::Vector2f(480,270));
        }

        //~Game(){}

        void run(){
            while (window->isOpen()){
                
                // handles closing the window manually
                sf::Event e;
                while (window->pollEvent(e)){

                    if (e.type==sf::Event::Closed){ // instead of Closed, this can be key pressed, MouseWheelScrolled
                        window->close();
                        std::cout<<"window closed"<<std::endl;
                    }
                }
                
                 // update function updates all 
                // void update(){
                //     for (int i =0;i<gameEntities.size();i++){
                //         GameEntity* current = gameEntities.at(i);
                //         current->update();
                //     }
                // }

                 // LEFT
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    this->player->move(-1,0);
                    std::cout<<"A or left keyboard pressed"<<std::endl;
                }   
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    this->player->move(1,0);
                    std::cout<<"D or right keyboard pressed"<<std::endl;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                    this->player->move(0,-1);
                    std::cout<<"W or up keyboard pressed"<<std::endl;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                    this->player->move(0,1);
                    std::cout<<"S or down keyboard pressed"<<std::endl;
                }

               // update(); // input delta time
                
                window->clear();
                player->draw(window);

                window->draw(*shape1); // delete this
                
                window->display();
            }
        }
            
        
};
#endif