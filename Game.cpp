
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Player.h"
#include "Game.h"
#include "Enemy.h"
#include "Walls.h"
#include<fstream>
#include<vector>

// Constructor for Game

Game::Game(int x, int y, std::string title){
    
    // Initialise Game Window
    window = new sf::RenderWindow(sf::VideoMode(x, y), title);
    window->setFramerateLimit(60);

    // Initialise Players - probs only do 1 player (or have that as user input in menu, choose either 1 or two players)
    player1 = new Player(20, 100, 200, sf::Color::Red);

    gameEntities.push_back(player1);

    player_list.push_back(player1);
    this->numPlayers = 1;

    // player2 = new Player(20, 150, 200, sf::Color::Cyan);

    // Enemy INITIALISATION   
    for (int i=0;i<10;i++){
        Enemy *temp;
        temp = new Enemy(i);
        enemylist.push_back(temp);

        gameEntities.push_back(temp);
    }   

    std::cout<<"gonna get wall data"<<std::endl;
    this->setWallPositionsData(8,4,"WallPos.txt");
    std::cout<<"got wall data"<<std::endl;

    
    for (int i=0;i<8;i++){
        Walls *temp1;
        temp1 = new Walls(WallPos[i][0],WallPos[i][1],WallPos[i][2],WallPos[i][3]);
        //temp1 = new Walls(10,10,10,10);
        wall_list.push_back(temp1);
        gameEntities.push_back(temp1);
       // std::cout<<"oki doki again "<<std::endl;
    }
    std::cout<<"good to go"<<std::endl;
}

// Destructor for Game
Game::~Game(){
    // delete [] player1;
    // delete [] player2;
    
    // delete [] wall_list;
    // delete [] enemylist;
    // delete [] gameEntities;
}


// Run function which deals with running the gameplay
void Game::run(){   

    std::cout<<"started running game"<<std::endl;

    if (this->numPlayers == 2){
            player2 = new Player(20, 150, 200, sf::Color::Cyan);
            gameEntities.push_back(player2);
            player_list.push_back(player2);
    }

    while (window->isOpen()){

        // handles closing the window manually
        sf::Event e;
        while (window->pollEvent(e)){
            if (e.type == sf::Event::Closed)
            { // instead of Closed, this can be key pressed, MouseWheelScrolled
                window->close();
                std::cout << "window closed" << std::endl;
            }
        }
         std::cout<<"checked window closed"<<std::endl;


        
        
        // Player Movements
        for (int i =0;i<player_list.size();i++){
            player_list[i]->inputmove(i);
        }
        // player1->inputmove(0);
        // player2->inputmove(1);
        std::cout<<"players can move"<<std::endl;


        // ENEMY AUTONOMOUS MOVEMENT:
        for (int i=0;i<enemylist.size()-4;i++){
            this->enemylist[i]->move(0,0.01+(-0.1)*(i%2));
        }
        for (int i=enemylist.size()-4;i<enemylist.size()-1;i++){
            this->enemylist[i]->move(0.05+(-0.1)*(i%2),0);
        }
        std::cout<<"enemies move"<<std::endl;



        // update(); // input delta time

        window->clear();

        std::cout<<"window cleared"<<std::endl;

        // RESPAWN UPON COLLISION WITH ENEMIES AND WALLS
        for (int i=0;i<enemylist.size();i++){
            // respawn if touch enemy or wall

            std::cout<<"respawn loop:"<<std::endl;

            for (int j =0;j<player_list.size();j++){
                player_list[j]->respawn((100+50*j),200,enemylist[i]);
            }
            // this->player1->respawn(100,200,enemylist[i]);

            // this->player2->respawn(150,200,enemylist[i]);
        }
        std::cout<<"touching enemies kills"<<std::endl;
        
        for (int i=0;i<wall_list.size();i++){
            // respawn if touch enemy or wall

            for (int j=0;j<player_list.size();j++){

                this->player_list[j]->respawn(100+50*j,200,wall_list[i]);
            }
            // this->player1->respawn(100,200,wall_list[i]);

            // this->player2->respawn(150,200,wall_list[i]);
        }
        std::cout<<"touching walls kills"<<std::endl;



        // Draws Game Entities onto window (players, enemies, walls, etc)
        for (int i =0;i<gameEntities.size();i++){
            gameEntities[i]->draw(window);
        }
        std::cout<<"game entities drawn"<<std::endl;

        // drawing players and walls onto window
        window->display();
    }
}

