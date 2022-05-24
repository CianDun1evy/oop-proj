
#include <iostream>
#include <SFML/Graphics.hpp>
#include<fstream>
#include<vector>

#include "Enemy.h"
#include "Walls.h"
#include "Player.h"
#include "WinZone.h"
#include "ScreenText.h"

#include "OHG_Game.h"



// Constructor for Game

OHG_Game::OHG_Game(int x, int y, std::string title){
    
    // Initialise Game Window
    window = new sf::RenderWindow(sf::VideoMode(x, y), title);
    
    window->setFramerateLimit(60);

    // Initialise Win Zone
    green1 = new WinZone(30,80,960-10,540/2);  //(10,100, 960 - 10 / 2, 540 / 2);
    gameEntities.push_back(green1);
    // std::cout<<"win zone initialised"<<std::endl;

    // Initialise Player1 - player2 initialised later if required
    this->numPlayers = 1;
    player1 = new Player(20, 100, 200, sf::Color::Red,0);
    gameEntities.push_back(player1);
    numDeaths = 0;
    // std::cout<<"player initialised"<<std::endl;



    // Enemy INITIALISATION   
    for (int i=0;i<10;i++){
        Enemy *temp;
        temp = new Enemy(i);
        gameEntities.push_back(temp);
    }   

    // INITIALISE WALLS AND THEIR POSITIONS

    std::cout<<"getting wall data"<<std::endl;
    this->setWallPositionsData(8,4,"WallPos.txt");
    std::cout<<"got wall data"<<std::endl;
    
    for (int i=0;i<8;i++){
        Walls *temp1;
        temp1 = new Walls(WallPos[i][0],WallPos[i][1],WallPos[i][2],WallPos[i][3]);
        gameEntities.push_back(temp1);
       // std::cout<<"oki doki again "<<std::endl;
    }
    // std::cout<<"Walls initialised"<<std::endl;

    
    // Initialise Text here:

    // this->deathMessage = new ScreenText("gothicb.ttf","Deaths: 0",30,100,100,sf::Color::Red);

    this->deathFont.loadFromFile("gothicb.ttf");

    displayDeaths.setFont(deathFont);
    // displayDeaths.setString("Deaths");
    displayDeaths.setCharacterSize(30);
    displayDeaths.setPosition(35, 200);
    displayDeaths.setFillColor(sf::Color::Red);


    std::cout<<" good to go"<<std::endl;
}
    

// Destructor for Game
OHG_Game::~OHG_Game(){
    
    std::cout<<"OHG destructor called"<<std::endl;

    for (int i =0 ; i<this->gameEntities.size(); i++){ 
        delete gameEntities[i];
        // std::cout<<"Game Entity deleted"<<std::endl;
    }

    std::cout<<"All Game Entities deleted" <<std::endl;

    delete this->window;
    std::cout<<"Successfully called and executed OOP's Hardest Game destructor"<<std::endl;
}


// Run function which deals with running the gameplay
void OHG_Game::run(){   

    std::cout<<"started running game"<<std::endl;

    if (this->numPlayers == 2){
            player2 = new Player(20, 150, 200, sf::Color::Cyan,1);
            gameEntities.push_back(player2);
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
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                
                window->close();
                std::cout<<"Q pressed!"<<std::endl;
            }
            
        }

        for (int i= 0 ; i<gameEntities.size();i++){

            std::string type = (gameEntities)[i]->getType();

            if (type == "Player" && green1->overlaps(gameEntities[i])){
                this->result();
            }   
        }

        window->clear();

        

        
        // Update all game entities
        for (int i =0;i<gameEntities.size();i++){ //a sghdfgsawefsgdb
            gameEntities[i]->update(&gameEntities);
        }
        // std::cout<<"game entities updated"<<std::endl;


        // Draws Game Entities onto window (players, enemies, walls, etc)
        for (int i =0;i<gameEntities.size();i++){
            gameEntities[i]->draw(window);
        }
        // std::cout<<"game entities drawn"<<std::endl;

        // Display Death Counter
        this->numDeaths = player1->getDeaths();
        
        if (this->numPlayers == 2){
            this->numDeaths+=player2->getDeaths();
        }
        std::string msg;
        msg =  "Death: " + std::to_string(this->numDeaths);
        this->displayDeaths.setString(msg);
        window->draw(this->displayDeaths);
        // std::cout<<"death counter drawn"<<std::endl;

        // display everything onto the screen
        window->display();
    }
}



