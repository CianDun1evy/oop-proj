
// How to use templates. this can be used for Movement, make it much simpler for accepting the different shapes


#include<iostream>
#include<string>
using namespace std;

// template <typename bob>
// void add(bob a,bob b){
//     *a=*b;
// }

template <typename test>
void min(test a,int b){
    cout<<"compiled!"<<endl;
    
}

// void add(char a,char b){
//     *a=*b;
// }

int main(){
    // std::string boobie="bob";
    // // char a[]="abv";
    // // char b[]="asdfgd";
    // char a='a';char b='b';
    // add<char*>(&a,&b);
    // std::cout<<a<<std::endl;
    min(1.1,1);

    return 0;
}
