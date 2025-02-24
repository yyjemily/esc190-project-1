#include "autocomplete.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// The comparator function should only return the following values:
// Less than zero (<0): If the first argument should be placed before the second argument.
// Zero (0): If both arguments are equal.
// Greater than zero (>0): If the first argument should be placed after the second argument.

int comp(const void *a, const void *b) {
    term *term_a = (term *)a;
    term *term_b = (term *)b;
    return strcmp(term_a->term, term_b->term);
}

void read_in_terms(term **terms, int *pnterms, char *filename) {
    char cur_line[200];
    
    FILE *fp = fopen(filename, "r");

    fgets(cur_line, sizeof(cur_line), fp);

    *pnterms = atoi(cur_line); // converts string to int
    *terms = (term *)malloc(sizeof(term) * (*pnterms));

    int j = 0;

    for (int i = 0; i < *pnterms; i++) {
        j = 0;
        fgets(cur_line, sizeof(cur_line), fp);
        strcpy((*terms + i)->term, cur_line);
        while ((isspace((*terms + i)->term[j]))) { // update: skip leading spaces // old comment: use the isspace function from c library as a helper function here, included #include <ctype.h>
            j++; // increment until you reach a space
        }
        
        char weight[200];
        char term[200];
        int start = j;

        while ((!isspace((*terms + i)->term[j]))) { // increment j until you find a space
            j++;
        }

        int weight_len = j - start;
        // int weight_fin = j - 1; // the place where info about the weight is done
        int term_init = j + 1; // the place where the info about the term itself starts
        // int term_fin = strlen((*terms + i)->term) - 2; // accounts for the character exclusion + null character
        int term_len = strlen((*terms + i)->term) - term_init - 1; // exclude the newline

        // put all the info about weight into the weight property of the struct
        strncpy(weight,(*terms + i)->term+start, weight_len);
        weight[weight_len] = '\0'; // null - terminate the string
        (*terms + i)->weight = (double)atoll(weight); // converts the weight from a string to a type long long int

        // put all the info about the term into the term propety of the struct
        strncpy(term, (*terms + i)->term+term_init, term_len);
        term[term_len] = '\0'; // null - terminate the string
        strcpy((*terms + i)->term, term);
        int len = strlen((*terms + i)->term); // get the length of the term 

        // AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

        // replace all the new lines with a null character
        if ((*terms + i)->term[len - 1] == '\n') {   
            (*terms + i)->term[len - 1] = '\0';
        }
    }

    // sorting by lex algo:

    // int sorted = 0 // false
    // char *temp;
    //passes in a comparing function, programmer decides how it compare 
    qsort(*terms, *pnterms, sizeof(term), comp);
    //assumes the function

    fclose(fp);
}

int lowest_match(term *terms, int nterms, char *substr) {
    // binary search

    // lowest match of the index in terms of the first term in lexicographic ordering that matches the string substr 
    int low = 0; 
    int high = nterms-1; 
    int lowest = -1;
    int val;

    // printf("low %d high %d\n", low, high);
    while(low <= high) {
        int mid = low + (high - low) /2; 
        // printf("mid %d\n", mid);
        //compare terms to see if they are equal
        //check if in the middle 
        // printf("%s %s\n", terms[mid].term, substr);
        // printf("%d comp\n", comp(terms[mid].term, substr));

        // if (comp(terms[mid].term, substr) == 0 ) {
        //     return mid; 
        // }

        val = strncmp(terms[mid].term, substr, strlen(substr));

        if (val == 0) {
            lowest = mid;
            high = mid - 1;
        } else if (val < 0) {
            low = mid + 1; 
        } else {
            high = mid - 1;
        }

    }
    return lowest; //term does not exist 
    
}



int highest_match(struct term *terms, int nterms, char *substr) {  
  // binary search
  // binary search
    int low = 0;
    int high = nterms - 1;
    int mid;
    int val;

    // int len_substr = strlen(substr);
    int highest = -1;

    while (low <= high) {
        // printf("current vals: low: %d, mid: %d, high %d", low, mid, high);
        mid = (low + high) / 2;
        val = strncmp(terms[mid].term, substr, strlen(substr));
        if (val < 0) {
            low = mid + 1;
        } else if (val > 0) {
            high = mid - 1;
        } else {
            highest = mid;
            low = mid + 1;
        }

        // if (comp(terms[low].term, substr) < 0) {
        //     low = mid + 1;
        // } else if (comp(terms[mid].term, substr) == 0) {
        //     return mid;
        // } else {
        //     high = mid - 1;
        // }
    }

    return highest;
}
int compweights(const void *a, const void *b) {
    term *term_a = (term *)a;
    term *term_b = (term *)b;
    if (term_a->weight > term_b->weight) {
        return -1; // higher weights get returned first
    } else if (term_a->weight < term_b->weight) {
        return 1;
    } else {
        return 0;
    }
}


void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr) {
    // cry because using qsort is gonna make us cry
    // extract terms that match query string
    // sort by weight -> qsort (# of appearances or by population)
    // extract top matching terms by weight / output things in order by weight

    int lowest = lowest_match(terms, nterms, substr);
    int highest = highest_match(terms, nterms, substr);

    // check for no matches
    if ((lowest == -1) || (highest == -1) || (lowest > highest)) {
        *n_answer = 0;
        *answer = NULL;
        return;
    }

    *n_answer = highest - lowest + 1;

    *answer = (term *)malloc(sizeof(term) * (*n_answer));

    for (int i = lowest; i <= highest; i++) {
        (*answer)[i - lowest] = terms[i];
    }

    qsort(*answer, *n_answer, sizeof(term), compweights);
    

}