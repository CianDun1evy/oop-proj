#include<SFML/Graphics.hpp>

class Player{
    protected:
        sf::RectangleShape* body;
    public:
        Player(int size,int x,int y){
            body = new sf::RectangleShape(sf::Vector2f(size,size));
            body->setOrigin(sf::Vector2f(size,size));
            body->setPosition(sf::Vector2f(0,0));
            body->setFillColor(sf::Color::Red);
        }
        void draw(sf::RenderWindow *window){
            window->draw(*this->body); 
        }
};

class oopGame{
    protected:
        sf::RenderWindow* window; // idk if having these as pointers is necessary tbh, might just be annoying 
        Player *player;
    public:
        oopGame(int sizex,int sizey,std::string title){
            // Initialising player and the window because they're pointers
            player = new Player(50,0,0);
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
            player->draw(window);
            window->display();
            }
        }

        ~oopGame(){ }
};



int main(){
    
    oopGame game(960, 540,"test");
    game.run();
    return 0;
}