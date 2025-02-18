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