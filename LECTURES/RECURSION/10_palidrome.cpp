#include<bits/stdc++.h>
using namespace std;

bool is_palidrome(string str,int size, int i){
    
    if(i>=size-i-1)return true;

    if(str[i] != str[size-i-1])return false;

    return is_palidrome(str, size, i+1);
    
}

int main() {
    string  str;
    cin>>str;
    int size = str.size();
    if(is_palidrome(str, size, 0))cout<<"True";
    else cout<<"False";
    
    
    return 0;
}