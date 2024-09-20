#include <stdio.h>

int numberOfWinners(FILE *f);
tabPrixTuring readWinners(FILE *f);
int anneeCharToInt(buffer);
int power_of_10(int exponent);
char *bufferToChar(buffer, index);

typedef struct {
    int annee;
    char *noms;
    char *nature;
} prixTuring;

typedef struct {
    prixTuring* tableauWinner;
    int tailleTableau;
} tabPrixTuring;

typedef enum {
    ANNEE,
    NOMS,
    NATURE
} Mode;