
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include "Game.h"
#include "Enemy.h"
#include "Walls.h"
#include<fstream>
#include<vector>

Game::Game(int x, int y, std::string title){
    
    // Initialise Game Window
    window = new sf::RenderWindow(sf::VideoMode(x, y), title);

    // Initialise Players - probs only do 1 player (or have that as user input in menu, choose either 1 or two players)
    player1 = new Player(20, 100, 200, sf::Color::Red);
    player2 = new Player(20, 150, 200, sf::Color::Cyan);
    gameEntities.push_back(player1);
    gameEntities.push_back(player2);

    // Enemy INITIALISATION   
    for (int i=0;i<10;i++){
        Enemy *temp;
        temp = new Enemy(i);
        enemylist.push_back(temp);

        gameEntities.push_back(temp);
    }   

    std::cout<<"gonna get wall data"<<std::endl;
    this->setWallPositionsData(8,4,"WallPos.txt");
    std::cout<<"got wall data"<<std::endl;

    
    for (int i=0;i<8;i++){
        Walls *temp1;
        temp1 = new Walls(WallPos[i][0],WallPos[i][1],WallPos[i][2],WallPos[i][3]);
        //temp1 = new Walls(10,10,10,10);
        wall_list.push_back(temp1);
        gameEntities.push_back(temp1);
        std::cout<<"oki doki again "<<std::endl;
    }
    std::cout<<"biiing booong"<<std::endl;
}

Game::~Game(){
    // delete [] player1;
    // delete [] player2;
    
    // delete [] wall_list;
    // delete [] enemylist;
    // delete [] gameEntities;
}


void Game::run(){   

    std::cout<<"started running game"<<std::endl;

    while (window->isOpen()){

        // handles closing the window manually
        sf::Event e;
        while (window->pollEvent(e)){
            if (e.type == sf::Event::Closed)
            { // instead of Closed, this can be key pressed, MouseWheelScrolled
                window->close();
                std::cout << "window closed" << std::endl;
            }
        }
        std::cout<<"checked window closed"<<std::endl;

        // Player 1 and 2 movement
        player1->inputmove(0);
        player2->inputmove(1);
        std::cout<<"players can move"<<std::endl;

        // ENEMY AUTONOMOUS MOVEMENT:
        for (int i=0;i<enemylist.size()-4;i++){
            this->enemylist[i]->move(0,0.01+(-0.1)*(i%2));
        }
        for (int i=enemylist.size()-4;i<enemylist.size()-1;i++){
            this->enemylist[i]->move(0.05+(-0.1)*(i%2),0);
        }
        std::cout<<"enemies move"<<std::endl;



        // update(); // input delta time

        window->clear();

        // RESPAWN UPON COLLISION WITH ENEMIES AND WALLS
        for (int i=0;i<enemylist.size();i++){
            // respawn if touch enemy or wall
            this->player1->respawn(100,200,enemylist[i]);

            this->player2->respawn(150,200,enemylist[i]);
        }
        std::cout<<"touching enemies kills"<<std::endl;
        
        for (int i=0;i<wall_list.size();i++){
            // respawn if touch enemy or wall
            this->player1->respawn(100,200,wall_list[i]);

            this->player2->respawn(150,200,wall_list[i]);
        }
        std::cout<<"touching walls kills"<<std::endl;



        // Draws Game Entities onto window (players, enemies, walls, etc)
        for (int i =0;i<gameEntities.size();i++){
            gameEntities[i]->draw(window);
        }
        std::cout<<"game ents drawn"<<std::endl;

        // drawing players and walls onto window


        // boundary_top->draw(window);
        // boundary_bottom->draw(window);
        // boundary_left->draw(window);
        // boundary_right->draw(window);
        // wall11->draw(window);
        // wall21->draw(window);
        // wall12->draw(window);
        // wall22->draw(window);

        window->display();
    }
}


void Game::setWallPositionsData(int row,int col,std::string posfile){

    // import file 
    
    std::cout<< "boobs"<<std::endl;
   std::ifstream inputfile(posfile);
    for (int i=0;i<row;i++){
        for( int j = 0;j<col;j++){
            // this->WallPos[i][j]=0;
            this->WallPos[i][j]=20;
        }
    }
    std::cout<< "boobieeeeees"<<std::endl;

    // check if file exists, or if it is usable
    if (!inputfile.is_open()){

        std::cout<<"There was an error opening file"<<std::endl;
        
        // if error, set all values to 0;
        for (int i=0;i<row;i++){
            for (int j=0;j<4;j++){ 
                WallPos[i][j]=0;
            }
        }
    }
    
    // get input from file into Wall if no errors 
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            inputfile >> WallPos[i][j];  //Take input from file and put into WallPos
        }
    }
    
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            std::cout<< WallPos[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}



// WALL INITIALISATION

      // boundary_top = new Walls(960, 15, 960 / 2, 15 / 2);
    // boundary_bottom = new Walls(960, 15, 960 / 2, 540 - 15 / 2);
    // boundary_left = new Walls(15, 540, 15 / 2, 540 / 2);
    // boundary_right = new Walls(15, 540, 960 - 15 / 2, 540 / 2);
    // wall11 = new Walls(5, 378, 192, 378 / 2);
    // wall21 = new Walls(5, 108, 736, 108 / 2);
    // wall12 = new Walls(5, 108, 192, 486);
    // wall22 = new Walls(5, 378, 736, 351);