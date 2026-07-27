#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int *A;
    int size;
    int length;
}Array;

#define IS_INVALID(arr)((arr) == NULL || (arr)->A == NULL)

float avarage(Array *arr){
   if (IS_INVALID(arr) || arr->length <= 0) return 0.0f;
   return (float)sum(arr) / arr->length;
}