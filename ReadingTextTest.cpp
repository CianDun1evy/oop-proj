#include<iostream>
#include<fstream>

int main(){   
    int row = 8; // Number of Walls
    int col = 4; // number of parameter required for Wall Initialisation


    float WallPos[row][col];
    std::string posfile = "WallPos.txt";

    //Opening the file
    std::ifstream inputfile(posfile);
    
    // check if file exists, or if it is usable
    if (!inputfile.is_open()){

        std::cout<<"There was an error opening file"<<std::endl;
        
        // if error, set all values to 0;
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                WallPos[i][j]=0;
            }
        }
    }
    
    // get input from file into Wall if no errors 
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            inputfile >> WallPos[i][j];  //Take input from file and put into WallPos
        }
    }
    
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            std::cout<< WallPos[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

  

    return 0;
}

