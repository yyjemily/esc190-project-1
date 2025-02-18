#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab3_header.h"

//Q1 
// Consider the two functions:

// Show how to try to use those functions in main(). Explain why one function has an effect but the
// other one does not.

void set_int1(int x)
{
    x = 42;
}

void set_int2(int *p_x)
{
    *p_x = 42;
}

// //Q2
// //Consider the following structure.
// //Write a function that takes in a student1 and prints their information. Test the function

// typedef struct student1{
//     char name[200]; // character array
//     char student_number[11];
//     int year;
// } student1;


// Question 3.
// Part (a)
// Write a function that takes in a pointer to student1, and sets name to "Default Student"
// The function signature should be
void set_default_name(student1 *p_s) {
    //start from a pointer and points to the variable name "name" because the pointer stores an array of addresses, -> tells you which variable to access
    strcpy(p_s->name, "Default Student"); 
    printf("%s\n",p_s->name);

    //change the year 
    p_s -> year = 0; //is p_y -> year basically another variable?
    printf("%i\n",p_s -> year);
}
// Part (b)
// Make sure that a function with a signature like
void set_default_name_wrong(student1 s) {
    //s.name = "Default Name";
    s.year = 0;

    
    printf("%i\n", s.year); 
}
// cannot work.
// Now, add setting year to 0 to set_default_name. Can this work with set_default_name_wrong?
// Why? 
//it can't work because the string is a const char *, but it works for the int because int is mutable???? 

//Question 4 ***DO AGAIN ---------------------------------------------------
// Write a function that uses malloc that takes in a pointer to student * and sets the pointer to the address
// of a block of n students students1’s.
// The function signature should be
void create_block1(student1 **p_p_s, int n_students) {
    *p_p_s = (student1 *) malloc(sizeof(student1)*n_students); //student1 is just 1 student 
    printf("%lu\n", sizeof(student1));
}
// In your main function, show how to use function create block1).

//Q5
// Write a function with the name set_name, which can be used to set the name of a student1 to a string.
// If the string is longer than 199 characters, set the name of the input student1 to the first 199 characters
// of the input string. Make sure that name is a valid string.
// (Note: input here is used in the sense of data being sent to a function, not data that was received from
// the input.)
// Use the function set_name to set the name of an element from the block you’ve allocated, and use
// printf to verify that you’ve successfully used set_name
void set_name (student1 *s, char *change_name){
    int i = 0; 

    while (i < 200 && *change_name != '\0'){}
        //when s is a pointer so -> name, when s is just s, do s.name
        s -> name[i] = *change_name;
        i ++; 
        change_name++; //moves through the string 
}

//Q6 
//Write the function destroy_block1 which frees all the memory that was allocated for a block of student1s.
void destroy_block1(student1 **p_p_s){ //pointer to pointer because you are referencing the memory allocation for one of the objects inside student
    free(p_p_s);  
}

//Q7 
// Now, consider the structure
// typedef struct student2{
// char *name;
// char *student_number;
// int year;
// } student2;
// Write void create_block2(student2 **p_p_s, int num_students). Do not allocate the names and
// student numbers yet. Set both name and student_number to 0.

typedef struct student2{
    char *name;
    char *student_number;
    int year;
} student2;

void create_block2(student2 **p_p_s, int num_students){ //when do you need double pointer? -> when you want to modify the base (modify globally)
    //p_p_s -> name doesnt do anything
    //p_p_s is the entire array filled with different students 
    //**p_p_s array of student structure  */ 
    *p_p_s = (student2 *)malloc(sizeof(student2)*num_students); 

    printf("%lu\n", sizeof(student2));
}

