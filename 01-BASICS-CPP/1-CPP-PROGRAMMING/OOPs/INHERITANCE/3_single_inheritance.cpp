#include<bits/stdc++.h>
using namespace std;

class Base{
    int data1;
    int data2;
    public:
    void setData1(int x, int y){
        data1 = x;
        data2 = y;
    }
    int getData1(){
        return data1;
    }
    int getData2(){
        return data2;
    }
};

class Derived : public Base{
    int data3;
    public:
    void process(){
        data3 = getData2() * getData1();
    }
    void display(){
        cout<<"Value of data 1 = "<<getData1()<<endl;  // in this line we can access the private data in derived class
        // not directly but via public member function 
        cout<<"Value of data 2 = "<<getData2()<<endl;
        cout<<"Value of data 3 = "<<data3<<endl;

    }
};

int main() {
    Derived der; // when we create the object of the derived class it does not create members present in derived class
    // and public memebers of the base class , but it also create the members that are private of the base class
    // but we can not access the private base members dirctly we need public methods to access and perform 
    //opration on them  like we do in main() fucniton 
    der.setData1(10,20);  //setData set private members of the base class , not directly but using member fun()
    der.process();
    der.display();
    return 0;
}

/* =======================================================================================
   THE TRUTH ABOUT INHERITANCE: MEMORY ALLOCATION VS. ACCESS VISIBILITY
   =======================================================================================
   
   COMMON MISCONCEPTION: 
   "Private members of a base class are not inherited by the derived class." 
   --> THIS IS TECHNICALLY FALSE. It is lazy shorthand used by textbooks.

   THE ACTUAL GROUND TRUTH:
   1. INHERITANCE OF STATE (MEMORY): 100% TRUE
      When you instantiate an object of a Derived class, the compiler allocates a single, 
      contiguous block of RAM. This block physically contains ALL data members of the 
      Base class (private, protected, and public) PLUS the Derived class members.
      Proof: sizeof(Derived) includes the bytes of the Base class private variables.

   2. INHERITANCE OF ACCESS (VISIBILITY): FALSE
      The access specifier 'private' is a compile-time restriction boundary. The private 
      variables physically exist inside the derived object's memory, but their names are 
      hidden from the Derived class's scope. You cannot access them DIRECTLY by name.

   HOW TO ACCESS THEM INDIRECTLY:
      Just like the main() function, the Derived class can manipulate these hidden 
      private variables indirectly by invoking inherited public or protected methods 
      of the Base class. Those methods act as authorized bridges to the private data.
   ======================================================================================= */