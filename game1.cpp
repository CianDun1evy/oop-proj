#include<iostream>
#include<SFML/Graphics.hpp>


// class GameEntity{
//     protected:
//  // sf::RectangleShape* body; // okay so having a body doesn't work either
//     public:
//         virtual void move(int x, int y){
//             // could make this look more complex
//             this->body->move(x,y);
//             std::cout<<"body moved!"<<std::endl;
//         }

// };

// class Player:public GameEntity{
class Player{
    protected:

        sf::RectangleShape *body;

    public:
        Player(int size, int x, int y){
            body = new sf::RectangleShape(sf::Vector2f(size,size));
            body->setOrigin(sf::Vector2f(size/2,size/2));
            body->setPosition(sf::Vector2f(x,y));
            body->setFillColor(sf::Color::Red);
            std::cout<<"player initialised"<<std::endl;

        }
       // Player(){}
        //~Player(){}

        void move(int x, int y){
            // could make this look more complex
            this->body->move(x,y);
            std::cout<<"body moved!"<<std::endl;
        }
        void draw(sf::RenderWindow *window){
            window->draw(*body); 
            //std::cout<<"drawn!"<<std::endl;

        }

};




class Game{
    // game runs straight from here
    protected:
        sf::RenderWindow *window;
        Player *player;
        
        sf::CircleShape *shape1; // delete this


    public:
        Game(int x,int y,std::string title){
            window = new sf::RenderWindow(sf::VideoMode(x,y),title);
            player = new Player(50,420,520);
         
            // delete this:
            shape1 = new sf::CircleShape(15.f);
            shape1->setOrigin(sf::Vector2f(15,15));
            shape1->setPosition(sf::Vector2f(480,270));
        }

        //~Game(){}

        void run(){
            while (window->isOpen()){
                
                // handles closing the window manually
                sf::Event e;
                while (window->pollEvent(e)){

                    if (e.type==sf::Event::Closed){ // instead of Closed, this can be key pressed, MouseWheelScrolled
                        window->close();
                        std::cout<<"window closed"<<std::endl;
                    }
                }
                
                 // LEFT
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    this->player->move(-1,0);
                    std::cout<<"A or left keyboard pressed"<<std::endl;
                }   
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    this->player->move(1,0);
                    std::cout<<"D or right keyboard pressed"<<std::endl;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                    this->player->move(0,-1);
                    std::cout<<"W or up keyboard pressed"<<std::endl;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                    this->player->move(0,1);
                    std::cout<<"S or down keyboard pressed"<<std::endl;
                }

                window->clear();
                player->draw(window);

                window->draw(*shape1); // delete this
                
                window->display();
            }
        }
};



int main(){
    Game GAM(960, 540,"daddy");
    GAM.run();
    return 0;
}



// class GameEntity{
//     protected:
//         sf::Shape body;

//     public:

//         //sf::Shape getBody(){return this->body;}

//         void move(int x, int y){
//             // could make this look more complex
//             this->body.move(x,y);
//         }
        
        
//         // bool collision(){

//         // }
// };

// class Enemy: public GameEntity{

// };