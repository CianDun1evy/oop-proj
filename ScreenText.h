#pragma once

#ifndef SCREENTEXT_H
#define SCREENTEXT_H

#include<SFML/Graphics.hpp>
#include<string>

class ScreenText{
    protected:
        sf::Text screenText;
        sf::Font screenFont;
    public:
        // constructor
        ScreenText(std::string fontfile, std::string text,int charsize,int x, int y, sf::Color colour);

        // destructor
        ~ScreenText();

        // draws onto screen  
        void draw(sf::RenderWindow *window);
};


#endif