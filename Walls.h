#ifndef WALLS_H
#define WALLS_H 
#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Game.h"
#include "Player.h"

class Walls:public GameEntity{
    protected:
        
        // int WallPos[10][4]; // data for 10 enemies with the 4 Constructor parameters to be stored


    public:
        Walls(float length,float breadth, int x, int y);

        // void getWallPositions(int row, int col,std::string positionfile); // maybe have WallsPos more ambiguous
    //   ~Walls();
};


#endif