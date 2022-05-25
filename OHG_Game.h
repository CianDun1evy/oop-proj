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
#include "WinZone.h"
#include "ScreenText.h"

#include "GenericGame.h"

class OHG_Game: public GenericGame { 
    // game runs straight from here
  protected:

    // Player team name and their number of deaths
    std::string teamName;
    int numDeaths;

    // Display tracking player number of deaths
    sf::Text displayDeaths;
    sf::Font deathFont;

    // number of players
    int numPlayers; 

    // Potential ingame players
    Player *player1;
    Player *player2;

    // Wall Position Data Array
    float WallPos[8][4]; 

    // a winzone, from which player contact results in winning the game
    WinZone * green1;
 
    // Vector containing Game Entities
    std::vector<GameEntity *> gameEntities; // add walls into a vector for easy looping through to detect for intersection


  public:
    // constructor
    OHG_Game(int x, int y, std::string title);
    
    // destructor
    ~OHG_Game();

    // run function from where main game takes place
    void run() override;

    // welcome screen function
    void welcomeScreen(); 
    
    // number of player selection screen
    void no_of_players(); 

    // input Team Name screen
    void inputName();

    // writes the end stats to a .txt file, ScoreData.txt
    void setScoreData();

    // win screen    
    void win();
    
    // sets wall position data in game
    void setWallPositionsData(int numWalls, int numparameters,std::string positionfile); // maybe have WallsPos more ambiguous
    
};
#endif

