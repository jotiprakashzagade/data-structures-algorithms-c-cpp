#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    // Creating a Constructor
    // Construtor is a special member function with the same name as class.
    // it is used to initialize the objects of class
    // it is automatically invoked whenever object is  created

    Complex(void); // constructor declaration
    // {
    //     a = 10;        // we can directly write the defination of the constructorr 
    //     b = 3;         // in the class defination 
    // }
   
    void printData()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

Complex::Complex(void) // this is a default constructor as it takes no parameters
{
    a = 10; 
    b = 3;
}

int main()
{

    Complex c1, c2;
    c1.printData();
    c2.printData();
    return 0;
}

/*Characteristics of the Construcotrs :
   1. It should be declare in the public section of the class
   2. They are automatically invoked whenever object is created
   3. They cannot returs values and do not have return type
   4. Constructor without arguments(void) is called as default consructor
   5. We cannot refer to their address
*/