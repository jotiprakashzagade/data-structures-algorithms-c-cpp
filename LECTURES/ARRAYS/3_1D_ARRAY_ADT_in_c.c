/**********************************************************************
 * SUBJECT  : Data Structures & Algorithms (DSA)
 * TOPIC    : Array Abstract Data Type (ADT)
 * AUTHOR   : Jotipraksh Zagade
 * CLASS    : SYBSc.CS (Semester 3)
 * DATE     : 20 July 2026
 * LANGUAGE : C
 * 
 * OPERATIONS IMPLEMENTED:
 * 1. display()  - Outputs the current array elements
 * 2. append()   - Adds an element to the end of the array
 * 3. insert()   - Inserts an element at a specific index (with right shift)
 * 4. delete()   - Removes an element from a specific index (with left shift)
 **********************************************************************/


#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int *A;
    int size;
    int length;
}Array;

// Macro check helper for clean, readable code
#define IS_INVALID(arr) ((arr) == NULL || (arr)->A == NULL)

void allocateMemmory(Array *arr){
    arr->A = (int*)malloc(arr->size*sizeof(int));
    if(arr->A == NULL){
        printf("Memmory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

void accept(Array *arr){
    int n;
    printf("Enter total number of elements in the arrray : ");
    scanf("%d",&n);
    if(n > arr->size){
        printf("Error:Number of elements (%d) exceeds allocated size (%d)\n",n,arr->size);
        printf("Truncating input size to fit max size (%d).\n",arr->size);
        n = arr->size;
    }
   
    arr->length = 0;
    printf("Enter %d elements of the array : ",n);
    for(int i=0; i<n; i++){
        scanf("%d",&arr->A[i]);
        arr->length++;
    }
}

void display(Array *arr) {
    if (IS_INVALID(arr)) return;
    
    printf("Array : ");
    for (int i = 0; i < arr->length; i++) {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}

void append(Array *arr, int x) {
    if (IS_INVALID(arr)) return;

    if (arr->length < arr->size) {
        arr->A[arr->length++] = x;
    }
}

void insert(Array *arr, int index, int x) {
    if (IS_INVALID(arr)) return;

    if (arr->length < arr->size && index >= 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

void delete(Array *arr, int index) {
    if (IS_INVALID(arr)) return;

    if (index >= 0 && index < arr->length) {
        for (int i = index; i < arr->length - 1; i++) {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
}
    //after delete function if we observe at index = length it still contains the
    //actual value  i.e. it does not delete it from the array, so it means  at low level
    // or hardware we do not inser, append , delete , we actully just copy and shift the
    //values at diifernt index , and length act as the gatekeeper means it tells
    // values till length - 1 index are valid after that values are garbage or invalid 
    // in langs like c++ or java or python where stl, java collection of diffrent librires exist
    // in this lang also same praocess occur undre the hood or at low level but it just 
    //  hide from the user that is  abstraction and like we use sruct in c , in langs
    // like java , python, and c++  bundel both data(space,size,length)
    // and their methods(function like insert,delete) in class that is incapsulation

    // so at low level hardware only know data copying and arithmetic operation 

int get(Array *arr, int index){
   
    if(index >= 0 && index < arr->length){
        return arr->A[index];
    }
}

void set(Array *arr, int index, int x){
    if(IS_INVALID(arr))return;
    if(index >=0 && index < arr->length){
        arr->A[index] = x;
    }
}

int Max(Array *arr){
   
    int max = arr->A[0];

    for(int i = 1; i < arr->length; i++){
        if(arr->A[i] > max) max = arr->A[i];
    }
    return max;
}

int Min(Array *arr){
    
    int min = arr->A[0];
    for(int i = 1; i < arr->length; i++){
        if(arr->A[i] < min) min = arr->A[i];
    }
    return min;
}

int sum(Array *arr){
    
    int total = 0;
    for(int i = 0; i < arr->length; i++){
        total += arr->A[i];
    }
    return total;
}

int recursiveSum(Array *arr , int n){
    if(n <= arr->length)return 0;

    return arr->A[n] + recursiveSum(arr, n + 1);
}

int average(Array *arr){
    
    int total = 0;
    for(int i = 0; i <= arr->length; i++){
        total += arr->A[i];
    }
    return total/arr->length;
}

void reverse1(Array *arr){
    int *B; 
    B = (int*)malloc(arr->size*sizeof(int));
    if(B == NULL){
        printf("Memmory allocation fialed during reversing array.\n");
        return;
    }

    for(int i = 0, j = arr->length - 1; j >= 0; j--, i++){
        B[i] = arr->A[j];
    }
    for(int i = 0; i<arr->length; i++){
        arr->A[i] = B[i];
    }
    free(B);
    B = NULL; 
}

void reverse2(Array *arr){
    if(IS_INVALID(arr))return;

    for(int i = 0, j = arr->length - 1;  i < j; i++, j--){
       int temp = arr->A[i];
       arr->A[i] = arr->A[j];
       arr->A[j] = temp;
       
       //we can also do swap(&arr->A[i], &arr->A[j]); 
    }
}

void leftShift(Array *arr){

}

void insertInSorted(Array *arr, int x){
    if(IS_INVALID(arr))return;

    if(arr->length < arr->size){
        int i = arr->length - 1;
        while(i >= 0 && arr->A[i] > x){
            arr->A[i + 1] = arr->A[i];
            i--; 
        }
        arr->A[i + 1] = x;
        arr->length++;
    }
}

int isSorted(Array *arr){
    for(int i = 0; i < arr->length - 1; i++){
        if(arr->A[i] > arr->A[i + 1])
            return 0;
    }
    return 1;

}

//rearrange the negative number on left side and positive on the right side, it is not sorted array
//it just rearrage element based on the their sign 
void rearrange(Array *arr){
    int i = 0;
    int j = arr->length - 1;
    while(i < j){
        while(arr->A[i] < 0)i++;
        while(arr->A[i] >= 0)j--;

        if(i < j){
            int temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
    }
}

void appendArray(Array *target, Array *source);

void concatArrays(Array *arr1, Array arr2, Array arr3);

void compareArrays(Array *arr1, Array arr2);

void copyArray(Array *arr);

Array* mergeArrays(const Array *arr1, const Array *arr2){

    if(arr1 == NULL || arr2 == NULL || arr1->A == NULL || arr2->A == NULL)return NULL;

    int i, j, k;
    i = j = k = 0;

    Array *arr3 = (Array*)malloc(sizeof(Array));
    if(arr3 == NULL)return NULL;

    arr3->length = arr1->length + arr2->length;
    arr3->size = arr1->length + arr2->length;
    
    arr3->A = (int*)malloc(arr3->length*sizeof(int));
    if(arr3->A == NULL){
        free(arr3);
        return NULL;
    }

    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];            
    }
    while(i < arr1->length)
        arr3->A[k++] = arr1->A[i++];
    while(j < arr2->length)
        arr3->A[k++] = arr2->A[j++];

    return arr3; //returing ptr to struct Array
}

void unionSortedArray();

void unionUnsortedArray();

void intersectionSortedArray();

void intersectionUnsortedArray();

void differenceSortedArray();

void differenceUnsortedArray();

void setMembershipSortedArray();

void setMembershipUnsortedArray();



int main() {
    Array arr1;
    int n;
    printf("Enter size of arrray : ");
    scanf("%d",&arr1.size);
    allocateMemmory(&arr1);

    accept(&arr1);

    rearrange(&arr1);
    display(&arr1);
    
    

    free(arr1.A);
    
    return 0;
}