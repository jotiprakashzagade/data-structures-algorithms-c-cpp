#include<bits/stdc++.h>
using namespace std;

int main() {
    //static normal array completely in the stack;
    int array[2][3]; // this is the true array as it is stored in continuse memmory 

    //2d array using the array of pointer
    int *array2[2];//this the array of 2 pointer to int i.e each element of this arr is ptr to the int,in stack

    array2[0] = new int[4]; // now ptr 0 is pointing to heap memmory location 
    array2[1] = (int*)malloc(4*sizeof(int)); // ptr 1 is pointing to heap memmory location but it is not 
    // continuation of the array2[0], it is completly diffrent location thats why it is not true array
    array2[2] = new int[4];

/*    STACK (Continuous)               HEAP (Scattered)
+--------+--------+--------+     +---+---+---+---+
|  A[0]  |  A[1]  |  A[2]  | ──> |   |   |   |   | (4 ints allocated somewhere)
+--------+--------+--------+     +---+---+---+---+
     │        │
     │        └────────────────> +---+---+---+---+
     │                           |   |   |   |   | (4 ints allocated elsewhere)
     │                           +---+---+---+---+
     └─────────────────────────> +---+---+---+---+
                                 |   |   |   |   | (4 ints allocated elsewhere)
                                 +---+---+---+---+
*/

    















    
    //2d array using the double pointer 
    int **array3;//this is double pointer in the stack
    array3 = new int*[3]; //array3 is pointing in heap memmory to the array of three pointers
    //in c => array3 = (int**)malloc(3*sizeof(int*))

    array3[0] = new int[4]; // now from the array3[0] which is the ptr in array of ptr in heap is pointing to
    // new array of  4 integers 
    array3[1] = (int*)malloc(4*sizeof(int));

/*STACK (Continuous)      HEAP (Scattered / Dynamic Blocks)
+--------+              +--------+--------+--------+
|   A    | ───────────> |  A[0]  |  A[1]  |  A[2]  |  (Array of 3 pointers)
+--------+              +--------+--------+--------+
                            │        │        │
                            │        │        └───────────────> +---+---+---+---+
                            │        │                          |   |   |   |   | (Row 2)
                            │        │                          +---+---+---+---+
                            │        └────────────────> +---+---+---+---+
                            │                           |   |   |   |   | (Row 1)
                            │                           +---+---+---+---+
                            └────────────────────────> +---+---+---+---+
                                                       |   |   |   |   | (Row 0)
                                                       +---+---+---+---+*/


    return 0;
}