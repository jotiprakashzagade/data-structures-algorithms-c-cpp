#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin>>str;
    int size = str.size();
    int q; 
    cin>>q;
    int hash[256]{0};
    for(int i=0; i<size; i++){
        hash[str[i]]++;
    }

    while(q--){
        char c;
        cin>>c;
        cout<<hash[c]<<endl;
    }
    
    return 0;
}