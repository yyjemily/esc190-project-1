//#3, 5, 7
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val; 
    struct node *next; //pointer to another node

    //Node (int v, Node *nxt = 0): val(v), next(next) {}
}node;


void moveToEnd(node* front, node* end, int k){
    //contained [a, b, c, d], k is 2, then output is [c,d,a,b]
    //want the head of the LL to point to the the k + 1 node 
    
    node* cur = malloc(sizeof(node));

    //a->c
    //find location of node c  
    for (int i =0; i < k; i++){
        cur = cur -> next; 
    }
    //set node c to front node
    end -> next = front; 

    //set front node to node c 
    front = cur -> next; 
    cur -> next = NULL; 

}
// Helper function to print the list
void printList(node* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
//-----------------------------------------------------------------------
//Question 5 
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
//rearrannge 0's 1's and 2's in list so that the 0s come first, -> basically in order
void ductch(int *list, int size){
    int low = 0, mid = 0, high = size - 1; 
    while (mid <= high){
        if (list[mid] == 0){
            swap(&(list[low]), &(list[mid]));
            low ++; 
            mid ++;
        }
        else if (list[mid] == 1){
            mid ++; 
        }
        else if (list[mid] == 2){
            swap(&(list[mid]), &(list[high]));
            high --; //want everything to the right of high to be 2
        }

    }
        
}
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");  // Add comma except for last element
    }
    printf("]\n");
}


int main() {
    int ls [7] = {0, 0 , 1, 2, 0 , 2, 1}; 
    ductch(ls, 7);
    printArray(ls, 7);
    // //Q3
    // node* node4 = malloc(sizeof(node));
    // node4->val = 4;
    // node4->next = NULL;

    // node* node3 = malloc(sizeof(node));
    // node3->val = 3;
    // node3->next = node4;

    // node* node2 = malloc(sizeof(node));
    // node2->val = 2;
    // node2->next = node3;

    // node* front = malloc(sizeof(node));
    // front->val = 1;
    // front->next = node2;

    // node* end = node4;  // Explicitly set end to last node

    // printf("Original list: ");
    // printList(front);  // Output: 1 2 3 4

    // // Move first 2 nodes to end
    // moveToEnd(front, end, 2);

    // printf("After moving first 2 to end: ");
    // printList(front);  // Output: 3 4 1 2

    // free(front); free(node2); free(node3); free(node4);
    return 0;
}