//Q8 
// Now, write the function set_name2 which can be used to set the name of a student2 to an input string.
// Allocate enough space using malloc so that the entire string (including the NULL) can be stored.
// Use this function with an element of a block allocated using create_block2. Verify using printf that
// your function worked correctly.
void set_name2 (student2 *s, char *change_name){ //only a specific student
    //one element of a block is just one student and hte block is array of students itself
    //take one student ansd set the name for it 
    //s is just one student therefore use single pointer 

    s->name = (char *)malloc(strlen(change_name)*sizeof(change_name)); 
    strcpy(s->name, change_name); 

    // while (*change_name != '\0'){ INFINITE LOOP? 
    //     //when s is a pointer so -> name, when s is just s, do s.name
    //     *(s -> name) = *change_name; //deferencing the string name
    //     (s -> name)++; 
    //     change_name++; //moves through each character in the string 
    // }
    printf("%s\n", s->name);
    printf("%s\n", s->student_number);
}
//Q9 
// Write a function named destroy_block2 which frees all the memory that’s been allocated for a block of
// student2s, including any blocks of memory assigned to names and student_numbers.
void destroy_block2(student2 **s){
    free(s); 
}
//Q10
// Recall from class that if a structure like student1 s1 is passed into a function, modifying the contents of
// s1.name would not have an effect outside the function, but if a structure like student2 s2 is passed into
// a function, things work differently. Reproduce this behaviour. Now, explain the difference. Show what
// happens when you pass a pointer to a structure instead of the structure itself.
void change_s1(student1 *s, char *change_name){
    //s->name = (char *)malloc(strlen(change_name)*sizeof(change_name)); //can't allocate memory because mememory is arleady allocated 
    strcpy(s->name, change_name); 
    printf("%s\n", s->name); 
}
void change_s1_2(student1 s, char *change_name){
    //makes a copy inside the function
    //content inside name and student number already exists and are copied -> becomes a local copy, if you modify the local copy 
    //since student 2 is defined as a pointer, you can point the the address with free space and even if the local copy inside the function deletes, 
    //the mememory for name is still pointing to a the "heap mememory"
   // s.name = change_name;
}

void change_s2_1(student2 *s, char *change_name){
    s->name = (char *)malloc(strlen(change_name)*sizeof(change_name)); 
    strcpy(s->name, change_name); 

}

void change_s2(student2 s, char *change_name){
    //change name is an array of character (string) denoted using * or []
    
    //. is for if you are working with the structure: student itself
    strcpy(s.name,change_name); //can't do this because tyou havent allocated memory 
    //strings are immutable, therefore use strcpy to modify 
    //s.name contains a memory address -> shouldnt override memory address with change_name when doing s.name = change_name

}
//Q13
// The following code can be used to read in N lines of a text file line-by-line.
// char line[200];
// FILE *fp = fopen(filename, "r");
// for(int i = 0; i < N; i++){
// fgets(line, sizeof(line), fp); //read in at most sizeof(line) characters
// //(including ’\0’) into line.
// }
// fclose(fp);
// Write a function that takes in a filename of a text file, and prints the file’s contents.

void read_file(char filename[], int N){
    char line[200];
    printf("print");
    FILE *fp = fopen(filename, "r");
    for(int i = 0; i < N; i++){
        fgets(line, sizeof(line), fp); //read in at most sizeof(line) characters
        printf("%s", line);
    //(including ’\0’) into line.
    }
    fclose(fp);

}
//Q14
// Write a function that takes in a filename that contains integers, one integer per line, and outputs the
// average of those integers. You can use the library function atoi: https://cplusplus.com/reference/
// cstdlib/atoi/.
// The function fgets returns NULL when it has reached the end of the file, so you can use
// in order to process all the lines in the file.
void read_int_file(char filename[]){
    char line[200];//string;
    int integers;
    int avg;
    int i =0;
    FILE *fp = fopen(filename, "r");
    while(fgets(line, sizeof(line), fp)) {
        integers += atoi(line);
        
        i++;
    }
    printf("%i", integers);
    avg = integers/i; 
    printf("%d", avg);
    
}




int main() {
    //Q1
    int a = 4;
    set_int1(a); //has no effect because not returning anything 

    //Q2
    set_int2(&a); //has effect because you are dereferencing the address and going there to change the value 
    student1 s1 = {"Emily", "12345678910", 1};
    //cant do this with print
    //printf("Name: %s\n", s1.name, "Student num: %s\n", s1.student_number, "Year %i\n", s1.year); 
    printf("Name: %s\nStudent num: %s\nYear: %i\n", s1.name, s1.student_number, s1.year);
    printf("helo");
    //Q3
    set_default_name(&s1); //only point to the array no need to specify the WHICH object in the student you are accessing 
    set_default_name_wrong(s1); //works with year but not with name

    //Q4
    student1 *s_1 = &s1; 
    create_block1(&s_1, 5);

    //Q8 
    student2 s2 = {"Emily", "32894058204", 2};
    set_name2(&s2, "Emily Ye");

    //Q10
    change_s1(&s1, "Ye"); 

    //Q13 
    read_file("/Users/emiliemui/coding/ESC190/Lab32025/test.txt", 3);
    read_int_file("/Users/emiliemui/coding/ESC190/Lab32025/test.txt");


    return 0;
}
