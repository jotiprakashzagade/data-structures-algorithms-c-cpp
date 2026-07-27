#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int *A;
    int size;
    int length;
}Array;

#define IS_INVALID(arr)((arr) == NULL || (arr)->A == NULL)

int recursiveSum(Array *arr, int i){
    if(i >= arr->length)
        return 0;
    return arr->A[i] + recursiveSum(arr, i + 1);
}