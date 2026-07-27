#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int *A;
    int size;
    int length;
}Array;

#define IS_INVALID(arr)((arr) == NULL || (arr)->A == NULL)

int delete(Array *arr, int index){
   if (IS_INVALID(arr) || index < 0 || index >= arr->length) {
        printf("Invalid index for deletion.\n");
        return -1;
    }
    int deleted = arr->A[index];
    for(int i = index; i < arr->length - 1; i++){
        arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
    return deleted;
}
 /*
 * NOTE ON DELETION & LOW-LEVEL MEMORY:
 * 
 * 1. Physical Memory Reality:
 *    At the hardware level, memory is never truly "deleted" or "cleared". 
 *    Deletion is merely a logical operation executed by left-shifting subsequent 
 *    elements and decrementing 'length'. The value at index = length remains in RAM, 
 *    but 'length' acts as a boundary gatekeeper—treating everything past length - 1 
 *    as invalid/garbage memory.
 * 
 * 2. Abstraction & Encapsulation:
 *    High-level languages (C++ STL vector, Java ArrayList, Python list) perform 
 *    this exact low-level copy and shift routine under the hood. They encapsulate 
 *    the raw buffer and length counter inside a class, exposing clean methods 
 *    like delete() or pop() to hide raw memory management from the user.
 * 
 * 3. Primitive Hardware Operations:
 *    Fundamentally, CPU/Hardware only understands memory addressing, data copying, 
 *    and arithmetic/logic operations. All abstract operations (insert, append, delete) 
 *    are built on top of these primitives.
 */