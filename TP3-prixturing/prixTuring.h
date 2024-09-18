#include <stdio.h>

int numberOfWinners(FILE *f);
void readWinners(FILE *f, prixTuring tab[]);

typedef struct {
    int annee;
    char noms[50];
    char nature[500];
} prixTuring;

typedef enum {
    ANNEE,
    NOMS,
    NATURE
} Mode;