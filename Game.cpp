
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include "Game.h"
#include "Enemy.h"

Game::Game(int x, int y, std::string title)
{

    // Initialise Game Window
    window = new sf::RenderWindow(sf::VideoMode(x, y), title);

    // Initialise Players
    player1 = new Player(20, 96, 54, sf::Color::Green);
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
    e1 = new Enemy(1);
    e2 = new Enemy(2);
    e3 = new Enemy(3);
    e4 = new Enemy(4);
    e5 = new Enemy(5);
    e6 = new Enemy(6);
    e7 = new Enemy(7);
    e8 = new Enemy(8);
    e9 = new Enemy(9);
    e10 = new Enemy(10);

    // gameEntities.push_back(player);

    // // delete this:
    // shape1 = new sf::CircleShape(15.f);
    // shape1->setOrigin(sf::Vector2f(15,15));
    // shape1->setPosition(sf::Vector2f(480,270));
}

void Game::run()
{
    while (window->isOpen())
    {

        // handles closing the window manually
        sf::Event e;
        while (window->pollEvent(e))
        {

            if (e.type == sf::Event::Closed)
            { // instead of Closed, this can be key pressed, MouseWheelScrolled
                window->close();
                std::cout << "window closed" << std::endl;
            }
        }

        // update function updates all
        // void update(){
        //     for (int i =0;i<gameEntities.size();i++){
        //         GameEntity* current = gameEntities.at(i);
        //         current->update();
        //     }
        // }
        
        // Player 1 movement
        player1->inputmove(0);


        // Player 2 movement
        player2->inputmove(1);
    
        // Enemy
        while (window->pollEvent(e)) // collision detection likely affected by this loop (or maybe not idk, currently not super consistent respawn)
        {

            this->e1->move(0, -1);
            this->e2->move(0, 1);
            this->e3->move(0, -1);
            this->e4->move(0, 1);
            this->e5->move(0, -1);
            this->e6->move(0, 1);
            this->e7->move(0, -1);
            this->e8->move(0, 1);
            this->e9->move(0, -1);
            //this->e10->move(0, 1); // commented for testing purposes
        }


        // BASIC UNFINISHED COLLISION DETECTION (will be made into a vector input format)
        // this->player1->overlaps(e1);
        // this->player1->overlaps(e2);
        // this->player1->overlaps(e3);
        // this->player1->overlaps(e4);
        // this->player1->overlaps(e5);
        // this->player1->overlaps(e6);
        // this->player1->overlaps(e7);
        // this->player1->overlaps(e8);
        // this->player1->overlaps(e9);
        // this->player1->overlaps(e10);

        // DEATH -- respawn player1 if they overlap with an enemy (ofc inefficient rn)
        this->player1->respawn(100,200,e1);
        this->player1->respawn(100,200,e2);
        this->player1->respawn(100,200,e3);
        this->player1->respawn(100,200,e4);
        this->player1->respawn(100,200,e5);
        this->player1->respawn(100,200,e6);
        this->player1->respawn(100,200,e7);
        this->player1->respawn(100,200,e8);
        this->player1->respawn(100,200,e9);
        this->player1->respawn(100,200,e10);

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
        e1->draw(window);
        e2->draw(window);
        e3->draw(window);
        e4->draw(window);
        e5->draw(window);
        e6->draw(window);
        e7->draw(window);
        e8->draw(window);
        e9->draw(window);
        e10->draw(window);

        window->display();
    }
}