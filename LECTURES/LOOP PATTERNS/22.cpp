/*  
4 4 4 4 4 4 4
4 1 1 1 1 1 4
4 1 2 2 2 1 4
4 1 2 3 2 1 4    
4 1 2 2 2 1 4
4 1 1 1 1 1 4
4 4 4 4 4 4 4

   */
#include <bits/stdc++.h>
using namespace std;

void printPattern(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0 || i==n-1 || j==0 || j==n-1){
                cout<<"*";
            }
            else cout<<" ";
        }
        cout<<endl;
    }  
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        printPattern(n);
    }
    return 0;
}