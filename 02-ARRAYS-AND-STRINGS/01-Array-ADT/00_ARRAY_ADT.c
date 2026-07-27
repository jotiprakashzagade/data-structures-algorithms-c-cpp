/**********************************************************************
 * SUBJECT  : Data Structures & Algorithms (DSA)
 * TOPIC    : 1D Array Abstract Data Type (ADT)
 * AUTHOR   : Jotipraksh Zagade
 * CLASS    : SYBSc.CS (Semester 3)
 * COLLAGE  : Ahmednagar College
 * GITHUB REPOSITORY  : https://github.com/jotiprakashzagade/data-structures-algorithms-c-cpp
 * FILE LINK : 
 * LANGUAGE : C
 * 
 * OPERATIONS IMPLEMENTED:
 * 1. createArray()                 - Allocate heap memory for the array
 * 2. acceptArray()                 - Read initial elements from user
 * 3. displayArray()                - Output current array elements
 * 4. append()                      - Add element to the end of the array
 * 5. insert()                      - Insert element at index (right shift)
 * 6. delete()                      - Remove element at index (left shift)
 * 7. get()                         - Return element at specified index
 * 8. set()                         - Replace element at specified index
 * 9. Max()                         - Return maximum value in array
 * 10. Min()                        - Return minimum value in array
 * 11. sum()                        - Return total sum of elements
 * 12. recursiveSum()               - Return sum using recursion
 * 13. average()                    - Return average of elements
 * 14. swap()                       - Helper function to swap two integers
 * 15. reverse1()                   - In-place reversal using two pointers
 * 16. reverse2()                   - Reversal using auxiliary array
 * 17. leftShift()                  - Shift elements left by 1 position
 * 18. rightShift()                 - Shift elements right by 1 position
 * 19. isSorted()                   - Check if array is sorted ascending
 * 20. insertInSorted()             - Insert into sorted position
 * 21. rearrange()                  - Separate negative numbers to left
 * 22. appendArray()                - Append source array to target
 * 23. concatArrays()               - Concatenate two arrays into a third
 * 24. compareArrays()              - Compare two arrays for equality
 * 25. copyArray()                  - Deep copy of array structure
 * 26. mergeArrays()                - Merge two sorted arrays
 * 27. unionSortedArray()           - Set union for sorted arrays
 * 28. unionUnsortedArray()         - Set union for unsorted arrays
 * 29. intersectionSortedArray()    - Set intersection for sorted arrays
 * 30. intersectionUnsortedArray()  - Set intersection for unsorted arrays
 * 31. differenceSortedArray()      - Set difference for sorted arrays
 * 32. differenceUnsortedArray()    - Set difference for unsorted arrays
 * 33. setMembershipSortedArray()   - Check element presence in sorted set
 * 34. setMembershipUnsortedArray() - Check element presence in unsorted set
 * 
 * SEARCH TECHNIQUES:
 * 35. linearSearch()               - Sequential search, O(n)
 * 36. transpositionLinearSearch()  - Swap found item with predecessor
 * 37. moveToFrontLinearSearch()    - Move found item to index 0
 * 38. sentinelLinearSearch()       - Search without boundary check in loop
 * 39. orderedListLinearSearch()    - Early stop linear search for sorted lists
 * 40. binarySearch()               - Iterative binary search, O(log n)
 * 41. rbinSearch()                 - Recursive binary search, O(log n)
 **********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int *A;
    int size;
    int length;
}Array;

#define IS_INVALID(arr)((arr) == NULL || (arr)->A == NULL)

void createArray(Array *arr){
    if(arr == NULL){
        printf("Error : Array pointer is NULL.\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter size of the array : ");
    if(scanf("%d",&arr->size) != 1 || arr->size <= 0){
        printf("Invalid Capacity/size entered.\n");
        exit(EXIT_FAILURE);        
    }

    arr->A = (int*)malloc(arr->size*sizeof(int));
    if(arr->A == NULL){
        printf("Memmory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    arr->length = 0;
}

void acceptArray(Array *arr){
    if(IS_INVALID(arr) || arr->size <= 0) exit(EXIT_FAILURE);
    int n;
    printf("Enter total elements in the array : ");
    if(scanf("%d",&n) != 1)
        exit(EXIT_FAILURE);
    
    if(n <= 0){
        printf("No elements added.\n");
        return;
    }
    if(n > arr->size){
        printf("Error : Number of elements(%d) exceeds max size(%d).\n",n,arr->size);
        printf("Truncating input size to max size(%d).\n",arr->size);
        n = arr->size;
    }
    printf("Enter %d elements of the array : ",n);
    for(int i = 0; i < n; i++){
        if(scanf("%d", &arr->A[i]) == 1)
            arr->length++;
        else{
            printf("Invalid integer input encountered at index %d. Stopping reading.\n",i);
            break;
        }
    }
}

void displayArray(Array *arr){
    if(IS_INVALID(arr) || arr->size <= 0) exit(EXIT_FAILURE);

    if(arr->length > 0){
        for(int i = 0; i < arr->length; i++){
            printf("%d ",arr->A[i]);
        }
        printf("\n");
    }
}

void append(Array *arr, int x){
    if(IS_INVALID(arr))return;

    if(arr->length < arr->size){
        arr->A[arr->length++] = x;
    }
}

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
int get(Array *arr, int index){
    if (IS_INVALID(arr) || index < 0 || index >= arr->length) {
        return -1;
    }
    return arr->A[index];
}

void set(Array *arr, int index, int x){
    if (IS_INVALID(arr) || index < 0 || index >= arr->length) {
        printf("Invalid index for set operation.\n");
        return;
        }
    arr->A[index] = x;
}

int Max(Array *arr) {
    if (IS_INVALID(arr) || arr->length == 0) return -1;

    int max = arr->A[0];
    for (int i = 1; i < arr->length; i++) {
        if (arr->A[i] > max)
            max = arr->A[i];
    }
    return max;
}

int Min(Array *arr) {
    if (IS_INVALID(arr) || arr->length == 0) return -1;

    int min = arr->A[0];
    for (int i = 1; i < arr->length; i++) {
        if (arr->A[i] < min)
            min = arr->A[i];
    }
    return min;    
}

int sum(Array *arr){
    if (IS_INVALID(arr) || arr->length == 0) return 0;

    int total = 0;
    for (int i = 0; i < arr->length; i++) {
        total += arr->A[i];
    }
    return total;
}

int recursiveSum(Array *arr, int i){
    if(i >= arr->length)
        return 0;
    return arr->A[i] + recursiveSum(arr, i + 1);
}

float avarage(Array *arr){
   if (IS_INVALID(arr) || arr->length <= 0) return 0.0f;
   return (float)sum(arr) / arr->length;
}

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

/* Below functions defination is in github repository in independent files for each function
void leftShift();

void rightshift();

bool isSorted();

void insertInSorted(Array *arr, int x);

void rearrange(Array *arr);

void appendArray(Array *target, Array *source);

void concatArrays(Array *arr1, Array arr2, Array arr3);

void compareArrays(Array *arr1, Array arr2);

void copyArray(Array *arr);

void mergeArrays(Array *arr1, Array *arr2);

void unionSortedAray();

void unionUnsortedArray();

void intersectionSortedArray();

void intersectionUnsortedArray();

void differenceSortedArray();

void differenceUnsortedArray();

void setMembershipSortedArray();

void setMembershipUnsortedArray();
*/

