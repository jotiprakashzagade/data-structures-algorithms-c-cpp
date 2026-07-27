#include<bits/stdc++.h>
using namespace std;

//base class
class Employee{
    public:
    int id;
    float salary;
    Employee(int npid){
        id = npid;
        salary = 34;
    }
    Employee(){}
};

//derived class syntax
/*
class derived_class_name : visibility_mode base_class_name
    {
        //code
    }

Note:
1.visiblity mode can be private or public
2.if we keep mode public then , public members of base class inhereded as public in derived class
3.if we keep mode private then , public  members of base class inhereded as private in derived class
4.by default visibility mode is private    
5.private members of base class are never inhereted

*/

class Programmer :  Employee{  // here we do not give mode so by defualt it is private
    public:
    int languageCode = 9;
    Programmer(int npid){
        id = npid;
    }
    void getData(){
        cout<<id;
    }
};

int main() {
    Employee harry(1), rohan(2);
    cout<<harry.salary<<endl;
    cout<<rohan.salary<<endl;
    Programmer skillF(10);
    cout<<skillF.languageCode<<endl;
    skillF.getData();
    return 0;
}