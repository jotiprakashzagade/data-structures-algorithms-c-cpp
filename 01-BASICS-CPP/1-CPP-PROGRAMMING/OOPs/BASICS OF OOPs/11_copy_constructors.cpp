#include<iostream>
using namespace std;

class Number{
    int a;
    public:
    Number(){
        a = 0;
    }
    Number(int x)
    {
        a = x;
    }

    //when we do not create the copy constructor and in main() if we send object as and argument then comiler provide 
    // its own copy compiler, like if we do not create the construcotr below then compiler will not give the 
    // error it will work but the line that we write (copy construcor invoked will not be printed becuase it is no inovoked)
    Number(Number &obj)
    {
        cout<<"copy constructor invoked"<<endl;
        a = obj.a;
    }
    void display()
    {
        cout<<"The number for this object is "<<a<<endl;
    }

};
int main() {
    Number x, y(45), z, z2;// for x and z and z2 default constructor will be invoked and for y constructor with int will be invoked 
    x.display();
    y.display();
    z.display();

    Number z1(y); // for this copy constructor will be invoked
    z1.display();

    z2 = z; // copy constructor not invoked becuase for this defualt constructor is already invoked when it created
    // so in this line we are only assinging the values of the z obj to the z2
    z2.display();

    Number z3 = z; 
    z3.display();
    
    //for this copy consturcotr will be invoked
    /* why copy constructor is invoked for the above line ? :
    ==>  COMPILER TRANSLATION:
            Although this uses the '=' sign, the compiler sees 'Number z3' and knows it must CREATE a new object.
            Because it is a creation, it completely ignores the assignment operator (operator=) and treats 
            this line exactly like: Number z3(z);
            Under the hood, the compiler passes 'z' as a reference argument straight into the Copy Constructor.
            Number z3 = z;  =======>>> Number z3(z) for compiler*/
    


    

    return 0;
}