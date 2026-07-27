#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[], int size, int i){
    if(i>= size/2)return;

    arr[i] = arr[i] + arr[size-i-1];
    arr[size-i-1] = arr[i] - arr[size-i-1];
    arr[i] = arr[i] - arr[size-i-1];

    reverse(arr, size, i+1);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    reverse(arr, n, 0);
    
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    reverse(arr, n, 0);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    return 0;
}