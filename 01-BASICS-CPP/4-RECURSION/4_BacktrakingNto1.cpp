#include<bits/stdc++.h>
using namespace std;
//print n to 1
void backTrackPrint(int i,int n){ 
    
    if(i>n)return;

    backTrackPrint(i+1, n);
    cout<<i<<endl;    
}

int main() {
    int n;
    cin>>n;
    backTrackPrint(1,n);
    return 0;
}