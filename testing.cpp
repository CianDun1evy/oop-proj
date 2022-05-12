#include <SFML/Graphics.hpp>
#include<iostream>
//#include<ctime>

//using namespace sf;

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

// bool collision(sf::CircleShape &a,sf::RectangleShape &b){ // this works, except it's far too precise   
//     if (a.getPosition()==b.getPosition() ){
//         std::cout<<"Collision!"<<std::endl;
//         return 1;
    
//     if (a.getPosition())
//     }else{return 0;}
// }


bool collision(sf::CircleShape &a,sf::RectangleShape &b){ // this works, except it's far too precise   
    if ((a.getPosition().x)/(b.getPosition().x)<1.05 && (a.getPosition().y)/(b.getPosition().y)<1.05){
        std::cout<<"Collision!"<<std::endl;
        std::cout<<(a.getPosition().x)/(b.getPosition().x)<<std::endl;
        std::cout<<(a.getPosition().y)/(b.getPosition().y)<<std::endl;

        return 0;
}else{return 1;}
}




// bool collision(sf::CircleShape &a,sf::RectangleShape &b){ // this works, except it's far too precise   
//     if ((a.getPosition().x)/(b.getPosition().x)>0.95 && (a.getPosition().x)/(b.getPosition().x)<1.05) || ((a.getPosition().y)/(b.getPosition().y)>0.95 && (a.getPosition().y)/(b.getPosition().y)<1.05) {
//         std::cout<<"Collision!"<<std::endl;
//         std::cout<<(a.getPosition().y)/(b.getPosition().y)<<std::endl;
//         std::cout<<(a.getPosition().x)/(b.getPosition().x)<<std::endl;
//     } 
//         return 1;
// }else{return 0;}
// }




int main(){

    //important that aspect ratio of window is same as screen resolution, otherwise fullscreen bad
    sf::RenderWindow GameWindow( sf::VideoMode(960, 540), "Test Game!"); // screen res is 1920 x 1080, this is 1/2 aspect ratio
    int radius = 15;

    sf::CircleShape shape1( 15.f);// 50 = radius i think  // not sure how rectangles work so I'll stick with circle for now
    
    shape1.setFillColor(sf::Color::Cyan);
    shape1.setOutlineColor(sf::Color::Magenta); shape1.setOutlineThickness(5);
    shape1.setOrigin(sf::Vector2f(radius,radius));
    shape1.setPosition(sf::Vector2f(480,270));

    sf::RectangleShape shape2(sf::Vector2f(50,50));
    shape2.setOrigin(sf::Vector2f(50,50));
    shape2.setPosition(sf::Vector2f(100,100));

    int speed = 1; // num pixels to change in movement


    while (GameWindow.isOpen()){
        
        sf::Event eventy;
        while (GameWindow.pollEvent(eventy)){

            if ((eventy.type==sf::Event::Closed ) || ( collision(shape1,shape2)!=1)){ // instead of Closed, this can be key pressed, MouseWheelScrolled
                std::cout<<"boob"<<std::endl;
                GameWindow.close();
            }
        }

            // LEFT
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                
                movex(shape1,-speed);
            }
            // RIGHT
             if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                // left key is pressed: move our character
                movex(shape1,speed);

            } 
            //UP
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                // left key is pressed: move our character
                movey(shape1,-speed);

            }
            //down
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                // left key is pressed: move our character
                movey(shape1,speed);
            }


            //shape 2
            // LEFT
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
              movex(shape2,-speed);
            }
            // RIGHT
             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){ 
                movex(shape2,speed);
            } 
            //UP
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ){
                // left key is pressed: move our character
                movey(shape2,-speed);

            }
            //down
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                // left key is pressed: move our character
                movey(shape2,speed);
            }

        //collision(shape1,shape2);

        GameWindow.clear();
        GameWindow.draw(shape2);
        GameWindow.draw(shape1);

        GameWindow.display();

    }

  
    
    return 0;
} 