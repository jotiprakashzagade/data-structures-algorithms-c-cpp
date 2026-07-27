/*  **********
    ****  ****
    ***    ***
    **      **
    *        *
    *        *
    **      **
    ***    ***
    ****  ****
    **********      

   */
#include <bits/stdc++.h>
using namespace std;

void printPattern(int n){

   for(int i=0; i <n ; i++){
    //stars
    for(int j=1; j<=n-i; j++){
        cout<<"*";
    }
    //spaces
    for(int j=1; j<=i*2; j++){
        cout<<" ";
    }

    //stars
    for(int j=1; j<=n-i; j++){
        cout<<"*";
    }


    cout<<endl;
   }

   for(int i=0; i<n; i++){
      //stars
    for(int j=1; j<=i+1; j++){
        cout<<"*";
    }
    //spaces
    for(int j=1; j<=(n*2)-((i+1)*2); j++){
        cout<<" ";
    }

    //stars
    for(int j=1; j<=i+1; j++){
        cout<<"*";
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