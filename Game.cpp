
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include "Game.h"
#include "Enemy.h"

Game::Game(int x, int y, std::string title){

    // Initialise Game Window
    window = new sf::RenderWindow(sf::VideoMode(x, y), title);

    // Initialise Players
    player1 = new Player(20, 96, 54, sf::Color::Red);
    player2 = new Player(20, 864, 486, sf::Color::Cyan);

    // Initialise Walls
    boundary_top = new Walls(960, 15, 960 / 2, 15 / 2);
    boundary_bottom = new Walls(960, 15, 960 / 2, 540 - 15 / 2);
    boundary_left = new Walls(15, 540, 15 / 2, 540 / 2);
    boundary_right = new Walls(15, 540, 960 - 15 / 2, 540 / 2);
    wall11 = new Walls(5, 378, 192, 378 / 2);
    wall21 = new Walls(5, 108, 736, 108 / 2);
    wall12 = new Walls(5, 108, 192, 486);
    wall22 = new Walls(5, 378, 736, 351);


    // Enemy    
    for (int i=0;i<10;i++){
        Enemy *temp;
        temp=new Enemy(i);
        enemylist.push_back(temp);

        gameEntities.push_back(temp);
    }

    gameEntities.push_back(player1);
    gameEntities.push_back(player2);
}

void Game::run()
{
    while (window->isOpen())
    {

        // handles closing the window manually
        sf::Event e;
        while (window->pollEvent(e)){
            if (e.type == sf::Event::Closed)
            { // instead of Closed, this can be key pressed, MouseWheelScrolled
                window->close();
                std::cout << "window closed" << std::endl;
            }
        }

        // Player 1 and 2 movement
        player1->inputmove(0);
        player2->inputmove(1);
    
        // Enemy
        while (window->pollEvent(e)){ // collision detection likely affected by this loop (or maybe not idk, currently not super consistent respawn)
        
            for (int i=0;i<enemylist.size();i++){
                
                this->enemylist[i]->move(0,1+(-2)*(i%2));
            }
        }


        // update(); // input delta time

        window->clear();

        for (int i=0;i<enemylist.size();i++){
                
            this->player1->respawn(100,200,enemylist[i]);
            this->player2->respawn(860,200,enemylist[i]);
        }

        // Draws Game Entities onto window (players, enemies, walls, etc)
        for (int i =0;i<gameEntities.size();i++){
            gameEntities[i]->draw(window);
        }

        // drawing players and walls onto window


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