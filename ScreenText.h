#pragma once

#ifndef SCREENTEXT_H
#define SCREENTEXT_H

#include<SFML/Graphics.hpp>
#include<string>

class ScreenText{
    protected:
        sf::Text screenText;
    public:
        // constructor
        ScreenText(std::string fontfile, std::string text,int charsize,int x, int y, sf::Color colour);

        ~ScreenText();

        sf::Text getText();  
};


#endif