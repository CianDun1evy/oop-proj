#include<SFML/Graphics.hpp>
#include<iostream>

class GameEntity{
   // protected:
    public:
    // movement figured out here:
        // void movex(sf::CircleShape& a, int xpixels);
        // void movey(sf::CircleShape& a, int ypixels); // then player and collectible inherit from here, Player overloads ?

        void movex(sf::RectangleShape *a, int xpixels){
            
            sf::Vector2f pose = a->getPosition();
            pose.x += xpixels;
            a->setPosition(pose);
            std::cout<<"A movex called"<<std::endl;

        }
        void movey(sf::RectangleShape a, int ypixels){
            sf::Vector2f pose = a.getPosition();
            pose.y+=ypixels;
            a.setPosition(pose);
        }

    
    
    //collisions figured out here
        // bool collision(sf::RectangleShape& a); // return 1 if collision, 0 if not; 
        // bool collision(sf::CircleShape& a); // overloading
};


class Player:public GameEntity{
    protected:
        sf::RectangleShape * body; // it was a pointer before, now just straight object
    public:
        Player(int size,int x,int y){
            body = new sf::RectangleShape(sf::Vector2f(size,size));
            body->setOrigin(sf::Vector2f(size/2,size/2));
            body->setPosition(sf::Vector2f(x,y));
            body->setFillColor(sf::Color::Red);
            std::cout<<"player initialised"<<std::endl;
        }
        void draw(sf::RenderWindow *window){
            std::cout<<"drawn!"<<std::endl;
            window->draw(*body); 
        }
        sf::RectangleShape* getBody(){return body;}


        // void movex(int a){
        //     GameEntity::movex(this->body,a);
        // }
        // void movement(sf::RectangleShape daddy, int speed){ // have this as a template?
            
        //     // LEFT
        //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        //         // left key is pressed: move our character
        //        // daddy.move(-5.f, 0.f); // the following code just does the same thing as daddy.move, so might want to just use move. don't see any advantage yet to not
        //         movex(daddy,-speed);
        //     }
            // RIGHT
            //  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            //     // left key is pressed: move our character
            //     movex(daddy,speed);

            // } 
            // //UP
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            //     // left key is pressed: move our character
            //     movey(daddy,-speed);
            // }
            // //down
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            //     // left key is pressed: move our character
            //     movey(daddy,speed);
            // }
        //}
};

//sf::Shape
// class Shape{

//     sf::RectangleShape a;
//     sf::CircleShape a;
    
// }
// class Movement{ // I don't think movement should be it's own class, there isn't a simple way to call the functions without having smth to call from protected/private
//     protected:
//         // nothing here, hopefully should be aight
//     public:

//     // can use template to not overload 
        

//        // template <typename shape>
    
// };


class oopGame{
    protected:
        sf::RenderWindow *window; // idk if having these as pointers is necessary tbh, might just be annoying 
        Player *player;
    public:
        oopGame(int sizex,int sizey,std::string title){
            // Initialising player and the window because they're pointers
            player = new Player (50,480,270);
            window = new sf::RenderWindow( sf::VideoMode(sizex, sizey),title); // screen res is 1920 x 1080, 960, 540 this is 1/2 aspect ratio
        } 

        void run(){
            while (window->isOpen()){
                
                // handles closing the window manually
                sf::Event e;
                while (window->pollEvent(e)){

                    if (e.type==sf::Event::Closed){ // instead of Closed, this can be key pressed, MouseWheelScrolled
                        window->close();
                    }
                }
                
                 // LEFT
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                // left key is pressed: move our character
               //daddy.move(-5.f, 0.f); // the following code just does the same thing as daddy.move, so might want to just use move. don't see any advantage yet to not

                this->player->movex(player->getBody(),-1);
                //player->getBody().move(-5.f, 0.f);
                std::cout<<"A or left keyboard pressed"<<std::endl;
            }


               // player->movex(player->getBody(),-100);
                // movement done here. idk, not really good to have it here I think
                //player->movement(player->getBody(), 1);

                window->clear();
                // insert window->draw() here
               // player->draw(window);
                window->draw(*(player->getBody())); // Soooo okay can either have a draw function or a get function that you call then draw

                window->display();
            }
        }

       // ~oopGame(){ }
};



int main(){
    
    oopGame game(960, 540,"daddy");
    game.run();
    return 0;
}