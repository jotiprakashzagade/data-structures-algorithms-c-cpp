#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin>>str;
    int q; 
    cin>>q;
    //precompute
    int size = str.size();
    int hash[26]{0};
    for(int i=0; i<size; i++){
        hash[str[i] - 'a'] += 1; //for uppercase str[i] - 'A'
    }
    
    while(q--){
        char c;
        cin>>c;
         cout<<hash[c-'a']<<endl;
    }
    
    return 0;
}