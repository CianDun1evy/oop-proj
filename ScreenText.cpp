#include<SFML/Graphics.hpp>
#include<iostream>

#include "ScreenText.h"

ScreenText::ScreenText(std::string fontfile, std::string text,int charsize,int x, int y, sf::Color colour){
    
    screenText = new sf::Text;
    sf::Font font;
    font.loadFromFile(fontfile);

    this->screenText->setFont(font);
    this->screenText->setString(text);
    this->screenText->setCharacterSize(charsize);
    this->screenText->setPosition(x, y);
    this->screenText->setFillColor(colour);
    std::cout<<"Screen Text made"<<std::endl;
}

ScreenText::~ScreenText(){
    delete this->screenText;
}

void ScreenText::draw(sf::RenderWindow* window){
    window->draw(*screenText);
}
