#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int *A;
    int size;
    int length;
}Array;

#define IS_INVALID(arr)((arr) == NULL || (arr)->A == NULL)

int Max(Array *arr) {
    if (IS_INVALID(arr) || arr->length == 0) return -1;

    int max = arr->A[0];
    for (int i = 1; i < arr->length; i++) {
        if (arr->A[i] > max)
            max = arr->A[i];
    }
    return max;
}