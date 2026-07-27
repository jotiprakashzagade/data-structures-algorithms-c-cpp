#include<bits/stdc++.h>
using namespace std;

void printDivisor(int n){
    vector<int> smallDivisor;
    vector<int> largDivisor;

    for(int i=1; i*i <= n; i++){
        if(n%i==0){
            smallDivisor.push_back(i);
            if(n/i != i)
                largDivisor.push_back(n/i);
        }
    }

    for(int i : smallDivisor){
        cout<<i<<" ";
    }
    for(int i = largDivisor.size()-1; i>=0; i--){
        cout<<largDivisor.at(i)<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    printDivisor(n);
    return 0;
}