#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int *A;
    int size;
    int length;
}Array;

#define IS_INVALID(arr)((arr) == NULL || (arr)->A == NULL)

void set(Array *arr, int index, int x){
    if (IS_INVALID(arr) || index < 0 || index >= arr->length) {
        printf("Invalid index for set operation.\n");
        return;
        }
    arr->A[index] = x;
}