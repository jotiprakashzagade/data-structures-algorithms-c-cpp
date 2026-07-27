#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int *A;
    int size;
    int length;
}Array;

#define IS_INVALID(arr)((arr) == NULL || (arr)->A == NULL)

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverse1(Array *arr){
    if (IS_INVALID(arr) || arr->length <= 0) return;

    for (int i = 0, j = arr->length - 1; i < j; i++, j--) {
        swap(&arr->A[i], &arr->A[j]);
    }
}