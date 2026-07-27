#include<bits/stdc++.h>
using namespace std;

bool is_palidrome(char str[], int size, int i){  //TC O(N/2) // 
    if(i>= size /2)return true;
    if(str[i] != str[size-i-1])return false;
    return is_palidrome(str, size, i+1);
}
int main() {
    int size;
    cin>>size;
    char str[size];
    for(int i=0; i<size; i++) cin>>str[i];
    if(is_palidrome(str, size, 0))cout<<"True";
    else cout<<"False";
    return 0;
}