int linearSearch(Array *arr, int key){
    if (IS_INVALID(arr) || arr->length <= 0) return -1;
    for(int i = 0; i < arr->length; i++){
        if(arr->A[i] == key)
            return i;
    }
    return -1;
}

//variation of probabilty search
int transpositionLinearSearch(Array *arr, int key) {
    if (IS_INVALID(arr) || arr->length <= 0) return -1;
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == key) {
            if (i > 0) {
                swap(&arr->A[i], &arr->A[i - 1]);
                return i - 1;
            }
            return i;
        }
    }
    return -1;
}

//probability search variation
int moveToFrontLinearSearch(Array *arr, int key) {
    if (IS_INVALID(arr) || arr->length <= 0) return -1;
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == key) {
            if (i > 0) {
                swap(&arr->A[i], &arr->A[0]);
                return 0;
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

    if (i < arr->length - 1 || key == lastElement)
        return i;
    
    return -1;
}

int orderedListLinearSearch(Array *arr, int key) {
    if (IS_INVALID(arr) || arr->length <= 0) return -1;
    for (int i = 0; i < arr->length; i++) {
        if (key == arr->A[i])
            return i;
        if (arr->A[i] > key)
            return -1;
    }
    return -1;
}

int binarySearch(Array *arr, int key) {
    if (IS_INVALID(arr) || arr->length <= 0) return -1;

    int low = 0;
    int high = arr->length - 1; 
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr->A[mid] == key)
            return mid;
        else if (arr->A[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int rbinSearch(Array *arr, int low, int high, int key) {
    if (IS_INVALID(arr) || low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr->A[mid] == key)
        return mid;
    else if (arr->A[mid] < key)
        return rbinSearch(arr, mid + 1, high, key);
    else
        return rbinSearch(arr, low, mid - 1, key);
}

int main(){
     Array arr1;
    
    createArray(&arr1);

    accept(&arr1);

    /*
     Call any function 
     here to perform any operation on array 
    */
    display(&arr1);
    
    

    free(arr1.A);
    return 0;
}