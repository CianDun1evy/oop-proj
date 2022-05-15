/* sorta a draft on concepts ofo how to use sfml with classes:
#include<The graphics>

class Game{
    // game runs straight from here

};

class GameEntity{
    protected:
        sf::CircleShape circle;  // maybe figure out some way to switch between Circle and square (EASY, just redefine once you're in player! overloading or polymorphism or whatever)
        std::string name;
        int HP;
    public:
        sf::CircleShape getShape(){return circle; } // displayed getShape(); // in header file
        std::string getName(){ }
        int getHP(){return this->HP;}
        //MAYBE this class contains movement! would this be better or is it better to have movement as it's own seperate class?

};

//inherit from GameEntity
class GameEntity: public Player{
    
};

//inherit enemy from game entity
    
// maybe have enemy names being called from a txt file that 
// can be changed by user - gives extra points maybe? 
// (when you die, it says "<enemy name> has slain you!")

class enemy{ 

};

// HAVE A CLASS MOVEMENT THAT DEALS WITH ALL MOVEMENT ON THE SCREEN

// Have movement and collisions as part of Game Entity I think, and have polymorphism redefine once in Player for square
class movement{ 
    private:
        // do we even need a private in this case?

    public:
    // you can prolly just have two: moveX and moveY, and just specify negative or positive. might be better prolly
        void moveleft(sf::CircleShape& a, int pixels) // maybe make a class called 'Shape' or smth that contains either a circle or rectangle for this, idk maybe too convoluted
        void moveright()
        void moveup()
        void movedown()
        // OR
        void movex(sf::CircleShape& a, int xpixels)
        void movey(sf::CircleShape& a, int ypixels)

};

class Collisions{ // would this be it's own class ??

};
*/