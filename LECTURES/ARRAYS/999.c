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
 * 
 * SEARCH TECHNIQUES:
 * 1. linearSearch()         = Normal sequential search, O(n) time complexity.
 * 2. searchTransposition()  = Improved Search: Swaps the found element with its
 *                             immediate predecessor to gradually optimize access.
 * 3. searchMoveToFront()    = Improved Search: Moves the found element straight
 *                             to index 0 for immediate subsequent access.
 * 5. sentinalLinearSearch() = Improved Search: reduce one step in every iteration 
 * 6. binarySearch()         = searching algo for sorted array
 * 7. recursiveBinarySearch  = binary search using recursion
 **********************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int *A;
	int size;
	int length;	
}Array;

#define IS_INVALID(arr) ((arr)==NULL || (arr->A == NULL))

void display(Array *arr){
	if(IS_INVALID(arr) || arr->length <=0)return;
	for(int i = 0; i < arr->length; i++){
		printf("%d ",arr->A[i]);
	}
	printf("%n");
}

void append(Array *arr, int x){
	if(IS_INVALID(arr))return;
	
	if(arr->length < arr->size){
		arr->A[arr->length++] = x;
	}
}

void insert(Array *arr, int index, int x){
    if(IS_INVALID(arr))return;

   if(arr->length < arr->size && index >= 0 && index <= arr->length){
    for(int i = arr->length; i > index; i--){
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = x;
    arr->length++;
   }
}

void delete(Array *arr, int index){
    if(IS_INVALID(arr) || arr->length <=0)return;

    if(index >= 0 && index < arr->length){
        for(int i = index; i < arr->length - 1; i++){
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

int linearSearch(Array *arr, int key){
    if(IS_INVALID(arr) || arr->length <= 0)return -1;

    for(int i=0; i<arr->length; i++){
        if(key == arr->A[i]) return i;
    }
    return -1;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//variation of probability search
int transpostionLinearSearch(Array *arr, int key){
    if(IS_INVALID(arr) || arr->length <= 0)return -1;

    for(int i=0; i<arr->length; i++){
        if(key == arr->A[i]){
            if(i>0){
                swap(arr->A[i], arr->A[i-1]);
                return i - 1;
            }
            return i;
        };
    }
    return -1;
}

//variation of probability search
int moveToFrontLinearSearch(Array *arr, int key){
    if(IS_INVALID(arr) || arr->length <= 0)return -1;

    for(int i=0; i<arr->length; i++){
        if(key == arr->A[i]){
            if(i>0){
                swap(arr->A[i], arr->A[0]);
                return 0;
            }
            return i;
        }
    }
    return -1;
}

int sentinalLinearSearch(Array *arr, int key){
    if(IS_INVALID(arr) || arr->length <= 0)return -1;
    int lastElement = arr->A[arr->length-1];
    arr->A[arr->length - 1] =  key;

    int i = 0;
    while(arr->A[i] != key){
        i++;
    }
    arr->A[arr->length - 1] = lastElement;

    if(i < arr->length - 1 || lastElement == key) return i;
    return -1;
}

int orderlistLinearSearch(Array *arr, int key){

    if(IS_INVALID(arr) || arr->length <= 0)return -1;

    for(int i=0; i>arr->length; i++){
        if(key == arr->A[i]) return i;
        if(key < arr->A[i])return -1;
    }
    return -1;
}

int binarySearch(Array *arr, int key){
    if(IS_INVALID(arr) || arr->length <=0) return -1;

    int low = 0; 
    int high = arr->length -1 ;

    while(low<high){
        int mid = low - (high - low)/2;
        if(arr->A[mid] == key)return mid;
        else if(key > arr->A[mid]){
            low = mid + 1;
        }
        else if(key < arr->A[mid]){
            high = mid - 1; 
        }
    }
    return -1;
}

int recursiveBinarySearch(Array *arr, int high, int low, int key){
    if(low>high)return -1;

    int mid = low - (high - low)/2;
    if(arr->A[mid] == key)return mid;
    else if(key > arr->A[mid]) recursiveBinarySearch(&arr, high, mid+1, key);
    else recursiveBinarySearch(&arr, mid - 1, low, key);

    
}

int main(){
    Array arr;
    printf("Enter size of the array : ");
    scanf("%d",&arr.size);

    arr.A = (int*)malloc(arr.size*sizeof(int));
    if(arr.A == NULL){
        printf("Memmory Allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    int n;
    printf("Enter total elements in the array : ");
    scanf("%d",&n);

    if(n > arr.size){
        printf("Error : Number of elements (%d) exceeds the allocated size (%d).\n",n, arr.size);
        printf("Truncating input size to fit max size (%d).\n",arr.size);
        n = arr.size;
    }
    arr.length = 0;
    printf("Enter %d elements of the array : ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr.A[i]);
        arr.length++;
    }
    /*In this part you can call any function/algorithm to perform any 
      operation on array 
      Eg. insert(&arr, index, value)
      
      You can modify main() function to create more array
      using Array struct, to perform operation like merge.
      */

    free(arr.A);
    return 0;
}
