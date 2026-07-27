#include<iostream>
using namespace std;
class Y;
class X
{
    int data;
    friend void add(X, Y);
// =========================================================================
// QUESTION: Why does "friend void add(X, Y);" inside class X cause a compilation error?
//
// ANSWER: When the compiler reads class X line-by-line, it hits "friend void add(X, Y);". 
// At this exact moment, the compiler has absolutely no idea what 'Y' is because class Y 
// is defined further down the file. Unlike "friend class Y;", a function friend declaration 
// cannot implicitly forward-declare missing class types used as parameters.
//
// THE FIX: You MUST put an explicit forward declaration "class Y;" at the very top 
// of the file before class X. This tells the compiler that 'Y' is a valid class name 
// so it can safely parse the function signature inside class X.
// =========================================================================
    public:
        void setValue(int value)
        {
            data = value;
        }
};

class Y
{
    int data;
    friend void add(X, Y);
    public: 
        void setValue(int value)
        {
            data = value;
        }
};

void add(X o1, Y o2)
{
    cout<<"summing datas of X and Y objects gives me = "<<o1.data + o2.data<<endl;
}
int main() {
    
    X a1;
    Y b1;
    a1.setValue(3);
    b1.setValue(5);
    add(a1, b1);
    return 0;
}