
#ifndef GAMEENTITY_H
#define GAMEENTITY_H 
#include<iostream>
#include<SFML/Graphics.hpp>

// class GameEntity{


//     protected:
//         sf::Shape *body;
//  // sf::RectangleShape* body; // okay so having a body doesn't work either
//     public:
//         void move(int x, int y);

//         //virtual void update()=0;



//         //  bool overlaps(vector Wall+EnemyArray){
//             //check if this->body overl

//             // for (int i =0;i<gameEntities.size();i++){

//                             //overlap check with wall[i] and body
//                 //     }
//         // }
//         // void respawn(){
//         //     if overlaps(){
//         //         body->setPosition(100,100);
//         //     }
//         // }
        

// };
class GameEntity{
    protected:
        sf::Shape *body;
 // sf::RectangleShape* body; // okay so having a body doesn't work either
    public:
        void move(int x, int y){ 
            // could make this look more complex
            this->body->move(x,y);
            std::cout<<"body moved!"<<std::endl;
        }

        //virtual void update()=0;



        //  bool overlaps(vector Wall+EnemyArray){
            //check if this->body overl

            // for (int i =0;i<gameEntities.size();i++){

                            //overlap check with wall[i] and body
                //     }
        // }
        // void respawn(){
        //     if overlaps(){
        //         body->setPosition(100,100);
        //     }
        // }
        

};


#endif