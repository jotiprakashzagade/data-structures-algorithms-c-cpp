#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
   while(a > 0){
    int temp = a;
    a =  b % a;
    b = temp;
   }
   return b;
}
int main()
{
    int a, b;
    cin>>a>>b;
    cout<<GCD(a,b);
    return 0;
}