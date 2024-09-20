#include <stdio.h>

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

int numberOfWinners(FILE *f);
tabPrixTuring readWinners(FILE *f);
int anneeCharToInt(char *buffer);
int power_of_10(int exponent);
char *bufferToChar(char *buffer, int index);
void freeTabPrixTuring(tabPrixTuring *cible);
void printWinners(FILE *f, tabPrixTuring *cible);