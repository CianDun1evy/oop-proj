// // In this test, we look at how to set values for a text value, storing death count and name

#include<iostream>
#include<fstream>

#include<string>


int main(){
    
    int death = 14;
    std::string name;

    int prevdeath;
    std::string prevname;

    std::string filename  = "ScoreData.txt";

    
    while(name.size()>20 || name.size()<1){
        // request name input
        std::cout<< " Input a name : ";
        std::cin >> name;
        
        if (name.size()>20){
            std::cout<<"Team name too long, try again. \n(Hint: yours was "<<name.size()<<" characters long, we accept a max of 20)"<<std::endl;
        }
    
    }
    std::cout<< name<< " "<< death << std::endl;


    std::fstream file;
    
    file.open(filename, std::ios_base::app | std::ios_base::in);

    
    if (file.is_open()){
        // file >> prevname;
        // file >> prevdeath;
        file << name << " " << death << std::endl;
    }
    // // std::cout << "Done !" << std::endl;
    // std::cout << "Prevname = " << prevname << std::endl;
    // std::cout << "Prevdeath = " << prevdeath << std::endl;


    
    return 0;
}

// #include <iostream>
// #include <fstream>

// using std::cout; using std::fstream;
// using std::endl; using std::string;

// int main()
// {
//     string filename("ScoreData.txt");
//     fstream file;

//     file.open(filename, std::ios_base::app | std::ios_base::in);
//     if (file.is_open())
//         file << "Some random text to append." << endl;
//     cout << "Done !" << endl;

//     return 0;
// }