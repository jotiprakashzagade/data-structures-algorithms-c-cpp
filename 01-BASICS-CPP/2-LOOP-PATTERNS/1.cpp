/*STEPS TO SLOVE ANY PATTER :

1.For the outer loop count the number of rows
2.for inner loop , foucus on the columns and connect 
   them somehow to rows
3.Whatever you are pirnting , print in the inner loop
4.Observe symmetry [optional]*/

/*
*****
*****
*****
*****
*****
*/

#include<bits/stdc++.h>
using namespace std;

void printPattern(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int main() {
    int n;
    cin>>n;
    printPattern(n);
    
    return 0;
}