
// How to use templates. this can be used for Movement, make it much simpler for accepting the different shapes


#include<iostream>
#include<string>
using namespace std;

template <typename test>
void min(test a,int b){
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<"compiled!"<<endl;
}

int main(){

    min("a",1);

    return 0;
}
