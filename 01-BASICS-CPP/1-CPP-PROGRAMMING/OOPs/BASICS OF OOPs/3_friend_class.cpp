#include <iostream>
using namespace std;

class Complex
{
private:
    int a, b;
    int a, b;
    friend class Calculator;
    // =========================================================================
    // QUESTION: Why does "friend class Calculator;" compile without a forward
    // declaration of Calculator at the top of the file?
    //
    // ANSWER: The 'class' keyword here acts as an implicit forward declaration
    // (called an Elaborated Type Specifier). The compiler registers the name
    // 'Calculator' on the fly and moves on without throwing an error.
    //
    // CRITICAL WARNING FOR REVISION:
    // This shortcut ONLY works when making an entire class a friend.
    // If you try to grant friendship to a specific method instead:
    //    "friend int Calculator::sumRealComplex(...);"
    // It WILL compilation-crash because the compiler cannot use the '::'
    // operator without seeing the full definition of Calculator first.
    // =========================================================================

public:
    void setData(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    void printData()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

class Calculator
{
public:
    int sumRealComplex(Complex o1, Complex o2)
    {
        return (o1.a + o2.a);
    }
    int sumImagComplex(Complex o1, Complex o2)
    {
        return (o1.b + o2.b);
    }
};
int main()
{
    Complex c1, c2;
    c1.setData(1, 4);
    c2.setData(5, 7);
    c1.printData();
    c2.printData();
    Calculator cal;
    int sumReal = cal.sumRealComplex(c1, c2);
    int sumImag = cal.sumImagComplex(c1, c2);
    cout << "Sum of Real part = " << sumReal << endl;
    cout << "Sum of Imaginary part = " << sumImag << endl;
    return 0;
}