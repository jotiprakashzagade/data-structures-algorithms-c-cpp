#include<bits/stdc++.h>
using namespace std;

//In funciotnal reucrusion we return the some value to the 
//calleer function 

int printSum(int n){ // TC = O(N)  //SC = O(N)
    if(n<1)return 0;

    
    return (n+=printSum(n-1));

}
int main() {
    int n, sum = 0;
    cin>>n;
    sum = printSum(n);
    cout<<sum<<endl;
    return 0;
}