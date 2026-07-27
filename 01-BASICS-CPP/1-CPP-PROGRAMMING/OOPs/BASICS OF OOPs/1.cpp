#include<bits/stdc++.h>
using namespace std;


class ComplexNumber;

class Calculator{
    public:
    int sumRealComplex(ComplexNumber, ComplexNumber);
    int sumImagComplex(ComplexNumber, ComplexNumber);
};

class ComplexNumber{
    private:
    int a, b;
    // friend class Calculator;
    friend int Calculator::sumRealComplex(ComplexNumber,ComplexNumber);
    friend int Calculator::sumImagComplex(ComplexNumber,ComplexNumber);
    public:
    void setData(int x, int y){
        a = x; 
        b = y;
    }
    void printData(){
        cout<<"Your number is "<<a<<" + "<<b<<"i"<<endl;
    }
};

int Calculator:: sumRealComplex(ComplexNumber c1, ComplexNumber c2){
    return (c1.a+c2.a);
}

int Calculator::sumImagComplex(ComplexNumber c1, ComplexNumber c2){
   return (c1.b+c2.b);
}

int main() {
    ComplexNumber c1, c2;
    c1.setData(1,4);
    c2.setData(5,7);
    c1.printData();
    c2.printData();
    Calculator cal;
    int sumReal = cal.sumRealComplex(c1, c2);
    int sumImag = cal.sumImagComplex(c1, c2);

    cout<<sumReal<<endl;
    cout<<sumImag<<endl;
    
    return 0;
}