// this could be used for enemies as well, so could have more ambiguous version:
// void Game::setPositionData(int row,int col,std::string posfile, float array[row][col]){}

void OHG_Game::setWallPositionsData(int row,int col,std::string posfile){

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
void OHG_Game::welcome()
{
    std::cout<<"welcome!"<<std::endl;


    sf::Text game_name;

    sf::Font gothic;
    gothic.loadFromFile("gothicb.ttf");

    sf::Font lora;
    lora.loadFromFile("Lora-MediumItalic.ttf");
    
// Just could not figure out how to make a ScreenText class work. idk why

    // this->_welcome = new ScreenText("gothicb.ttf","WELCOME TO",30,50,200,sf::Color::Cyan);
    // gameTexts.push_back(_welcome);
    // ScreenText welcome("gothicb.ttf","WELCOME TO",30,50,200,sf::Color::Cyan);
    
    sf::Text welcome;
    welcome.setFont(gothic);
    welcome.setString("WELCOME TO");
    welcome.setCharacterSize(30);
    welcome.setPosition(50, 200);
    welcome.setFillColor(sf::Color::Cyan);

    

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

        // std::cout<<"checking to move to num players"<<std::endl;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            std::cout<<"moving to num players!"<<std::endl;
            this->no_of_players();
        }


        // std::cout<<"welcome - after check to go to numplayers"<<std::endl;


        // Refresh and Update Screen
        window->clear();
        window->draw(welcome);
        // window->draw(welcome.getText());
        // welcome.draw(window);
        // _welcome->draw(window);
        // std::cout<<"welcome - drew welcome"<<std::endl;

        
        window->draw(game_name);
        window->draw(entry);
        window->draw(quit);

        window->display();
    }
}

void OHG_Game::no_of_players() {

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

        // std::cout<<"Gonna check if window closed"<<std::endl;
        sf::Event e;
        while (window->pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            { // instead of Closed, this can be key pressed, MouseWheelScrolled
                window->close();
                std::cout << "window closed" << std::endl;
            }
        // This also breaks the game - IT LOOKS LIKE MY LAPTOP IS REGISTERING AS EVERY SINGLE KEY PRESSED CONSTANTLY, IDK WHY
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {   
                std::cout<<" Quitting in num players"<<std::endl;
                this->window->close(); // break here before
            }
        }

        // std::cout<<"num players - checked window wasn't closed "<<std::endl;

        

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

        // std::cout<<"num players - player didn't press 1 or 2 "<<std::endl;


        window->clear();

        window->draw(mode);
        window->draw(players_no);
        window->draw(quit);

        window->display();
    }

}




void OHG_Game::controls() {

    // Nothing here yet? What is this for?

}




void OHG_Game::result() {

    std::cout<<"In Result "<<std::endl;
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

    // ScreenText winner("gothicb.ttf","Cheers! You WON!!",70,200,220,sf::Color::Green);
    std::cout<<" made winner text"<<std::endl;


// will not need a loser, as everyone is a winner :)
    // sf::Text loser;
    // loser.setFont(gothic);
    // loser.setString("Try next time!!!");
    // loser.setCharacterSize(70);
    // loser.setPosition(200, 220);
    // loser.setFillColor(sf::Color::Green);

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

        // close the window to exit the game
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            window->close();
        }

        

        window->clear();

        //window->draw(loser);
        window->draw(winner);
        // window->draw(winner.getText());

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