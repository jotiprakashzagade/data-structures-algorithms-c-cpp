#include<bits/stdc++.h>
using namespace std;

void insertInSorted(int A[], int *n, int x){
    int i = *n - 1;
    while(A[i] > x && i >=0){
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    *(n)++;
}

void insertionSortAscending(int A[], int n){
    for(int i = 1; i < n; i++){
        int temp = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > temp){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}

void insertionSortDescending(int A[], int n){
    for(int i = 1; i < n; i++){
        int temp = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] < temp){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}

int main() {
   
    int size;
    cin>>size;
    int A[size];
    for(int i = 0; i < size; i++){
        cin>>A[i];
    }
    insertionSortDescending(A, size);

    for(int i = 0; i < size; i++){
        cout<<A[i]<<" ";
    }
    return 0;
}