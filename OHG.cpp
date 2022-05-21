// This is OOP's Hardest Game
// this is the main function

// made by Cian, Simran and Jyo

#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Game.h"
#include "Player.h"
#include "Walls.h"



int main(){
    Game GAM(960, 540,"daddy");
    
    GAM.welcome();
    //GAM.run();
    //GAM.result();
    return 0;
}
