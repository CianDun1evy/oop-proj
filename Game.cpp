
#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include "Game.h"

Game::Game(int x,int y,std::string title){

            // Initialise Game Window
            window = new sf::RenderWindow(sf::VideoMode(x,y),title);

            // Initialise Players
            player1 = new Player(20,96,54);
            player2 = new Player(20,864,486);

            // Initialise Walls
            boundary_top = new Walls(960,15, 960/2,15/2);
            boundary_bottom = new Walls(960,15, 960/2,540-15/2);
            boundary_left = new Walls(15,540, 15/2,540/2);
            boundary_right = new Walls(15,540, 960-15/2,540/2);
            wall11 = new Walls(5,378, 192,378/2);
            wall21 = new Walls(5,108, 736,108/2);
            wall12 = new Walls(5,108, 192,486);
            wall22 = new Walls(5,378, 736,351);



           // gameEntities.push_back(player);

            // // delete this:
            // shape1 = new sf::CircleShape(15.f);
            // shape1->setOrigin(sf::Vector2f(15,15));
            // shape1->setPosition(sf::Vector2f(480,270));
        }


void Game::run()        {
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

                // Player 1
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    this->player1->move(-1,0);
                    std::cout<<"A or left keyboard pressed"<<std::endl;
                }   
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    this->player1->move(1,0);
                    std::cout<<"D or right keyboard pressed"<<std::endl;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                    this->player1->move(0,-1);
                    std::cout<<"W or up keyboard pressed"<<std::endl;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                    this->player1->move(0,1);
                    std::cout<<"S or down keyboard pressed"<<std::endl;
                }

                //Player 2
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                    this->player2->move(-1,0);
                    std::cout<<"A or left keyboard pressed"<<std::endl;
                }   
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                    this->player2->move(1,0);
                    std::cout<<"D or right keyboard pressed"<<std::endl;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                    this->player2->move(0,-1);
                    std::cout<<"W or up keyboard pressed"<<std::endl;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                    this->player2->move(0,1);
                    std::cout<<"S or down keyboard pressed"<<std::endl;
                }

               // update(); // input delta time
                
                window->clear();

                // drawing players and walls onto window
                player1->draw(window);
                player2->draw(window);
                boundary_top->draw(window);
                boundary_bottom->draw(window);
                boundary_left->draw(window);
                boundary_right->draw(window);
                wall11->draw(window);
                wall21->draw(window);
                wall12->draw(window);
                wall22->draw(window);
                
                window->display();
            }
        }