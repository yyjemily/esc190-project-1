#include "autocomplete.h"
#include <stdbool.h>
#include <stdio.h>


int main(void)
{
    struct term *terms;
    int nterms;
    read_in_terms(&terms, &nterms, "cities.txt");
    lowest_match(terms, nterms, "Tor");
    highest_match(terms, nterms, "Tor");
    
    struct term *answer;
    int n_answer;
    autocomplete(&answer, &n_answer, terms, nterms, "Tor");
    //free allocated blocks here -- not required for the project, but good practice
    return 0;
}

// The comparator function should only return the following values:
// Less than zero (<0): If the first argument should be placed before the second argument.
// Zero (0): If both arguments are equal.
// Greater than zero (>0): If the first argument should be placed after the second argument.

int comp(term *a, term *b) {
    return strcmp(a->term, b->term);
}

void read_in_terms(term **terms, int *pnterms, char *filename) {
    term *terms = (term *)malloc(sizeof(term) * (pnterms));

    FILE *fp = fopen(filename, "r");

    for (int i = 0; i < pnterms; i++) {
        fgets(*(terms + i), 200, fp);
    }

    // sorting by lex algo:

    // int sorted = 0 // false
    // char *temp;
    
    qsort(*terms, *pnterms, sizeof(term), comp);

    // while (sorted == 0) {
    //     sorted = 1;
    //     for (int i = 0; i < pnterms - 1; i++) {
    //         if (*(terms + i) > *(terms + i + 1)) {
    //             sorted = 0;
    //             // sorting algo -> use q sort + comparator function
    //             qsort(*terms, *pnterms, sizeof(term), comp);
    //         }
    //     }
    // }

    fclose(fp);

    // sort 

    // The function reads in all the terms from filename,
    // and places them in the block pointed to by *terms.
    // The terms should be sorted in lexicographic order

    // fgets(myString, 200, fptr);

    // term t1 = {term, weight};
    // term *p_t1 = &t1;
    // term terms[500];
    // term *terms_block = (term *)malloc(sizeof(term)*500)

    // recall
        // typedef struct term{
        //     char term[200]; // assume terms are not longer than 200
        //     double weight;
        // } term;

    // read in entire file of terms
    // term *terms = (term *)malloc(sizeof(term) * (pnterms));
    // for(int i = 0; i < pnterms; i++) {
    //     terms[i].name = (char *)malloc(2000 * sizeof(term));
    // }

    // read in terms from file based on lab exercises

    // to sort alphabetically, "sorted in c"? qsort...? inspired by internet
}

int lowest_match(term *terms, int nterms, char *substr) {
    // binary search

    // lowest match of the index in terms of the first term in lexicographic ordering that matches the string substr 
    // while((str[i] >= '0' && str[i] <= '9') || str[i] == '.' ){
    //check if the first 
    int left = 0; 
    int right = nterms-1; 
    int mid = (left + right)/2;

    int i = 0; //indexs through substr 

    do {
        mid = (left + right)/2;
        bool term_match = true; 
        //if first letter matches 
        if (terms[mid].term == substr[i]){
            //while substr not at null and the
            while((substr[i] != '/0')){
                if ((terms[mid].term) + 1 == substr[i]){
                                        
                }
                i ++;
            }

        }

    }while(left <= right);

    
    while((substr[i] != '/0')){ 


    }

    
    
    
}

int highest_match(struct term *terms, int nterms, char *substr) {
    // binary search
}

int compweights(term *a, term *b) {
    return a->weight - b->weight;    
}

void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr) {
    // cry because using qsort is gonna make us cry
    // extract terms that match query string
    // sort by weight -> qsort (# of appearances or by population)
    // extract top matching terms by weight / output things in order by weight

    int lowest = lowest_match(terms, nterms, substr);
    int highest = highest_match(terms, nterms, substr);

    int n_answer = highest - lowest + 1;

    term *answer = (term *)malloc(sizeof(term) * n_answer);

    for (int i = lowest; i <= highest; i++) {
        answer[i - lowest] = terms[i];
    }

    qsort(answer, n_answer, sizeof(term), comp);
}