#include <iostream>

using namespace std;

void fib(int);
int main() {
    int limit;cin>>limit;
    fib(limit);
    return 0;
}
void fib(int limit)
{
    int x=0,y=1;
    for(int i=1; i<=limit; i++)
    {
           cout<<x<<" "; // 0 1 1 2 3 5
        int next = x+y; // 1 1 2 3 5 8 
     
        x = y; // 1 1 2 3 5
        y = next; // 1 1 2 3 5

    }
}