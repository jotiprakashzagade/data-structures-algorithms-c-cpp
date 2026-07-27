#include <iostream>

using namespace std;
void add(int,int);
void add(int,int,int c=0);

void fun(int);
void fun(int&);
int main() {
    add(1,2); /* In this call it is giving the error because compiler getting counfuse
    because with this both function are usable like this call can be accepted by 
    function with two int arg and also by the function with 3 arg in whcih last
    arg is default and thats why in this overloading comiler will through error*/
    add(1,2,3);
    fun(2); /*in this call also happing the same things of compiler confusion 
    because refernce is just anothher name given to the actual value*/
    return 0;
}