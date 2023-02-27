#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

const int MAZE_WIDTH = 20;
const int MAZE_HEIGHT = 20;
const int CELL_SIZE = 30;

int main() {
    sf::RenderWindow window(sf::VideoMode(MAZE_WIDTH * CELL_SIZE, MAZE_HEIGHT * CELL_SIZE), "Maze Game");

    char maze[MAZE_HEIGHT][MAZE_WIDTH];

    std::ifstream file("maze.txt");
    if (!file.is_open()) {
        std::cout << "Failed to open maze file." << std::endl;
        return 1;
    }

    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            char c;
            file >> c;
            maze[i][j] = c;
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
    }

    int playerX = 1;
    int playerY = 1;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        int dx = 0;
        int dy = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            dx = -1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            dx = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            dy = -1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            dy = 1;
        }

        int newPlayerX = playerX + dx;
        int newPlayerY = playerY + dy;

        if (maze[newPlayerY][newPlayerX] != 'X') {
            playerX = newPlayerX;
            playerY = newPlayerY;
        }

        window.clear(sf::Color::White);

        for (int i = 0; i < MAZE_HEIGHT; i++) {
            for (int j = 0; j < MAZE_WIDTH; j++) {
                if (maze[i][j] == 'X') {
                    sf::RectangleShape wall(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                    wall.setFillColor(sf::Color::Black);
                    wall.setPosition(j * CELL_SIZE, i * CELL_SIZE);
                    window.draw(wall);
                }
            }
        }

        sf::CircleShape player(CELL_SIZE / 2);
        player.setFillColor(sf::Color::Red);
        player.setPosition(playerX * CELL_SIZE, playerY * CELL_SIZE + CELL_SIZE / 2);
        window.draw(player);

        window.display();
    }

    return 0;
}
