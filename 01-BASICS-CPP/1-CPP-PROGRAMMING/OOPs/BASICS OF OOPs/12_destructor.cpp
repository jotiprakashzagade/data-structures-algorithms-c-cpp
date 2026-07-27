#include<iostream>
using namespace std;

int count = 0;
class Num{
    public:
    Num(){
        count++;
        cout<<"This is the time when constructor is called for the object number "<<count<<endl;
    }
    //Destructor never takes an arguments neither it returns any value
    ~Num(){
        cout<<"This is the time when destructor is called for the object number "<<count<<endl;
        count--;
    }
};

int main() {
    cout<<"We are inside the main funciton "<<endl;
    cout<<"Creating first object n1 "<<endl;
    Num n1;
    cout<<"count : "<<count<<endl;
    {
        cout<<"Entering this block"<<endl;
        cout<<"Creating 2 more objects n2 and n3"<<endl;
        Num n2, n3;
        cout<<"count : "<<count<<endl;
        cout<<"Exitign this block"<<endl;
    }
    //as we can see as soon as we came out of this box destructor is called and it prints the message
    // and destruct this local object and releease the memmory , so they are bassicaly use for 
    // relearsing memmroy that is allocated dynamically or in the dynamic array 
    cout<<"Back to main funtion "<<endl;
    cout<<count<<endl;
    return 0;
}