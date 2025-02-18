#include <stdio.h>
#include <math.h> 

//Question 1
/*
int main(){
FILE *fptr;

fptr = fopen("a.txt", "r");

//fclose(fptr);
return 0;
}
*/

//Question 2 
// The function atof from stdlib.h converts an input string to a double, and the function atoi converts
// an input string to an int.
// Here is a sample implementation of atoi:
// In C, without using atof or any of the scanf family of functions, write a program that reads a text
// file that lists several (not necessarily 3) constants formatted similarly to the following:
// PI = 3.14
// G = 0.0000000000667
// g = 9.8
// and outputs the sum of all the constants in the file. For example, the output in this example would be
// (3.14+0.0000000000667+9.8) 12.9400000000667.
// The following will be useful:
// https://stackoverflow.com/questions/16839658/printf-width-specifier-to-maintain-precision-of-fCreate a text file to test your program and then test it.

//converts a string to a float 
int my_atof(const char *str)
    {
    int i = 0;
    int sign = 1;

    //if negative 
    if(str[i] == '-'){
        sign = -1;
        i++;
    }

    double result = 0;
    int decimal_count = 0; 

    
    while((str[i] >= '0' && str[i] <= '9') || str[i] == '.' ){

        if (str[i] == '.') {
        //counts the location of the decimal 
            decimal_count = i + 1; 
        }
        //multiplying by 10 moves through the digit columns 

        else {
            result = result * 10 + (str[i] - '0'); //str[i] - '0' converts the string at index i to an integer
        }
        printf("here4 %f\n", result);
        
        i++; 
    }
    result = result/(pow(10, decimal_count)); 
    return result * sign;
}

//Question 3 
/*
In class, we used the following C code:

Suppose that in Python, we store a student with the name "ab" and the age 20 as ["ab", 20].
Explain why each of the C functions above does not have an equivalent in Python (without using
ctypes).
Write a Python function that changes the name of a student to a new name that’s passed to the
function.
Now, write a C function that works the same way as the Python function you wrote.
For both the C function and the Python function, write out the memory diagrams
*/

typedef struct student1{
    char name[3];
    int age;
} student1;

void change_name1_wrong(student1 s)
{
    s.name[0] = 'b';
}
void change_name1_right_a(student1 *p_s)
    {
    p_s->name[0] = 'b';
    }
void change_name1_right_b(student1 *p_s)
{
    strcpy(p_s->name, "b");
}

/*Main*/
int main (){
    printf("%d\n", my_atof("3.14"));
}