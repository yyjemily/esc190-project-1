#include "autocomplete.h"
#include <stdbool.h>

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

void read_in_terms(term *terms, int *pnterms, char filename) {
    termterms = (term *)malloc(sizeof(term) (pnterms));

    FILE fp = fopen(filename, "r");

    for (int i = 0; i < pnterms; i++) {
        fgets((terms + i), 200, fp);
    }

    // sorting by lex algo:

    int sorted = 0 // false
    char temp;

    while (sorted == 0) {
        sorted = 1;
        for (int i = 0; i < pnterms - 1; i++) {
            if ((terms + i) > (terms + i + 1)) {
                sorted = 0;
                temp =(terms + i);
                (terms + i) =(terms + i + 1);
                *(terms + i + 1) = temp;
            }
        }
    }

    fclose(fp);
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

void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr) {
    // cry because using qsort is gonna make us cry
    // extract terms that match query string
    // sort by weight -> qsort (# of appearances or by population)
    // extract top matching terms by weight / output things in order by weight
}