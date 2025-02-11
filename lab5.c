#include <stdio.h>
#include "intlist.h"
#include <string.h>
#include <stdlib.h>
// Read the documentation for memmove (note: need string.h for memmove) and memcpy. Why is memcpy an
// inappropriate choice when implementing list insert and list delete?


void grow_capacity(IntList *list){

    //grow the capacity, resize 
    //size plus 1 because integer is 1
    if (list -> size + 1 > list -> capacity){
        int new_capacity = (list -> capacity)*2; 
        (list -> data)= (int*) realloc(list -> data, new_capacity* sizeof(int)); 
        //realloc preserves the original data (not the memory, might need to copy to a new location but the content is preserved), returns new location 
    }

}
// Allocate memory for an object of type IntList, initialize
// its data to equal the data in data_arr, and set its size
// Store the address of the new object in *p_IntList
void create_list_from_data(IntList **p_IntList, int *data_arr, int size){
    //dereference the int list and allocates memory to the list 
    *p_IntList = (IntList *)malloc(sizeof(IntList));
    (*p_IntList) -> capacity = size; //how do you determine the size of the capacity?

    //allocates the size of an integer into memory with a specific capacity 
    (*p_IntList) -> data = (int *)malloc(sizeof(int)*(*p_IntList) -> capacity); //malloc returns void* by default-> changes the type that is returned

    //if malloc cant return the the amount of memory requested 
    if ((*p_IntList) -> data == NULL){
        printf("Error: failed to create the integer"); 
    }
    memmove((**p_IntList).data, data_arr, sizeof(int)*(size));
}

// Append new_elem to the end of list
void list_append(IntList *list, int new_elem){
    //check if there is enough memory 
    //size + 1, keeps tracks the number of integers and adds it by its size (1int= 4byte)
    //size can also contain the number of bytes of a certain type 
    grow_capacity(list); 

    //adds to the end of the 
    list -> data[list->size] = new_elem; 
    //update size
    list-> size ++; 
}

// Insert new_elem at index in list. new_elem should now be at
// location index.
// Use the function memmove to move elements of list->data as needed
// If the capacity needs to grow, use realloc to increase the capacity by
// a factor of 2
void list_insert(IntList *list, int new_elem, int index){
    //check indexing
    if (index < 0 || index > list->size){
        printf("Incorrect indexing");
        exit(1);
    }
    grow_capacity(list); 
    //memmove moves content that overrides to a buffer, but memcopy will override the content
    //&(list->data)[index] take the address of the index of the data 
    //(list -> data)+(index*sizeof(int))
    //index + 1 because you are only moving one element 
    memmove(&(list->data)[index+1],&(list->data)[index], sizeof(int)*((list->size)-index)); 
    //you move it, then insert at the source
    list->data[index] = new_elem;
    
}

// Delete the element at index index
void list_delete(IntList *list, int index){
    if (index < 0 || index > list->size){
            printf("Incorrect indexing");
            exit(1);
    }
    list -> data[index] = 0; //zero? 
    //what if the index is zero?, then index -1 will be negative
    memmove(&(list->data)[index], &(list->data)[index-1], sizeof(int)*(list->size)-index);
}


// call free as appropriate to free the memory used by list
// Note: the order in which you free list->data and list
// itself is important (how?)
void list_destroy(IntList *list){
    free(list->data); 
    free(list);
}
// Return the element at index index in list
int list_get(IntList *list, int index){
    return (list -> data)[index];
}


