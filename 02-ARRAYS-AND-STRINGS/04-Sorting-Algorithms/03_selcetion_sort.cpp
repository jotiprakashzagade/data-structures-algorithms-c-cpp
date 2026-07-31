#include<bits/stdc++.h>
using namespace std;

void selectionSortAscending(int A[], int n){
    for(int i = 0; i < n - 1; i++){
        int min_index = i;
        for(int j = i + 1; j < n; j++){
            if(A[min_index] > A[j]){
                min_index = j;
            }
        }
        if(min_index != i)
            swap(A[min_index], A[i]);
    }
}

void selectionSortDescending(int A[], int n){
    for(int i = 0; i < n - 1; i++){
        int min_index = i;
        for(int j = i + 1; j < n; j++){
            if(A[min_index] < A[j])
                min_index = j;
        }
        swap(A[min_index], A[i]);
    }
}

int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i = 0; i < n; i++)cin>>A[i];
    selectionSortAscending(A,n);
    for(int i = 0; i < n; i++)cout<<A[i]<<" ";
    return 0;
}