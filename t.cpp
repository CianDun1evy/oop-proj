
// How to use templates. this can be used for Movement, make it much simpler for accepting the different shapes


#include<iostream>
#include<string>

template <typename bob>
void add(bob a,bob b){
    *a=*b;
}

// void add(char a,char b){
//     *a=*b;
// }

int main(){
    std::string boobie="bob";
    // char a[]="abv";
    // char b[]="asdfgd";
    char a='a';char b='b';
    add<char*>(&a,&b);
    std::cout<<a<<std::endl;

    return 0;
}
