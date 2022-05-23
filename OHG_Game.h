#pragma once

#ifndef OHG_GAME_H
#define OHG_GAME_H

#include <SFML/Graphics.hpp>
#include<fstream>
#include<vector>
#include <iostream>

#include "GameEntity.h"
#include "Player.h"
#include "Walls.h"
#include "Enemy.h"


#include "GenericGame.h"

class OHG_Game: public GenericGame { 
    // game runs straight from here
  protected:
    // sf::RenderWindow *window;
    // set refresh rate for window maybe 60

    int numDeaths;
    
    Player *player1;
    Player *player2;
  
    // std::vector<Player *> player_list;

    int numPlayers; // numPlayers
  
    
    // List of Walls
    // std::vector<Walls *> wall_list;

    float WallPos[8][4]; // data for 8 enemies with the 4 Constructor parameters to be stored

    // std::vector<std::vector<float> > WallPos;
    

    // List of Enemies
    // std::vector<Enemy *> enemylist; // add walls into a vector for easy looping through to detect for intersection

    // List of Game Entities
    std::vector<GameEntity *> gameEntities; // add walls into a vector for easy looping through to detect for intersection

  public:
    // constructor
    OHG_Game(int x, int y, std::string title);
    
    // destructor
    ~OHG_Game(); // have this as virtual?

    void run() override;

    void setWallPositionsData(int numWalls, int numparameters,std::string positionfile); // maybe have WallsPos more ambiguous
    void welcome();
    void menu(); // nothing here yet - delete
    void no_of_players();
    void controls(); // nothing here yet - delete
    
    void result();
};
#endif

// Hi

// Walls *boundary_top;
    // Walls *boundary_bottom;
    // Walls *boundary_left;
    // Walls *boundary_right;
    // Walls *wall11;
    // Walls *wall12;
    // Walls *wall21;
    // Walls *wall22;

      // Enemy *e1;
    // Enemy *e2;
    // Enemy *e3;
    // Enemy *e4;
    // Enemy *e5;
    // Enemy *e6;
    // Enemy *e7;
    // Enemy *e8;
    // Enemy *e9;
    // Enemy *e10;

       // or, as behaviour is different based on which collision happens

    // std::vector<GameEntity *> gameEnemies;
    // std::vector<GameEntity *> vertWalls; // maybe freeze x when vert and y when horiz? idk
    // std::vector<GameEntity *> horizWalls;