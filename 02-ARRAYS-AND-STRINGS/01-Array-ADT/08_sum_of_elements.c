#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int *A;
    int size;
    int length;
}Array;

#define IS_INVALID(arr)((arr) == NULL || (arr)->A == NULL)

int sum(Array *arr){
    if (IS_INVALID(arr) || arr->length == 0) return 0;

    int total = 0;
    for (int i = 0; i < arr->length; i++) {
        total += arr->A[i];
    }
    return total;
}