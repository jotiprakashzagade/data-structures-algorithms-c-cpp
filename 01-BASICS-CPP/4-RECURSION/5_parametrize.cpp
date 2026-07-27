#include<bits/stdc++.h>
using namespace std;
//sum of first n numbers
void printSum(int i,int sum){ // TC = O(N)  //SC = O(N)
    if(i<1){
        cout<<sum<<endl;
        return;
    }
    printSum(i-1, sum+i);
}
int main() {
    int n,sum=0;
    cin>>n;
    printSum(n,sum);
    return 0;
}