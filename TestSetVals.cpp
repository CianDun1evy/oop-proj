// In this test, we look at how to set values for a text value, storing death count and name

#include<iostream>
#include<fstream>

#include<string>

// void setArrayData(int row,int col,std::string posfile , std::string* array){

//     // import file 
    
//     std::cout<< "Finding file containing data"<<std::endl;
//     std::ifstream inputfile(posfile);

//     // check if file exists, or if it is usable
//     if (!inputfile.is_open()){

//         std::cout<<"There was an error opening file"<<std::endl;

//         // if error, set all values to 0;
//         for (int i=0;i<row;i++){
//             for (int j=0;j<col;j++){
//                 std::string temp = "sup";
//                 array[i][j] = temp;
//                 std::cout<<array[i][j]<<" ";
//             }
//         }
//     }

//     else{ 
//         // get input from file into Wall if no errors 

//         std::cout<< "Inputting Wall Position Data into array"<<std::endl;
//         for (int i=0;i<row;i++){
//             for (int j=0;j<col;j++){
//                 // inputfile >> WallPos[i][j];  //Take input from file and put into WallPos
//             }
//         }
//         std::cout<< "Successful input"<<std::endl;
//     }
    
// }


int main(){
    
    int death = 14;
    std::string name;

    int prevdeath;
    std::string prevname;

    std::string filename  = "TestSetValues.txt";

    
    while(name.size()>20 || name.size()<1){
        // request name input
        std::cout<< " Input a name : ";
        std::cin >> name;
        
        if (name.size()>20){
            std::cout<<"Team name too long, try again. \n(Hint: yours was "<<name.size()<<" characters long, we accept a max of 20)"<<std::endl;
        }
    
    }

    std::fstream file;
    
    file.open(filename, std::ios_base::app | std::ios_base::in);


    if (file.is_open()){
        file >> prevname;
        file >> prevdeath;
        file << name << " " << death << std::endl;
    }
    std::cout << "Done !" << std::endl;
    std::cout << "Prevname = " << prevname << std::endl;
    std::cout << "Prevdeath = " << prevdeath << std::endl;


    
    return 0;
}

