/**********************************************************************
 * SUBJECT           : Data Structures & Algorithms (DSA)
 * TOPIC             : Linked List Abstract Data Type (ADT)
 * AUTHOR            : Jotiprakash Zagade
 * CLASS             : SYBSc.CS (Semester 3)
 * COLLEGE           : Ahmednagar College
 * GITHUB REPO       : https://github.com/jotiprakashzagade/data-structures-algorithms-c-cpp
 * FILE LINK         : https://github.com/jotiprakashzagade/data-structures-algorithms-c-cpp/blob/main/03-LINKED-LIST/01-Singly-Linked-List/Singly_Linked_List.c
 * RELATED FILE LINK : https://github.com/jotiprakashzagade/data-structures-algorithms-c-cpp/blob/main/02-ARRAYS-AND-STRINGS/01-Array-ADT/00_ARRAY_ADT.c
 * LANGUAGE          : C/C++
 * DATE              : 01-09-2026
 * 
 * OPERATIONS IMPLEMENTED:
 * 
 * 1. Memory Management:
 *    - freeLL()                    : Deallocates all nodes in the linked list
 *    - convertArrToLL()            : Converts a standard C array into a singly linked list
 *    - createLL()                  : Interactively builds a linked list from user input
 * 
 * 2. Traversals & Displays:
 *    - displayLL()                 : Iteratively prints nodes from head to tail
 *    - reverseDisplay()            : Non-recursively prints nodes in reverse using a buffer
 *    - recursiveDisplay()          : Prints nodes head-to-tail via call stack
 *    - recursiveReverseDisplay()   : Prints nodes tail-to-head via stack unwinding
 * 
 * 3. Utility & Analytics:
 *    - lengthOfLL()                : Counts total nodes in the list
 *    - minimumElementLL()          : Finds minimum integer value in list
 *    - maximumElementLL()          : Finds maximum integer value in list
 * 
 * 4. Search Operations:
 *    - linearSearchLL()            : Standard O(N) search on unsorted list
 *    - orderLinearSearch()         : Early-terminating O(N) search on sorted list
 * 
 * ... (Additional operations will be appended as implemented)
 * 
 **********************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

//function for deallocating heap memory used for linked list;
void freeLL(Node *head) {

    Node *temp;

    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp); 
    }
}

//function for creating linked list for n number of nodes;
Node* createLL(int n) {
    if(n <= 0) {
        printf("Invalid Input.\n");
        return NULL;
    }

    Node *head = NULL;
    Node *newNode = NULL;
    Node *temp = NULL;

    for(int i = 1; i <= n; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        if(newNode == NULL) {
            printf("heap memory allocation failed for linked list.\n");
            return head;
        }

        printf("Enter data for Node %d : ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else    
            temp->next = newNode;
        
            temp = newNode;
    }
    return head;
}

//function for count total nodes in the linked list;
int lengthOfLL(Node *head) {

    int cnt = 0;
    Node *temp = head;
    while(temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

//function for displaying/traversing linked list;
void displayLL(Node *head) {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;

    printf("**********Linked List**********\n");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;        
    }
    printf("\n");
}

//function for displaying linked list in reverse order;
void revDisplay(Node *head) {
    
    int len = lengthOfLL(head);

    int *arr = (int*)malloc(len * sizeof(int));
    
    Node *temp = head;
    for(int i = 0; i < len; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }

     printf("**********Linked List**********\n");
    for(int i = len - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
}

//recursive function for displaying linked list;
void recDisplay(Node *head) {
    if(head == NULL) return;

    printf("%d ", head->data);
    recDisplay(head->next);
}

//recursive function for displaying linked list in reverse order 
void recRevDisplay(Node *head) {
    if(head == NULL) return;

    recRevDisplay(head->next);
    printf("%d ", head->data);

}

//function for converting array to the linked list;
Node* convertArrToLL(int *arr, int arrSize) {

    if(arrSize <= 0) return NULL;

    Node *head = (Node*)malloc(sizeof(Node));
    if(head == NULL) {
        printf("heap memory allocation failed.\n");
        return NULL;
    }

    head->data = arr[0];
    head->next = NULL;
    Node *temp = head;
    Node *newNode = NULL;

    for(int i = 1; i < arrSize; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        if(newNode == NULL) {
            printf("heap memory allocation failed for linked list at index %d.\n", i);
            freeLL(head);
            return NULL;
        }
        newNode->data = arr[i];
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
    return head;    
} 

//function for searching element in linked list 
int linearSearchLL(Node *head, int value) {
    
    Node *temp = head;

    while(temp != NULL) {
        if(temp->data == value) return 1;

        temp = temp->next;
    }
    return 0;
}

//function for searching element in sorted linked list;
int orderLinearSearchLL(Node *head, int value) {
    
    Node *temp = head;
    while(temp != NULL) {
        if(temp->data == value) return 1;
        if(temp->data > value) return 0;
        temp = temp->next;
    }
    return 0;
}
//function for sum of elements in the linked list;
int sumElementsLL(Node *head) {

    Node *temp = head;

    int sum = 0; 

    while(temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}


//function for finding minimum element in the linked list
int minElementLL(Node *head) {

    int min = head->data;
    Node *temp = head->next;

    while(temp != NULL) {
        if(min > temp->data) min = temp->data;

        temp = temp->next;
        
    }
    return min;
}

//function for finding maximum element in the linked list
int maxElementLL(Node *head) {

    int max = head->data;
    Node *temp = head->next;

    while(temp != NULL) {
        if(max < temp->data) max = temp->data;

        temp = temp->next;
        
    }
    return max;
}


int main() {
    int arr[5] = {55,44,33,22,11};

    Node *head = convertArrToLL(arr, 5);
    printf("%d \n",maxElementLL(head));
    revDisplay(head);
    freeLL(head);

    return 0;  
}