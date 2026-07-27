#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int *A;
    int size;
    int length;
}Array;

#define IS_INVALID(arr)((arr) == NULL || (arr)->A == NULL)

int get(Array *arr, int index){
    if (IS_INVALID(arr) || index < 0 || index >= arr->length) {
        return -1;
    }
    return arr->A[index];
}