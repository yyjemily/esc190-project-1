#include <stdio.h>
#include <stdbool.h>

/*
In your main function, define the variable int a and initialize it to 5. Now, write a function which does
not return anything, but can set the value of an integer to 10.
Use this function to set the value of a to 10.
Use printf to demonstrate that the value of a changed.
Now, put a breakpoint at int a = 5, and trace the code.
Now, write a similar function in Python, and point out the similarities and/or differences.
*/
void change_a(int *p_a){
    *p_a = 10;
}
/*
In main(), initialize an array of chars by setting up a char arr[100]. Now, write a function that would
change the contents of the array.
Now, write a similar function in Python, and point out the similarities and/or differences.
*/
void change_arr(int *p_a){
  *(p_a + 99) = 50; 
}


void print_arr(int *arr){
    for (int i = 0; i < 6; i++){
        printf("%d\n", arr[i]);
   }
}

void change_char(char *c, char change){
    //always only going to change the first element
    *c = change; 
    //c[99] = change //to change the 100th element 
    //*(c+99) = change
}

/*
Implement a function that performs https://en.wikipedia.org/wiki/Insertion_sort#Algorithm. The
function should take in an array of integers, and modify the array so that it’s sorted in increasing order.
Here is code to print out an array of integers using a for-loop and a while-loop in C.

*/
/*
i ← 1
while i < length(A)
    j ← i
    while j > 0 and A[j-1] > A[j]
        swap A[j] and A[j-1]
        j ← j - 1
    end while
    i ← i + 1
end while
*/
void insert_sort() { //pointer is where the array starts *always pass in a pointer for an array
    int i = 1; 
    int j; // j indexes through the values before it 
    int arr[5] = {7, 3, 2, 6, 5}; 
    int temp; 
    while (i < 5){
        j = i; 
        while (j > 0 && arr[j-1] > arr[j]){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp; 
            j --; 
        }
        i++; 
        }
    print_arr(arr);  
}

/* 5
Write a function that, without using strlen, returns the length of a string given by a pointer to the first
character in a string
What is the runtime complexity of this function? O(n)
*/

void string_len(char *str){
    //if the value at the address is \0 then stop 
    int i = 0; 
    while (*(str + i)!= '\0'){
        i++; 
    }
    printf("string length %d\n", i);
}

/* 6 
Write a function void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2. unsigned long arr2_sz)which takes in two arrays arr1 and arr2 and their sizes, and replaces every appearances of arr2 in arr1
with all 0’s.
For example int a[] = {5, 6, 7, 8, 6, 7};
int b[] = {6, 7};
seq_replace(a, 6, b, 2);
should result in a being {5, 0, 0, 8, 0, 0}
What is the runtime complexity of this function? o(n^2)
*/
void seq_replace(int *arr1, int size1, int *arr2, int size2){
    bool seq = true; 
    int arr2_index =0; 
    int j = 0;
    //assume that the size of arr2 is less than the size of arr1
    for (int i = 0; i <= size1-size2; i++) {
        //resets to true
        seq = true; 
        // while (arr2_index <= size2)
        //     if (arr1[i] == arr2[0]){
                
        //         j++; 
        // }
        for (int j = 0; j < size2; j++) {
            if (arr1[i+j] != arr2[j]) {
                seq = false; 
            }
        }
        if (seq == true){
            printf("%s\n", "true");
            for (int k = 0; k < size2; k++){
                if (arr1[i+k] == arr2[k]) {
                    arr1[i+k] = 0;
                }
            }
        }
    }
    print_arr(arr1);
}
int main(){
    int a = 5; //#2
    char arr[100]; //#3

    //fill the array
    //fill_arr(arr, 100); 
    change_char(arr, 1); //name of the array is a pointer 
    change_a(&a);
    printf("%d\n", a); 

    //#4
    insert_sort();

    //#5
    string_len("absc");

    //#6
    int ar[] = {5, 6, 78, 8, 6, 7};
    int br[] = {6, 7};
    seq_replace(ar, 6, br, 2);

}

