/*  
*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        * 

   */
#include <bits/stdc++.h>
using namespace std;

void printPattern(int n){

   for(int i=1; i <=2*n-1; i++){
    int stars = i;
    int spaces = (n*2) - (i*2);
    if(i>n){
        stars = n*2 - i;
        spaces = (i*2) - (n*2);
    } 
    //stars
    for(int j=1; j<=stars; j++){
        cout<<"*";
    }
    //spaces
    
    for(int j=1; j<=spaces; j++){
        cout<<" ";
    }

    //stars
    for(int j=1; j<=stars; j++){
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