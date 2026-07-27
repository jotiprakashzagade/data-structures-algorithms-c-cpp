#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int *A;
    int size;
    int length;
}Array;

#define IS_INVALID(arr)((arr) == NULL || (arr)->A == NULL)

void reverse2(Array *arr){
    if (IS_INVALID(arr) || arr->length <= 0) return;

    int *B = (int*)malloc(arr->size * sizeof(int));
    if (B == NULL) {
        printf("Memory allocation failed during reversing the array.\n");
        return;
    }
    for (int i = 0, j = arr->length - 1; i < arr->length; i++, j--) {
        B[i] = arr->A[j];
    }
    for (int i = 0; i < arr->length; i++) {
        arr->A[i] = B[i];
    }
    free(B);
}