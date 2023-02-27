#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode(1600, 1200), "Flappy Bird");

    // Set the frame rate
    window.setFramerateLimit(60);

    // Load the font
    sf::Font font;
    if (!font.loadFromFile("gothicb.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
        return -10;
    } 

    // Create the score text
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setPosition(10, 10);

    // Load the background texture
    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("munt.png"))
    {
        std::cout << "Error loading texture" << std::endl;
        return -1;
    }

    // Create the background sprite
    sf::Sprite background;
    background.setTexture(bgTexture);

    // Load the pipe texture
    sf::Texture pipeTexture;
    if (!pipeTexture.loadFromFile("pipe.png"))
    {
        std::cout << "Error loading texture" << std::endl;
        return -1;
    }

    // Create the pipes
    const int numPipes = 4;
    sf::Sprite pipes[numPipes];
    float pipeX = 800;
    float pipeY = 0;
    float pipeGap = 200;
    for (int i = 0; i < numPipes; i++)
    {
        pipes[i].setTexture(pipeTexture);
        pipes[i].setPosition(pipeX, pipeY);
        pipeY = (i % 2 == 0) ? 0 : window.getSize().y - pipes[i].getLocalBounds().height - pipeGap;
        pipeX += 300;
    }

    // Load the bird texture
    sf::Texture birdTexture;
    if (!birdTexture.loadFromFile("bird.png"))
    {
        std::cout << "Error loading texture" << std::endl;
        return -1;
    }

    // Create the bird sprite
    sf::Sprite bird;
    bird.setTexture(birdTexture);
    bird.setPosition(100, window.getSize().y / 2);

    // Set the bird's velocity
    float birdVelocity = 0;
    float gravity = 0.5f;

    // Set the score
    int score = 0;

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
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    // Flap the bird
                    birdVelocity = -10;
                }
            }
        }

        // Update the bird's position
        birdVelocity += gravity;
        bird.move(0, birdVelocity);

        // Check for collision with the pipes
        for (int i = 0; i < numPipes; i++)
        {
            if (bird.getGlobalBounds().intersects(pipes[i].getGlobalBounds()))
            {
                // Game over
                std::cout << "Game over! Final score: " << score << std::endl;
                window.close();
            }
        }

        // Update the pipes' position
        for (int i = 0; i < numPipes; i++)
        {
    pipes[i].move(-5, 0);

    // If the pipe is offscreen, reset its position and increment the score
    if (pipes[i].getPosition().x < -pipes[i].getLocalBounds().width)
    {
        pipes[i].setPosition(window.getSize().x, pipes[i].getPosition().y);
        score++;
    }
}

// Update the score text
scoreText.setString("Score: " + std::to_string(score));

// Clear the window
window.clear();

// Draw the background
window.draw(background);

// Draw the pipes
for (int i = 0; i < numPipes; i++)
{
    window.draw(pipes[i]);
}

// Draw the bird
window.draw(bird);

// Draw the score text
window.draw(scoreText);

// Display the window
window.display();
}

return 0;
}
