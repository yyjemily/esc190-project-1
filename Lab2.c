#include<stdio.h>
#include<string.h>
#include <ctype.h>

void print_arr(int *arr, int size){
    for (int i = 0; i < size ; i++){
        printf("%d\n", arr[i]);
   }
}
int string_len(const char *str){
    //if the value at the address is \0 then stop 
    int i = 0; 
    while (*(str + i)!= '\0'){
        i++; 
    }
    return i; 
}
// #1
// Write a function that takes in an address of the first element of a block of ints, and sets all the elements at
// even indices to 0. For example, if the input block is {5, 6, 7, 8}, it should be change to {0, 6, 0, 8}.
// The function signature should be

void set_even_to_zero(int *block, int size) {
    //index should be at an even index 
    int i = 0;
    while (*(block + i)!= '\0' && i < size){ //uses pointer arthemtic 
        block[i] = 0; // indexing with i
        i += 2; 
    }
    print_arr(block, size);
}
// #2
// Implement two versions of the string.h function strcat: https://www.programiz.com/c-programming/
// library-function/string.h/strcat .
// In one version, use the index i to access elements of strings.
// In another version, only use pointer arithmetic.
void my_strcar_index(char *destination, const char *source){
    int k = string_len(source);
    //start a count for the second loop 
    int i = 0; 
    //start the first loop at where it ended
    while(source[i] != '\0') {
        destination[k+i] = source[i]; //prints the % sign???? 
        i++;
    }
    printf("%s\n", destination); 
}

void my_strcar_arth(char *destination, const char *source){
    int k = string_len(source);
    //start a count for the second loop 
    int i = 0; 
    //start the first loop at where it ended
    while(*(source + i)!= '\0') {
        * (destination + (k+i)) = *(source + i); //prints the % sign???? 
        i++;
    }
    printf("%s\n", destination); 
}

// Q3 
// Implement a version of strcmp recursively. Name the function my strcmp rec. See the description of
// strcmp here: https://www.programiz.com/c-programming/library-function/string.h/strcmp.
// Suppose your code looks as follows:
// char *s1 = "[...]";
// char *s2 = "[...]";
// Explain the difference between s1 == s2, *s1 == *s2, and strcmp(s1, s2).
int my_strcmp_rec(const char* str1, const char* str2){
    //base case
    if (str1[0] == '\0' && str2[0] == '\0'){
        return 0;
    }
    else if (str1[0] == '\0'){
        //case if str 1 is greater than str 2
        return 1; 
    }
    else if (str2[0]=='\0') {
        return -1; 
    }
    else {
        //dereferencing first element 
        //comparing the location of the string if str1 is closer to the beginning of the alphabet than string 2
        if (*str1 < *str2) {
            return -1; 
        }
        else if (*str1 > *str2) {
            return 1; 
        }
        else{
            return my_strcmp_rec(++str1, ++str2); // ++str1 incrementing then calling the function with the new incremented value
            /// goes to the next character in memeory because memory increments in different byte sizes 
        }

    }
}

// Q5
//The C library function atoi converts a string to an integer. Write your own version of the function, with
// the signature
// int my_atoi(char *str)
// Hints:
// • The function isdigit (defined in <ctype.h>) can be used to tell if a character is a digit
// • You can convert a digit c to an integer value using c-’0’. For example, ’5’-’0’ is 5 since the digits
// ’0’, ’1’, ’2’, ’3’, ’4’, ’5’ appear in sequence in the ASCII table.
int my_atoi(char *str){
    int i = 0; 
    int res = 0; 
    while (str[i] != '\0'){
        if (isdigit(str[i]) == 1) {
            res = res * 10 + (str[i] - '0'); //subtract by '0' if you want to convert str to char from ASCII table because the difference between where the character is in the table and 0 is just an integer
        }
        i ++; 
    }
    return res; 
}

//Binary Search Delux
int main () {
    //q1
    int L[] = {5, 6, 7, 8, 9, 10};
    set_even_to_zero(L, 6); 

    //q2
    char str1[100] = "Hello", str2[] = "World";
    my_strcar_index(str1, str2);
    my_strcar_arth(str1, str2);

    //q3
    char str3[] = "Hello", str4[] = "World"; 
    printf("%i\n", my_strcmp_rec(str3, str4)); 
    printf("%i\n", my_strcmp_rec(str4, str4)); 
    printf("%i\n", my_strcmp_rec(str4, str3)); 

    //Q5
    char str9[] = "1234"; 
    printf("%i\n", my_atoi(str9)); 


    return 0;
}