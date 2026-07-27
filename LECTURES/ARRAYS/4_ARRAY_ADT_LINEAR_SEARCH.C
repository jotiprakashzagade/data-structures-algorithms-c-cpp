/**********************************************************************
 * SUBJECT  : Data Structures & Algorithms (DSA)
 * TOPIC    : Array Abstract Data Type (ADT)
 * AUTHOR   : Jotipraksh Zagade
 * CLASS    : SYBSc.CS (Semester 3)
 * DATE     : 20 July 2026
 * LANGUAGE : C
 *
 * SEARCH TECHNIQUES:
 * 1. linearSearch()       - Normal sequential search, O(n) time complexity.
 * 2. searchTransposition()- Improved Search: Swaps the found element with its
 *                           immediate predecessor to gradually optimize access.
 * 3. searchMoveToFront()  - Improved Search: Moves the found element straight
 *                           to index 0 for immediate subsequent access.
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *A;
    int size;
    int length;
} Array;

// Macro check helper for clean, readable code
#define IS_INVALID(arr) ((arr) == NULL || (arr)->A == NULL)


void swap(int *x, int *y) {
    if (x == NULL || y == NULL) return;
    int temp = *x;
    *x = *y;
    *y = temp;
}

int linearSearch(Array *arr, int key) {
    if (IS_INVALID(arr) || arr->length <= 0) return -1;

    for (int i = 0; i < arr->length; i++) {
        if (key == arr->A[i])
            return i;
    }
    return -1;
}

//probabilty linear search variation 
int transpositionLinearSearch(Array *arr, int key) {
    if (IS_INVALID(arr) || arr->length <= 0) return -1;

    for (int i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) {
            if (i > 0) {
                swap(&arr->A[i], &arr->A[i - 1]);
                return i - 1; // Return new position
            }
            return i;
        }
    }
    return -1;
}

//probability linear search variavation
int moveToFrontLinearSearch(Array *arr, int key) {
    if (IS_INVALID(arr) || arr->length <= 0) return -1;

    for (int i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) {
            if (i > 0) {
                swap(&arr->A[i], &arr->A[0]);
                return 0; // Return new position at index 0
            }
            return i;
        }
    }
    return -1;
}

int sentinelLinearSearch(Array *arr, int key) {
    if (IS_INVALID(arr) || arr->length <= 0) return -1;

    int lastElement = arr->A[arr->length - 1];
    arr->A[arr->length - 1] = key;

    int i = 0;
    while (arr->A[i] != key) {
        i++;
    }

    arr->A[arr->length - 1] = lastElement;

    if (i < arr->length - 1 || lastElement == key)
        return i;

    return -1;
}

//order linear search
int orderdLinearSearch(Array *arr, int key){
    if(IS_INVALID(arr) || arr->length <= 0) return -1;

    for(int i = 0; i < arr->length; i++){
        if(key == arr->A[i]) return i;

        if(arr->A[i] > key) return -1;
    }
    return -1;
}

int main(){
    Array arr;
    int n;
    printf("Enter size of the Array : ");
    scanf("%d", &arr.size);

    arr.A = (int *)malloc(arr.size * sizeof(int));
    if (arr.A == NULL){
        printf("Memmory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter total number of elements in the array : ");
    scanf("%d", &n);

    if (n > arr.size){
        printf("Error:Number of elements (%d) exceeds allocated size (%d)\n", n, arr.size);
        printf("Truncating input size to fit max size (%d).\n", arr.size);
        n = arr.size;
    }

    arr.length = 0;
    printf("Enter %d elements of the array : ", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr.A[i]);
        arr.length++;
    }

    int key;
    printf("Enter key element to search in the array : ");
    scanf("%d", &key);

    int index;
    //index = linearSearch(&arr, key);
    //index = linearSearchTransposition(&arr,key);
     index = linearSearchMoveToFront(&arr, key);

    if (index != -1){
        printf("Element %d found at index %d.\n", key, index);
    }
    else{
        printf("Element %d not found in the array.\n", key);
    }

    free(arr.A);
    arr.A = NULL;

    return 0;
}