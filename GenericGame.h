#pragma once

#ifndef GENERICGAME_H
#define GENERICGAME_H

#include <SFML/Graphics.hpp>

// All Games using SFML Graphics will require a window and a run function

class GenericGame{
    protected:
        // Pointer to Game Window
        sf::RenderWindow *window;
    public:
        // Run function, runs the base game
        virtual void run()=0;
};

#endif