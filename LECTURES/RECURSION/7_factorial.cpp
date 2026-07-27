#include<bits/stdc++.h>
using namespace std;

int fact(int n){ // TC = O(N)  //SC = O(N)
    if(n == 1)return 1;

    return n * fact(n-1);
}
int main() {
    int n, factorial;
    cin>>n;
    factorial = fact(n);
    cout<<factorial;
    return 0;
}