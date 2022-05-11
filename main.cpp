#include <SFML/Graphics.hpp>
#include<iostream>
//#include<ctime>

//using namespace sf;

// This is how to do it I reckon, but would have to define every object in terms of shape etc. idk maybe not best, we'll see I guess
class Shape{
    sf::CircleShape circle;
    sf::RectangleShape rectangle;
};

//void movex(Shape &a,int pix){ // pix is how many pixels to move, in either negative or positive direction
//     sf::Vector2f pose = a.getPosition();
//     pose.x+=pix;
//     a.setPosition(pose);
// }


//FUNCTIONS 
void movex(sf::CircleShape &a,int pix){ // pix is how many pixels to move, in either negative or positive direction
    sf::Vector2f pose = a.getPosition();
    pose.x+=pix;
    a.setPosition(pose);
}

// could just overload the function? but is uneccesry
void movex(sf::RectangleShape &a,int pix){ // pix is how many pixels to move, in either negative or positive direction
    sf::Vector2f pose = a.getPosition();
    pose.x+=pix;
    a.setPosition(pose);
}

void movey(sf::CircleShape &a,int pix){
    sf::Vector2f pose = a.getPosition();
    pose.y+=pix;
    a.setPosition(pose);
}
void movey(sf::RectangleShape &a,int pix){
    sf::Vector2f pose = a.getPosition();
    pose.y+=pix;
    a.setPosition(pose);
}

bool collision(sf::CircleShape &a,sf::RectangleShape &b){ // this works, except it's far too precise 
    if (a.getPosition()==b.getPosition() ){
        std::cout<<"Collision!"<<std::endl;
        return 1;
    }else{return 0;}
}

int main(){

    //important that aspect ratio of window is same as screen resolution, otherwise fullscreen bad
    sf::RenderWindow GameWindow( sf::VideoMode(960, 540), "Test Game!"); // screen res is 1920 x 1080, this is 1/2 aspect ratio
    int radius = 15;

    sf::CircleShape shape1( 15.f);// 50 = radius i think  // not sure how rectangles work so I'll stick with circle for now
    
    shape1.setFillColor(sf::Color::Cyan);
    shape1.setOutlineColor(sf::Color::Magenta); shape1.setOutlineThickness(5);
    shape1.setOrigin(sf::Vector2f(radius,radius));
    shape1.setPosition(sf::Vector2f(480,270));

    sf::RectangleShape shape2(sf::Vector2f(100,100));
    shape2.setOrigin(sf::Vector2f(50,50));
    shape2.setPosition(sf::Vector2f(100,100));
   // int x=-5;
    // int y=-5;
    int speed = 1; // num pixels to change in movement

// TO DO: LEARN THE DELTA TIME STUFF IF I WANT SMOOTH GAMEPLAY -- NOT NECESSARY THO -- NOT NECESSARY, SMOOTH MOVEMENT ACHIEVED IF MOVEMENT IS IN "while (GameWindow.isOpen()){", NOT the Event loop. that is laggy and slow
    //delta time stuff to stop jittering and annoying movement: (saw this in youtube tutorial). This stuff should be in a class. This guy made a class called "Game" which contains initialising window etc
    // sf::Clock dtClock;
    // float dt;
    // //Function .. //COOL THING WHEN IN HEADER FILE. IN HEADER FILE, WHILE HOVERING OVER DO "ctrl . enter" and it'll take you from .h to .cpp
    // void updateDT();

    while (GameWindow.isOpen()){
        
        sf::Event eventy;
        while (GameWindow.pollEvent(eventy)){

            if (eventy.type==sf::Event::Closed){ // instead of Closed, this can be key pressed, MouseWheelScrolled
                GameWindow.close();
            }
        }
            // put this in it's own class  // MOVEMENT or maybe just in class GameEntity. have movex, movey, or move_left,right,up,down. should have a speed input otherwise it's gonna be a pain

            // LEFT
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                // left key is pressed: move our character
               // shape1.move(-5.f, 0.f); // the following code just does the same thing as shape1.move, so might want to just use move. don't see any advantage yet to not
                movex(shape1,-speed);
            }
            // RIGHT
             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                // left key is pressed: move our character
                movex(shape1,speed);

            } 
            //UP
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                // left key is pressed: move our character
                movey(shape1,-speed);

            }
            //down
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                // left key is pressed: move our character
                movey(shape1,speed);
            }
        
    
        // if (eventy.type==Event::KeyPressed){
        //     shape1.setPosition(Vector2f(-100,-100));
        // }

        collision(shape1,shape2);

        GameWindow.clear();
        GameWindow.draw(shape2);
        GameWindow.draw(shape1);

        GameWindow.display();

    }

  
    
    return 0;
} 