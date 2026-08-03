#include<bits/stdc++.h>
using namespace std;

void mergeSort(int *arr, int start, int end){
    if(start >= end)return;

    int mid = start + (end - start)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    int i = start;
    int j = mid + 1;
    int k = 0;

    int *temp = (int*)malloc((end - start + 1) * sizeof(int));

    while(i <= mid && j <= end){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        }
        else{
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i <= mid){
        temp[k] = arr[i];
        k++;
        i++;
    }
    while(j <= end){
        temp[k] = arr[j];
        k++;
        j++;
    }

    for(int idx = start; idx <= end; idx++){
        arr[idx] = temp[idx - start];
    }
}

int main() {
    int n;
    cin>>n;
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}