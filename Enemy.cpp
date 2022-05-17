#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include "Game.h"
#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy(int pos) {
x = 192 + (50*pos);
y = (rand()%450+50) ;
body = new sf::RectangleShape(sf::Vector2f(40,40));
body->setOrigin(sf::Vector2f(25,25));
body->setPosition(sf::Vector2f(x,y));
body->setFillColor(sf::Color::Yellow);
std::cout<<"player initialised"<<std::endl;
}

void Enemy::draw(sf::RenderWindow *window){
window->draw(*body); 
//std::cout<<"drawn!"<<std::endl;

}
