
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include "Game.h"
#include<fstream>
#include<iostream>

#include "Walls.h"

Walls::Walls(int length,int breadth, int x, int y){

    // store the size of the wall
    this->size = sf::Vector2f(length,breadth);

    body = new sf::RectangleShape(sf::Vector2f(length,breadth));
    body->setOrigin(sf::Vector2f(length/2,breadth/2));
    body->setPosition(sf::Vector2f(x,y));
    body->setFillColor(sf::Color::White);
    std::cout<<"Wall Initialised"<<std::endl;
        }


// void Walls::getWallPositions(int row,int col,std::string posfile){

//     // import file 
//     std::ifstream inputfile(posfile);
    
//     // check if file exists, or if it is usable
//     if (!inputfile.is_open()){

//         std::cout<<"There was an error opening file"<<std::endl;
        
//         // if error, set all values to 0;
//         for (int i=0;i<row;i++){
//             for (int j=0;j<4;j++){ 
//                 WallPos[i][j]=0;
//             }
//         }
//     }
    
//     // get input from file into Wall if no errors 
//     for (int i=0;i<row;i++){
//         for (int j=0;j<col;j++){
//             inputfile >> WallPos[i][j];  //Take input from file and put into WallPos
//         }
//     }
    
//     for (int i=0;i<row;i++){
//         for (int j=0;j<col;j++){
//             std::cout<< WallPos[i][j]<<" ";
//         }
//         std::cout<<std::endl;
//     }
// }