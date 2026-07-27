#include<bits/stdc++.h>
using namespace std;

//we can create a pointer of class type, which can be used to point class object
class Number{
    
    int a, b;
    public:
    int c;
    void setData(int x, int y){
        a = x; 
        b = y;
    }
    void printData(){
        cout<<"a = "<<a<<endl<<"b = "<<b<<endl;
    }
};

int main() {

    Number n1;
    Number *ptr = &n1; // ptr to object of class Number
    (*ptr).setData(1,2); // we can access using astric but syntax must be correct
    ptr->printData();  // standard way to access using arrow oprator 

    //we can also crete the ptr to the class member

    //data type ClassName::*ptr = &ClassName::dataMember

    int Number::*ptr2 = &Number::c;
    n1.*ptr2 = 34;      // we can access the this data member using the *
    cout<<n1.*ptr2<<endl;
    cout<<(*ptr).*ptr2<<endl;
    cout<<ptr->*ptr2<<endl;

    //NOTE : we can only create the ptr to class member who are public and not private 

    // we can also create the pointer the member function of the class
    // return_type (ClassName::*ptr_fun)(arg list) = &ClassName::functionName;
    
    void (Number::*ptr_fun)() = &Number::printData; 
    (n1.*ptr_fun)();  // syntax to use ptr_fun 
    return 0;
}