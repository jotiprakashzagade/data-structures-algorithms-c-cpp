#include<iostream>
using namespace std;
class C2;
class C1
{
    int val;
    friend void swap(C1 &, C2 &);
    public:
        void inData(int a)
        {
            val = a;
        }
        void display()
        {
            cout<<val<<endl;
        }
};

class C2
{
    int val2;
    friend void swap(C1 &, C2 &);
    public:
        void inData(int a)
        {
            val2 = a;
        }
        void display()
        {
            cout<<val2<<endl;
        }
};

void swap(C1 &oc1, C2 &oc2)//we used reference to change the origianl value 
{
    oc1.val = oc1.val + oc2.val2;
    oc2.val2 = oc1.val - oc2.val2;
    oc1.val = oc1.val - oc2.val2;
}
int main() {
    C1 oc1;
    C2 oc2;
    oc1.inData(34);
    oc2.inData(67);
    swap(oc1,oc2);
    cout<<"After swapping oc1 = ";
    oc1.display();
    cout<<"After swapping oc2 = ";
    oc2.display();
    return 0;
}