// This is OOP's Hardest Game
// this is the main function

#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Game.h"
#include "Player.h"
#include "Walls.h"



int main(){
    Game GAM(960, 540,"daddy");
    
    GAM.run();
    
    return 0;
}
