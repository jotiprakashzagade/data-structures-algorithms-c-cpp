#include<bits/stdc++.h>
using namespace std;

int primeCheck(int n){
    if(n<=1)return 0;

    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;

}
int main() {
    int n;
    cin>>n;
    if(primeCheck(n)){
        cout<<"Prime Number"<<endl;
    }
    else 
    cout<<"Not Prime Number"<<endl;
    return 0;
}