// this could be used for enemies as well, so could have more ambiguous version:
// void Game::setPositionData(int row,int col,std::string posfile, float array[row][col]){}
void Game::setWallPositionsData(int row,int col,std::string posfile){

    // import file 
    
    std::cout<< "Finding Wall Position Data"<<std::endl;
    std::ifstream inputfile(posfile);

    // check if file exists, or if it is usable
    if (!inputfile.is_open()){

        std::cout<<"There was an error opening file"<<std::endl;

        // if error, set all values to 0;
        for (int i=0;i<row;i++){
            for (int j=0;j<4;j++){ 
                WallPos[i][j]=0;
            }
        }
    }
    else{ 
        // get input from file into Wall if no errors 

        std::cout<< "Inputting Wall Position Data into array"<<std::endl;
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                inputfile >> WallPos[i][j];  //Take input from file and put into WallPos
            }
        }
        std::cout<< "Successful input"<<std::endl;
    }

    // Debugging: print out values held in WallPos to check validity

    /* std::cout<<"Printing WallPos Data:"<<std::endl;  
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            std::cout<< WallPos[i][j]<<" ";
        }
        std::cout<<std::endl;
    } */
    
}



// Welcome screen - this is what happens first
void Game::welcome()
{
    std::cout<<"welcome!"<<std::endl;

    sf::Text welcome;
    sf::Text game_name;
    sf::Font gothic;
    gothic.loadFromFile("gothicb.ttf");
    welcome.setFont(gothic);
    //welcome.setString(wel);
    welcome.setString("WELCOME TO");
    welcome.setCharacterSize(30);
    welcome.setPosition(50, 200);
    welcome.setFillColor(sf::Color::Cyan);
    sf::Font lora;
    lora.loadFromFile("Lora-MediumItalic.ttf");
    game_name.setFont(lora);
    game_name.setString("OOP's HARDEST GAME");
    game_name.setCharacterSize(50);
    game_name.setPosition(50, 230);
    game_name.setFillColor(sf::Color::Green);
    
    sf::Text entry;
    entry.setFont(gothic);
    entry.setString("Press SPACE to Continue!!");
    entry.setCharacterSize(25);
    entry.setPosition(330, 400);
    entry.setFillColor(sf::Color::Red);

    sf::Text quit;
    quit.setFont(gothic);
    quit.setString("Q-Quit!!");
    quit.setCharacterSize(15);
    quit.setPosition(800, 50);
    quit.setFillColor(sf::Color::Red);

    std::cout<<"welcome - initialised text "<<std::endl;

    while (window->isOpen())
    {
       // std::cout<<"looping in welcome!"<<std::endl;

        // handles closing the window manually
        sf::Event e;
        while (window->pollEvent(e))
        {
            if (e.type == sf::Event::Closed )//|| sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            { // instead of Closed, this can be key pressed, MouseWheelScrolled
                window->close();
                std::cout << "window closed" << std::endl;
            }

            // for some reason this breaks everything

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                
                window->close();
                std::cout<<"Q pressed!"<<std::endl;
            }
        }

        
       // std::cout<<"window wasn't closed"<<std::endl;

        // Cian laptop got screwed by this bit for some reason, computer was registering that Q was being pressed when it wasn't - super stupid
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        //     std::cout<<"Q pressed!"<<std::endl;

        //     break;
        // }

        std::cout<<"checking to move to num players"<<std::endl;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            std::cout<<"moving to num players!"<<std::endl;
            this->no_of_players();
        }


        std::cout<<"welcome - after check to go to numplayers"<<std::endl;

        // std::string wel="welcome";
        // // Welcome text

        // Refresh and Update Screen
        window->clear();

        window->draw(welcome);
        window->draw(game_name);
        window->draw(entry);
        window->draw(quit);

        window->display();
    }
}

