#include "autocomplete.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    struct term terms = {"Tooor", 12020};
    int nterms = 10;
    // read_in_terms(&terms, &nterms, "cities.txt");
    // lowest_match(terms, nterms, "Tor");
    struct term *termss = &terms;
    highest_match(termss, nterms, "Tor");
    
    // struct term *answer;
    // int n_answer;
    // autocomplete(&answer, &n_answer, terms, nterms, "Tor");
    //free allocated blocks here -- not required for the project, but good practice
    return 0;
}

// The comparator function should only return the following values:
// Less than zero (<0): If the first argument should be placed before the second argument.
// Zero (0): If both arguments are equal.
// Greater than zero (>0): If the first argument should be placed after the second argument.

int comp(const void *a, const void *b, int len_substr) {
    term *term_a = (term *)a;
    term *term_b = (term *)b;
    return strcmp(term_a->term, term_b->term, len_substr);
}

void read_in_terms(term **terms, int *pnterms, char *filename) {
    *terms = (term *)malloc(sizeof(term) * (*pnterms));

    FILE *fp = fopen(filename, "r");

    for (int i = 0; i < *pnterms; i++) {
        fgets((*terms + i)->term, 200, fp);
    }

    // sorting by lex algo:

    // int sorted = 0 // false
    // char *temp;
    
    qsort(*terms, *pnterms, sizeof(term), comp);

    fclose(fp);
}

int lowest_match(term *terms, int nterms, char *substr) {
    // binary search

    // lowest match of the index in terms of the first term in lexicographic ordering that matches the string substr 
    int low = 0; 
    int high = nterms-1; 

    while(low <= high) {
        int mid = low + (high - low) /2; 
        //compare terms to see if they are equal
        //check if in the middle 
        if (comp(terms[low].term, substr) == 0 ) {
            return mid; 
        }
        if (comp(terms[low].term, substr) < 0) {
            high = mid - 1;
        } else if (comp(terms[low].term, substr) > 0) {
            low = mid + 1; 
        }

    }
    return -1; //term does not exist 
    
}

// FIXEDDD (?)
int highest_match(struct term *terms, int nterms, char *substr) {
    // binary search
    int low = 0;
    int high = nterms - 1;
    int mid; 

    int len_substr = length(substr);

    while (low <= high) {
        // printf("current vals: low: %d, mid: %d, high %d", low, mid, high);
        mid = (low + high) /2; 
        val = (terms)[mid].term, substr, len_substr;
        if (val > 0) {
            high = mid - 1;
        } else if (val <= 0) {
            low = mid + 1;
        }
    }

    return high;
}

int compweights(const void *a, const void *b) {
    term *term_a = (term *)a;
    term *term_b = (term *)b;
    return term_a->weight - term_b->weight;    
}

void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr) {
    // cry because using qsort is gonna make us cry
    // extract terms that match query string
    // sort by weight -> qsort (# of appearances or by population)
    // extract top matching terms by weight / output things in order by weight

    int lowest = lowest_match(terms, nterms, substr);
    int highest = highest_match(terms, nterms, substr);

    int na_answer = highest - lowest + 1;

    *answer = (term *)malloc(sizeof(term) * (*n_answer));

    for (int i = lowest; i <= highest; i++) {
        (*answer)[i - lowest] = terms[i];
    }

    qsort(answer, na_answer, sizeof(term), compweights);
    

}