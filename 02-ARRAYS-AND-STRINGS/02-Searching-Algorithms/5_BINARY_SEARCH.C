/**********************************************************************
 * SUBJECT  : Data Structures & Algorithms (DSA)
 * TOPIC    : Array Abstract Data Type (ADT)
 * AUTHOR   : Jotipraksh Zagade
 * CLASS    : SYBSc.CS (Semester 3)
 * DATE     : 21 July 2026
 * LANGUAGE : C
 *
 * SEARCH TECHNIQUES:
 * 1. BINARY SEARCH = SEARCHING IN SORTED LIST
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *A;
    int size;
    int length;
} Array;

// Macro check helper for clean, readable code
#define IS_INVALID(arr) ((arr) == NULL || (arr)->A == NULL)

int binarySearch(Array *arr, int key){

    if(IS_INVALID(arr) || arr->length <= 0) return -1;
    int l = 0; 
    int h = arr->length - 1;
   

    while(l<h){
        int mid = (l+h)/2;
        if(arr->A[mid] == key)
            return mid;
        else if(arr->A[mid] > key){
            h = mid - 1;           
        }
        else if(arr->A[mid] < key){
            l = mid + 1;
        }
    }
    return -1;
}

int main(){
    Array arr;
    int n;
    printf("Enter size of the Array : ");
    scanf("%d", &arr.size);

    arr.A = (int *)malloc(arr.size * sizeof(int));
    if (arr.A == NULL){
        printf("Memmory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter total number of elements in the array : ");
    scanf("%d", &n);

    if (n > arr.size){
        printf("Error:Number of elements (%d) exceeds allocated size (%d)\n", n, arr.size);
        printf("Truncating input size to fit max size (%d).\n", arr.size);
        n = arr.size;
    }

    arr.length = 0;
    printf("Enter %d elements of the array : ", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr.A[i]);
        arr.length++;
    }

    int key;
    printf("Enter key element to search in the array : ");
    scanf("%d", &key);

    int index;
    //index = linearSearch(&arr, key);
    //index = linearSearchTransposition(&arr,key);
     index = binarySearch(&arr, key);

    if (index != -1){
        printf("Element %d found at index %d.\n", key, index);
    }
    else{
        printf("Element %d not found in the array.\n", key);
    }

    free(arr.A);
    arr.A = NULL;

    return 0;
}