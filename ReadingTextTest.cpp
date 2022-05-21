#include<iostream>
#include<fstream>

int main(){   
    int row = 4; // Number of Walls
    int col = 4; // number of parameter required for Wall Initialisation


    int WallPos[row][col];
    std::string posfile = "WallPos.txt";

    //Opening the file
    std::ifstream inputfile(posfile);
    
    if (!inputfile.is_open()){

        std::cout<<"There was an error opening file"<<std::endl;
        
        // if error, set all values to 0;
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                WallPos[i][j]=0;
            }
        }
    }

    //Defining the loop for getting input from the file
    
    for (int r = 0; r < row; r++){ //Outer loop for rows
        for (int c = 0; c < col; c++){ //inner loop for columns
          inputfile >> WallPos[r][c];  //Take input from file and put into WallPos
        }
    }

    for (int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
            std::cout << WallPos[r][c] << "\t";
        }
       std:: cout<<std::endl;
    }

    return 0;
}