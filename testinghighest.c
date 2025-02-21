#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int main() {
//   struct term *terms;
//   int nterms 5;
  
//   create_te
  
//   terms
  
//   highest_match(terms, nterms, "Tor");
  

//   return 0;
// }

// void create_term(struct term1 **p_p_t1, const char *term, double weight) {
//     *p_p_t1 = (struct term1*) malloc(sizeof(struct term1)); // THIS *p_p_s1
//     strcpy((*p_p_t1)->term, term);
//     (*p_p_t1)->weight = weight;
// }

// void create_terms2_block(struct term2 **p_p_t2, int n_terms) {
//     *p_p_t2 = (struct term2*)malloc(sizeof(struct term2) * n_terms);
//     for(int i = 0; i < n_terms; i++) {
//         (*p_p_t2)[i].name = (char *)malloc(sizeof(char) * 200);
//         ((*p_p_t2)[i])->weight = (double *)malloc(sizeof(double) * 200);
//     }
// }

typedef struct term{
    char term[200]; // assume terms are not longer than 200
    double weight;
} term;

// int comp(const void *a, const void *b, int len_substr) {
//     term *term_a = (term *)a;
//     term *term_b = (term *)b;
//     return strcmp(term_a->term, term_b->term, len_substr);
// }

int highest_match(struct term *terms, int nterms, char *substr) {  
  // binary search
  // binary search
    int low = 0;
    int high = nterms - 1;
    int mid;
    int val;

    int len_substr = strlen(substr);
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

int main() {
    // Test data: sorted lexicographically
    term terms[] = {
        {"Tor", 12020},
        {"Torino", 15000},
        {"Toronto", 20000},
        {"Torrance", 18000},
        {"Torrrrrrrrrrrrrrrr", 16000},
        {"Van", 25000}
    };

    int nterms = sizeof(terms) / sizeof(terms[0]);
    char substr[] = "Tor";

    int highest = highest_match(terms, nterms, substr);

    if (highest != -1) {
        printf("Highest match at index %d: \"%s\"\n", substr, highest, terms[highest].term);
    } else {
        printf("No match found");
    }

    return 0;
}