#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int *A;
    int size;
    int length;
}Array;

#define IS_INVALID(arr)((arr) == NULL || (arr)->A == NULL)

void append(Array *arr, int x){
    if(IS_INVALID(arr))return;

    if(arr->length < arr->size){
        arr->A[arr->length++] = x;
    }
}