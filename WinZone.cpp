#include "WinZone.h"


WinZone::WinZone(float length,float breadth, int x, int y){

    this->size = sf::Vector2f(length,breadth);

    body = new sf::RectangleShape(sf::Vector2f(length,breadth)); // (35,100)
    body->setOrigin(sf::Vector2f(length/2,breadth/2));
    body->setPosition(sf::Vector2f(x,y));//(960-15,540/2));
    body->setFillColor(sf::Color::Green);
    std::cout<<"WinZone initialised"<<std::endl;
}

// just make constructors for rest

// Destructor
WinZone::~WinZone(){
    delete this->body;
    std::cout<<"Wall destructor called"<<std::endl;
}

// return class type
std::string WinZone::getType(){
    return "WinZone";
}
void WinZone::update(std::vector <GameEntity *>* gameEnts){
    // do nothing
}