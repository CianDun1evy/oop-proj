
#ifndef GameEntity_h
class GameEntity{


    protected:
        sf::Shape *body;
 // sf::RectangleShape* body; // okay so having a body doesn't work either
    public:
        void move(int x, int y);

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