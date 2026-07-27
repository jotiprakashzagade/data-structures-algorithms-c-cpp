#include<iostream>
using namespace std;

int main() {
    int n;cin>>n;
    unsigned long long a=0,b=1;
    for(int i=0; i<n; i++)
    {
        unsigned long long next = a+b;
        cout<<a<<"      ";
        a=b;
        b=next;
    }
    return 0;
}