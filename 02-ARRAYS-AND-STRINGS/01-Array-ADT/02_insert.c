#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int *A;
    int size;
    int length;
}Array;

#define IS_INVALID(arr)((arr) == NULL || (arr)->A == NULL)

void insert(Array *arr, int index, int x){
    if(IS_INVALID(arr))return;

    if(index >= 0 && index <= arr->length &&  arr->length < arr->size){
        for(int i = arr->length; i > index; i--){
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}