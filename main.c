#include <stdio.h>
#include "autocomplete.h"

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

void read_in_terms(term **terms, int *pnterms, char *filename) {
    term *terms = (term *)malloc(sizeof(term) * (pnterms));

    FILE *fp = fopen(filename, "r");

    for (int i = 0; i < pnterms; i++) {
        fgets(*(terms + i), 200, fp);
    }

    // sorting by lex algo:

    int sorted = 0 // false
    char *temp;

    while (sorted == 0) {
        sorted = 1;
        for (int i = 0; i < pnterms - 1; i++) {
            if (*(terms + i) > *(terms + i + 1)) {
                sorted = 0;
                temp = *(terms + i);
                *(terms + i) = *(terms + i + 1);
                *(terms + i + 1) = temp;
            }
        }
    }

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
}

int highest_match(struct term *terms, int nterms, char *substr) {
    // binary search
}

void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr) {
    // cry because using qsort is gonna make us cry
    // extract terms that match query string
    // sort by weight -> qsort (# of appearances or by population)
    // extract top matching terms by weight / output things in order by weight
}