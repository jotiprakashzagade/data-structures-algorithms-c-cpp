#include<bits/stdc++.h>
using namespace std;

void print(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<"-";
        }
        for(int j=1; j<=i*2-1; j++){
            cout<<"*";
        }
        for(int j=1; j<=n-i; j++){
            cout<<"-";
        }
        cout<<endl;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            cout<<"-";
        }
        for(int j=0; j<n*2-(i*2+1); j++){
            cout<<"*";
        }
        for(int j=0; j<i; j++){
            cout<<"-";
        }
        cout<<endl;
    }
}
int main() {
    int n;
    cin>>n;
    print(n);
    return 0;
}