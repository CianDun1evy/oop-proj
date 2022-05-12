#include <SFML/Graphics.hpp>
#include <iostream>

void movex(sf::CircleShape &a, int pix)
{ // pix is how many pixels to move, in either negative or positive direction
    sf::Vector2f pose = a.getPosition();
    pose.x += pix;
    a.setPosition(pose);
}
void movex(sf::RectangleShape &a, int pix)
{ // pix is how many pixels to move, in either negative or positive direction
    sf::Vector2f pose = a.getPosition();
    pose.x += pix;
    a.setPosition(pose);
}
void movey(sf::CircleShape &a, int pix)
{
    sf::Vector2f pose = a.getPosition();
    pose.y += pix;
    a.setPosition(pose);
}
void movey(sf::RectangleShape &a, int pix)
{
    sf::Vector2f pose = a.getPosition();
    pose.y += pix;
    a.setPosition(pose);
}

bool collision(sf::CircleShape &a, sf::RectangleShape &b)
{   int ax = a.getPosition().x;
    int bx = b.getPosition().x;
    int ay = a.getPosition().y;
    int by = b.getPosition().y;

    if (abs(ax - bx) < 45 && abs(ay - by) < 45)
    {
        std::cout << "Collision!" << std::endl;
        std::cout << (a.getPosition().x) / (b.getPosition().x) << std::endl;
        std::cout << (a.getPosition().y) / (b.getPosition().y) << std::endl;

        return 0;
    }
    else
    {
        return 1;
    }

}


int main()
{
    //boundaries    
    sf::RectangleShape boundary_top(sf::Vector2f(3840, 30));
    boundary_top.setOrigin(sf::Vector2f(30, 30));
    boundary_top.setPosition(sf::Vector2f(0, 30));

    sf::RectangleShape boundary_left(sf::Vector2f(30, 2160));
    boundary_left.setOrigin(sf::Vector2f(30, 30));
    boundary_left.setPosition(sf::Vector2f(30, 0));

    sf::RectangleShape boundary_right(sf::Vector2f(30, 2160));
    boundary_right.setOrigin(sf::Vector2f(30, 30));
    boundary_right.setPosition(sf::Vector2f(1920, 0));

    sf::RectangleShape boundary_bottom(sf::Vector2f(3840, 30));
    boundary_bottom.setOrigin(sf::Vector2f(30, 30));
    boundary_bottom.setPosition(sf::Vector2f(0, 1020));

    //walls
    sf::RectangleShape wall_left1(sf::Vector2f(30, 800));
    wall_left1.setOrigin(sf::Vector2f(30, 30));
    wall_left1.setPosition(sf::Vector2f(500, 0));

    sf::RectangleShape wall_left2(sf::Vector2f(30, 2160));
    wall_left2.setOrigin(sf::Vector2f(30, 30));
    wall_left2.setPosition(sf::Vector2f(500, 900));

    sf::RectangleShape wall_right1(sf::Vector2f(30, 200));
    wall_right1.setOrigin(sf::Vector2f(30, 30));
    wall_right1.setPosition(sf::Vector2f(1450, 0));

    sf::RectangleShape wall_right2(sf::Vector2f(30, 900));
    wall_right2.setOrigin(sf::Vector2f(30, 30));
    wall_right2.setPosition(sf::Vector2f(1450, 300));


    // important that aspect ratio of window is same as screen resolution, otherwise fullscreen bad
    sf::RenderWindow GameWindow(sf::VideoMode(3840, 2160), "Test Game!");
    float radius = 15;
    sf::CircleShape shape1(radius); 
    shape1.setFillColor(sf::Color::Cyan);
    shape1.setOutlineColor(sf::Color::Magenta);
    shape1.setOutlineThickness(5);
    shape1.setOrigin(sf::Vector2f(radius, radius));
    shape1.setPosition(sf::Vector2f(200, 300));

    sf::RectangleShape shape2(sf::Vector2f(30, 30));
    shape2.setOrigin(sf::Vector2f(30, 30));
    shape2.setPosition(sf::Vector2f(1700, 800));
    shape2.setOutlineColor(sf::Color::Red);
    shape2.setOutlineThickness(5);
 


    int speed = 1; // num pixels to change in movement

    while (GameWindow.isOpen())
    {

        sf::Event eventy;
        while (GameWindow.pollEvent(eventy))
        {

            if ((eventy.type == sf::Event::Closed) || (collision(shape1, shape2) != 1))
            { // instead of Closed, this can be key pressed, MouseWheelScrolled
                std::cout << "Collision" << std::endl;
                GameWindow.close();
            }
        }
        
        // LEFT
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            movex(shape1, -speed);
        }
        // RIGHT
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            // left key is pressed: move our character
            movex(shape1, speed);
        }
        // UP
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            // left key is pressed: move our character
            movey(shape1, -speed);
        }
        // down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            // left key is pressed: move our character
            movey(shape1, speed);
        }

        // shape 2
        //  LEFT
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            movex(shape2, -speed);
        }
        // RIGHT
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            movex(shape2, speed);
        }
        // UP
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            // left key is pressed: move our character
            movey(shape2, -speed);
        }
        // down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            // left key is pressed: move our character
            movey(shape2, speed);
        }

        // collision(shape1,shape2);

        GameWindow.clear();
        GameWindow.draw(shape2);
        GameWindow.draw(shape1);
        GameWindow.draw(boundary_top);
        GameWindow.draw(boundary_left);
        GameWindow.draw(boundary_right);
        GameWindow.draw(boundary_bottom);
        GameWindow.draw(wall_left1);
        GameWindow.draw(wall_left2);
        GameWindow.draw(wall_right1);
        GameWindow.draw(wall_right2);


        GameWindow.display();
    }

    return 0;
}