#include<SFML/Graphics.hpp>

class Player{
    protected:
        sf::RectangleShape* playa;
    public:
        Player(int size,int x,int y){
            playa = new sf::RectangleShape(sf::Vector2f(size,size));
            playa->setOrigin(sf::Vector2f(size/2,size/2));
            playa->setPosition(sf::Vector2f(x,y));
            playa->setFillColor(sf::Color::Red);
        }
        void draw(sf::RenderWindow *window){
            window->draw(*playa); 
        }
        sf::RectangleShape getPlayer(){return *playa;}
};

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
        
                sf::Event e;
                while (window->pollEvent(e)){

                    if (e.type==sf::Event::Closed){ // instead of Closed, this can be key pressed, MouseWheelScrolled
                        window->close();
                    }
                }
                

                window->clear();
                // insert window->draw() here
               // player->draw(window);
                window->draw(player->getPlayer()); // Soooo okay can either have a draw function or a get function that you call then draw

                window->display();
            }
        }

       // ~oopGame(){ }
};



int main(){
    
    oopGame game(960, 540,"test");
    game.run();
    return 0;
}