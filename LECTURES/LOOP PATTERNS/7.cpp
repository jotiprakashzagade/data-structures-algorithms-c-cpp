/*
    *
   ***
  *****
 *******
*********
*/

#include<bits/stdc++.h>
using namespace std;

void printPattern(int n){
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n-i; j++){
        cout<<" ";
    }
    for(int j=1; j<=i*2-1; j++){
        cout<<"*";
    }
    cout<<endl;
  }
}
int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        printPattern(n);
        cout<<endl;
    }
    
    
    return 0;
}