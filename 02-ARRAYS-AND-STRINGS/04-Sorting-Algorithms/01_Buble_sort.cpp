#include<bits/stdc++.h>
using namespace std;

//standard buble sort for acending sorter
void bubleSortAcending(int A[], int n){
    for(int i = 0; i < n - 1; i++){
        int didSwap = 0;
        for(int j = 0; j < n - 1 - i; j++){
            if(A[j] > A[j + 1]){
                swap(A[j], A[j + 1]);
                didSwap = 1;
            }
        }
        if(!didSwap)
            break;
    }
}

//decending
void bubleSortDecending(int A[], int n){
    for(int i = 0; i < n - 1; i++){
        int didSwap = 0;
        for(int j = 0; j < n - 1 - i; j++){
            if(A[j] < A[j + 1]){
                swap(A[j] , A[j + 1]);
                didSwap = 1;
            }
        }
        if(!didSwap)
            break;
    }
}


int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i = 0; i < n; i++)
        cin>>A[i];

    bubleSortDecending(A,n);
    for(int i = 0; i < n; i++)
        cout<<A[i]<<" ";
    
    return 0;
}