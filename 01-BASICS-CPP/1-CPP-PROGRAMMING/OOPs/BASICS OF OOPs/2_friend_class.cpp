#include <iostream>
using namespace std;

// forward declaration
class complexNumber;
class calculator
{
public:
    int sumRealComplex(complexNumber o1, complexNumber o2);
    int sumImagComplex(complexNumber o1, complexNumber o2);
};

class complexNumber
{
private:
    int a, b;
    // // individully decalaring the function as friend
    // friend int calculator::sumRealComplex(complexNumber, complexNumber);
    // friend int calculator::sumImagComplex(complexNumber, complexNumber);

    //declaring entire class as friend so all the function in the class can access pravate data
    friend class calculator;

public:
    void setdata(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    void printdata()
    {
        cout << "Your number is " << a << " + " << b <<"i"<< endl;
    }
};

int calculator ::sumRealComplex(complexNumber o1, complexNumber o2)
{
    return (o1.a + o2.a);
}
int calculator::sumImagComplex(complexNumber o1, complexNumber o2)

{
    return (o1.b + o2.b);
}

int main()
{
    complexNumber c1, c2;
    c1.setdata(1, 4);
    c2.setdata(5, 7);
    c1.printdata();
    c2.printdata();
    calculator cal;
    int sumreal = cal.sumRealComplex(c1, c2);
    int sumimag = cal.sumImagComplex(c1, c2);
    cout << "Sum of real part = " << sumreal << endl;
    cout << "Sum of Imaginary part = " << sumimag <<"i"<< endl;
    return 0;
}