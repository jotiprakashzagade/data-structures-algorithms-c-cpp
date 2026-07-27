#include<iostream>
using namespace std;

//complex number
//   |
//  \|/
// 1 + 4i
// 5 + 8i
//---------
// 6 + 12i

class complexNumber
{
    private:
        int a,b;
    public:
        friend complexNumber sumComplex(complexNumber o1, complexNumber o2);
        void setNumber(int n1, int n2)
        {
            a = n1;
            b = n2;
        }
        void printNumber()
        {
            cout<<"Your number is : "<<a<<" + "<<b<<"i"<<endl;
        }
};

complexNumber sumComplex(complexNumber o1, complexNumber o2)
{
    complexNumber o3;
    //o3.setNumber((o1.a + o2.a), (o1.b + o2.b)); ==> so in this line of code we are trying to access the 
    // private data of the class without directly like o1.a + o2.a , althoug it is inside the setNumber()
    // function but it doesnt matter because we can access private data only in the class functions and
    // sumCompex() function is global funtion not a class function so we can not access this like it
    // in this case there is a concept of the friend funciton , so to access this private data
    // in this kind of funciton we need to tell compiler using the friend keyword in the class defination 
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}
int main() {
    complexNumber c1, c2, sum;
    c1.setNumber(1,4);
    c2.setNumber(5,8);
    c1.printNumber();
    c2.printNumber();

    sum = sumComplex(c1,c2);

    sum.printNumber();


    
    return 0;
}

/*Properties of friend functions 
1.not in the scope of the class means it is not the function of the class it is just the friend functoin
or non member function that is allowed to access the private data 

2.since it is not in the scope of the class, it cannot be called from the object of the  of that class .
c1.sumComplext() == invalid 

3. can be invoked without the help of any object

4. Usally contians the objects as argumnets 

5. can be declared inside public or the private part of the class it doesnt matter 

6. it can not access the members dirctly by their names and need object_name.memeber_name to access any member
*/