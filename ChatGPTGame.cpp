#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <random>

using namespace std;

int main()
{
    // Set up the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "World's Hardest Game");

    // Set up the player
    sf::CircleShape player(20);
    player.setFillColor(sf::Color::Blue);
    player.setPosition(50, 50);

    // Set up the enemy
    sf::RectangleShape enemy(sf::Vector2f(40, 40));
    enemy.setFillColor(sf::Color::Red);
    enemy.setPosition(700, 500);

    // Set up the movement
    float speed = 0.5f;

    // Set up the bouncing balls
    const int numBalls = 10;
    sf::CircleShape balls[numBalls];
    for (int i = 0; i < numBalls; i++)
    {
        balls[i].setFillColor(sf::Color::Green);
        balls[i].setRadius(15.0f);

        // Generate random starting position for each ball
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> disX(50.0, 750.0);
        uniform_real_distribution<> disY(50.0, 550.0);
        balls[i].setPosition(disX(gen), disY(gen));
    }

    // Set up gravity and ball velocity
    float gravity = 0.01f;
    float ballVelocity = 0.0f;

    // Set up the maze
    const int numRows = 10;
    const int numCols = 12;
    const int wallSize = 50;
    sf::RectangleShape walls[numRows][numCols];
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            walls[i][j].setSize(sf::Vector2f(wallSize, wallSize));
            walls[i][j].setFillColor(sf::Color::Black);
            walls[i][j].setPosition(j * wallSize, i * wallSize);

            // Add some gaps in the walls
            if ((i == 1 && j != 3 && j != 4 && j != 7 && j != 8) ||
                (i == 2 && j != 2 && j != 3 && j != 4 && j != 7 && j != 8 && j != 9) ||
                (i == 3 && j != 4 && j != 7) ||
                (i == 4 && j != 2 && j != 3 && j != 4 && j != 7 && j != 8 && j != 9) ||
                (i == 5 && j != 3 && j != 4 && j != 7 && j != 8) ||
                (i == 6 && j != 2 && j != 3 && j != 4 && j != 7 && j != 8 && j != 9) ||
                (i == 7 && j != 4 && j != 7))
            {
                walls[i][j].setFillColor(sf::Color::White);
            }
        }
    }

    // Set up the end goal
    sf::CircleShape goal(20);
    goal.setFillColor(sf::Color::Green);
    goal.setPosition(700, 50);


    // Main game loop
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Move the player
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player.move(-speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            player.move(speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            player.move(0, -speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            player.move(0, speed);
        }

        // Move the bouncing balls and apply gravity
        for (int i = 0; i < numBalls; i++)
        {
            // Apply gravity
            ballVelocity += gravity * 0.01f;

            // Update the ball position
            balls[i].move(0, ballVelocity);

            // Bounce off the floor
            if (balls[i].getPosition().y + balls[i].getRadius() > 600)
            {
                ballVelocity = -sqrt(2 * gravity * balls[i].getRadius());
            }
        }

        // Check for collision with the player
        for (int i = 0; i < numBalls; i++)
        {
            if (player.getGlobalBounds().intersects(balls[i].getGlobalBounds()))
            {
                cout << "Game over!" << endl;
                window.close();
            }
        }

        // Check for collision with the enemy
        if (player.getGlobalBounds().intersects(enemy.getGlobalBounds()))
        {
            cout << "Game over!" << endl;
            window.close();
        }

        // Clear the screen
        window.clear(sf::Color::White);

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {

            window.draw(walls[i][j]);
        }
    }
    // Draw the player
    window.draw(player);

    // Draw the enemy
    window.draw(enemy);

    // Draw the bouncing balls
    for (int i = 0; i < numBalls; i++)
    {
        window.draw(balls[i]);
    }
    
    window.draw(goal);
    // Display the window
    window.display();
    }

    return 0;
}