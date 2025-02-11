#include <stdio.h>
#include "intlist.h"
#include <string.h>
#include <stdlib.h>

int main (){
    int data_arr[8]= {1,2,3,4,5,6,7,8};
    IntList *l; 
    //want to pass in an existing pointing to 
    IntList **ls = &l; 
    //copies data_arr into ls locations
    //data_arr is already APOINTER 
    create_list_from_data(ls, data_arr, 8); 

    //*ls accesses the content of the pointer 
    list_append(*ls, 9);

    //*ls is the structure, *ls -> data contains the array 
    for (int i=0; i < (l-> size); i++) {
        printf("%d\n", (l -> data)[i]); 
    }
   


}