void Game::no_of_players() {

    std::cout<<"started num players"<<std::endl;
    
    // Fonts
    sf::Font gothic;
    gothic.loadFromFile("gothicb.ttf");
    sf::Font lora;
    lora.loadFromFile("Lora-MediumItalic.ttf");
    
    sf::Text mode;
    mode.setFont(gothic);
    mode.setString("SELECT MODE:");
    mode.setCharacterSize(25);
    mode.setPosition(100, 370);
    mode.setFillColor(sf::Color::Green);

    sf::Text players_no;
    players_no.setFont(gothic);
    players_no.setString("Press 1 for Singleplayer mode\nPress 2 for Multiplayer mode");
    players_no.setCharacterSize(25);
    players_no.setPosition(100, 400);
    players_no.setFillColor(sf::Color::Green);

    sf::Text quit;
    quit.setFont(gothic);
    quit.setString("Q-Quit!!");
    quit.setCharacterSize(15);
    quit.setPosition(800, 50);
    quit.setFillColor(sf::Color::Red);

    std::cout<<"num-player - initialised text"<<std::endl;

    while (window->isOpen())
    {

        // handles closing the window manually

        std::cout<<"Gonna check if window closed"<<std::endl;
        sf::Event e;
        while (window->pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            { // instead of Closed, this can be key pressed, MouseWheelScrolled
                window->close();
                std::cout << "window closed" << std::endl;
            }
        }

        // This also breaks the game - IT LOOKS LIKE MY LAPTOP IS REGISTERING AS EVERY SINGLE KEY PRESSED CONSTANTLY, IDK WHY
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {   
            std::cout<<" Quitting in num players"<<std::endl;
            this->window->close(); // break here before
        }

        std::cout<<"num players - checked window wasn't closed "<<std::endl;

        

        // Single or Two Player Options
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            this->numPlayers = 1;
            this->run();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {   
            this->numPlayers = 2;
            this->run();
        }

        std::cout<<"num players - player didn't press 1 or 2 "<<std::endl;


        window->clear();

        window->draw(mode);
        window->draw(players_no);
        window->draw(quit);

        window->display();
    }

}




void Game::controls() {

    // Nothing here yet? What is this for?

}




void Game::result() {

    // Fonts
        sf::Font gothic;
        gothic.loadFromFile("gothicb.ttf");
        sf::Font lora;
        lora.loadFromFile("Lora-MediumItalic.ttf");
        
        sf::Text winner;
        winner.setFont(gothic);
        winner.setString("Cheers! You WON!!");
        winner.setCharacterSize(70);
        winner.setPosition(200, 220);
        winner.setFillColor(sf::Color::Green);

        sf::Text loser;
        loser.setFont(gothic);
        loser.setString("Try next time!!!");
        loser.setCharacterSize(70);
        loser.setPosition(200, 220);
        loser.setFillColor(sf::Color::Green);

        sf::Text exit;
        exit.setFont(gothic);
        exit.setString("Press SPACE to EXIT the game!!");
        exit.setCharacterSize(25);
        exit.setPosition(300, 500);
        exit.setFillColor(sf::Color::Red);

    while (window->isOpen())
    {

        // handles closing the window manually
        sf::Event e;
        while (window->pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            { // instead of Closed, this can be key pressed, MouseWheelScrolled
                window->close();
                std::cout << "window closed" << std::endl;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            break;
        }

        

        window->clear();

        //window->draw(loser);
        window->draw(winner);
        window->draw(exit);

        window->display();
    }

}






/*  // Old Code that may be useful if something breaks

// WALL INITIALISATION

      // boundary_top = new Walls(960, 15, 960 / 2, 15 / 2);
    // boundary_bottom = new Walls(960, 15, 960 / 2, 540 - 15 / 2);
    // boundary_left = new Walls(15, 540, 15 / 2, 540 / 2);
    // boundary_right = new Walls(15, 540, 960 - 15 / 2, 540 / 2);
    // wall11 = new Walls(5, 378, 192, 378 / 2);
    // wall21 = new Walls(5, 108, 736, 108 / 2);
    // wall12 = new Walls(5, 108, 192, 486);
    // wall22 = new Walls(5, 378, 736, 351);
    
*/