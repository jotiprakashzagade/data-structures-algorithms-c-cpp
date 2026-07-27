#include<bits/stdc++.h>
using namespace std;

//fib() function
void fib(int n){
    if(n<=0){
        cout<<0;
        return;
    }
    if(n==1){
        cout<<1;
        return;
    }

    cout<<0<<" "<<1<<" ";
    int a=0; 
    int b=1;
    for(int i=2; i<n; i++){
        int temp = a;
        a = b;
        b = temp + b;
        cout<<b<<" "; 
    }
}

//main function
int main() {
    int n;
    cout<<"Enter how many of fibonacci numbers want to print : ";
    cin>>n;
    fib(n);
    return 0;
}