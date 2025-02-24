#include "autocomplete.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int comp(const void *a, const void *b) {
    //cast type to term
    term *term_a = (term *)a;
    term *term_b = (term *)b;
    return strcmp(term_a->term, term_b->term);
}

int compweights(const void *a, const void *b) {
    term *term_a = (term *)a;
    term *term_b = (term *)b;
    return term_a->weight - term_b->weight;    
}


int lowest_match(term *terms, int nterms, char *substr) {
    // binary search

    // lowest match of the index in terms of the first term in lexicographic ordering that matches the string substr 
    int low = 0; 
    int high = nterms-1; 

    printf("low %d high %d\n", low, high);
    while(low <= high) {
        int mid = low + (high - low) /2; 
        printf("mid %d\n", mid);
        //compare terms to see if they are equal
        //check if in the middle 
        printf("%s %s\n", terms[mid].term, substr);
        printf("%d comp\n", comp(terms[mid].term, substr));

        
        int val = comp(terms[mid].term, substr);
        // if (comp(terms[mid].term, substr) == 0 ) {
        //     return mid; 
        // }
        if (val > 0) {
            high = mid - 1;
            if (strstr(terms[mid].term, substr) != NULL) {
                high = mid - 1;
            } 
        } else if (val < 0) {
            low = mid + 1; 
        }

    }

    return -1; //term does not exist 
    
}
int highest_match(struct term *terms, int nterms, char *substr) {  
  // binary search
    int low = 0;
    int high = nterms - 1;
    int mid;
    int val;

    while (low <= high) {
        // printf("current vals: low: %d, mid: %d, high %d", low, mid, high);
        mid = low + (high - low) / 2;
        val = strcmp((terms)[mid].term, substr);
        if (val <= 0) {
            low = mid + 1;
        } else if (val > 0) {
            high = mid - 1;
        }

    }
    return high;

    // return -1; // term doesnt exist in terms
}
int main(void)
{
    // struct term *terms; //declare as struct to allocate memory
    // int nterms;
    // read_in_terms(&terms, &nterms, "cities.txt");

    term terms[] = {
        {"Shanghai, China", 14608512},
        {"Buenos Aires, Argentina", 13076300},
        {"Mumbai, India", 12691836},
        {"Mexico City, Distrito Federal, Mexico", 12294193},
        {"Karachi, Pakistan", 11624219},
        {"İstanbul, Turkey", 11174257},
        {"Delhi, India", 10927986},
        {"Manila, Philippines", 10444527},
        {"Moscow, Russia", 10381222},
        {"Dhaka, Bangladesh", 10356500},
        {"Seoul, South Korea", 10349312},
        {"São Paulo, Brazil", 10021295},
        {"Shanxi, China", 14623452},
        {"Lagos, Nigeria", 9000000}
    };

    // Dynamically allocate memory for the terms array
 
    qsort(terms, 13, sizeof(term), comp); 
    for (int i = 0; i< 13; i++) {
        printf("City: %s, Population: %.0f\n", terms[i].term, terms[i].weight);
    }
    printf("%d", lowest_match(terms, 14, "Shan")); 
    //printf("%d", highest_match(terms, 14, "Shan")); 
    
    //lowest_match(terms, nterms, "Tor");
    //highest_match(terms, nterms, "Tor");
    
    struct term *answer;
    int n_answer;
    //autocomplete(&answer, &n_answer, terms, nterms, "Tor");
    //free allocated blocks here -- not required for the project, but good practice
    
    return 0;
}
