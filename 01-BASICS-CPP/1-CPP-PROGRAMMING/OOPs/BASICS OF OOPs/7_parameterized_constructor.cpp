#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex(int, int); //this is parameterized constructor as it take arguments

    void printData()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

Complex::Complex(int x, int y)
{
    a = x;
    b = y;
}
int main()
{
    //Implicite declaration
    Complex a(1,2);
    a.printData();

    //Explicite declaration 
    Complex b = Complex(2,3);
    b.printData();

    return 0;
}