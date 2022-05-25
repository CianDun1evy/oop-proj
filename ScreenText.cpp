#include<SFML/Graphics.hpp>
#include<iostream>

#include "ScreenText.h"

ScreenText::ScreenText(std::string fontfile, std::string text,int charsize,int x, int y, sf::Color colour){
    std::cout<<"making screen text"<<std::endl;
    
    this->screenFont.loadFromFile(fontfile);
    std::cout<<"read from font"<<std::endl;
    screenText.setFont(screenFont);
    this->screenText.setString(text);
    this->screenText.setCharacterSize(charsize);
    this->screenText.setPosition(x, y);
    this->screenText.setFillColor(colour);
    std::cout<<"Screen Text made"<<std::endl;

}

ScreenText::~ScreenText(){
    
}

void ScreenText::draw(sf::RenderWindow* window){
    window->draw(screenText);
}
