#include <stdlib.h>
#include <prixTuring.h>

int main(int argc, char *argv[]) {
    int mustSort = 0;
    char *input_file;
    char *output_file;
    input_file = "turingWinners.csv";
    output_file = "out.csv";
    for(int i=1; i<argc; i++) {
        if(!strcmp(argv[i], "-i") && (i + 1 < argc)) {
            input_file = argv[i+1];
        }
        if(!strcmp(argv[i], "-o") && (i + 1 < argc)) {
            output_file = argv[i+1];
        }
        if(!strcmp(argv[i], "-sort")) {
            mustSort = 1;
        }
    }

    char inFilePath[256];
    char outFilePath[256];
    sprintf(inFilePath, "../TP3-prixturing/%s", input_file);
    sprintf(outFilePath, "../TP3-prixturing/%s", output_file);

    printf("../TP3-prixturing/%s", input_file);

    FILE *pFile = fopen(inFilePath,"r");
    tabPrixTuring result = readWinners(pFile);
    fclose(pFile);

    infoAnnee(&result, 2004);

    pFile = fopen(outFilePath, "w");
    if (mustSort) {
        sortTabPrixTuring(&result);
    }
    printWinners(pFile, &result);
    fclose(pFile);
    freeTabPrixTuring(&result);
}

int numberOfWinners(FILE *f) {
    rewind(f);
    int result = 0;
    char currentChar;
    currentChar = fgetc(f);
    while (currentChar != EOF) {
        if(currentChar=='\n') {
            result++;
        }
        currentChar = fgetc(f);
    }
    return result;
}

tabPrixTuring readWinners(FILE *f) {
    int numberWinners = numberOfWinners(f);
    rewind(f);
    char caracCourant;
    char buffer[2048];
    int index = 0;
    int currentWinnerIndex = 0;
    prixTuring currentWinner;
    prixTuring *tab = malloc(sizeof(prixTuring)*numberWinners);
    tabPrixTuring result;
    Mode mode = ANNEE;

    caracCourant = fgetc(f);
    while (caracCourant != EOF) {
        if (caracCourant!=';' && caracCourant!='\n') {
            buffer[index]=caracCourant;
            index++;
        } else {
            switch (mode)
            {
            case ANNEE:
                currentWinner.annee = anneeCharToInt(buffer);
                break;
            case NOMS:
                currentWinner.noms = bufferToChar(buffer, index);
                break;
            case NATURE:
                currentWinner.nature = bufferToChar(buffer, index);
                tab[currentWinnerIndex] = currentWinner;
                currentWinnerIndex++;
                break;
            default:
                break;
            }
            index = 0;
            mode = (mode+1)%3;
        }
        caracCourant = fgetc(f);
    }

    result.tableauWinner = tab;
    result.tailleTableau = numberWinners;

    return result;
}

int anneeCharToInt(char *buffer) {
    int result = 0;
    for (int i = 0; i<4; i++) {
        result+= (buffer[i] - '0')*power_of_10(3-i);
    }
    return result;
}

int power_of_10(int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= 10;
    }
    return result;
}


char *bufferToChar(char *buffer, int index) {
    char *result = malloc(sizeof(char)*(index+1)); //+1 to leave room for \0
    for (int i = 0; i<index; i++) {
        result[i] = buffer[i];
    }
    result[index] = '\0';
    return result;
}

void freeTabPrixTuring(tabPrixTuring *cible) {
    for (int i = 0; i<cible->tailleTableau; i++) {
        free(((cible->tableauWinner)+i)->noms);
        free(((cible->tableauWinner)+i)->nature);
    }
    free(cible->tableauWinner);
}

void printWinners(FILE *f, tabPrixTuring *cible) {
    for (int i = 0; i<cible->tailleTableau; i++) {
        fprintf(f, "%d;%s;%s\n", ((cible->tableauWinner)+i)->annee, ((cible->tableauWinner)+i)->noms, ((cible->tableauWinner)+i)->nature);
    }
}

int comparePrixTuringParAnnee(const void *a, const void *b) {
    prixTuring *winnerA = (prixTuring *) a;
    prixTuring *winnerB = (prixTuring *) b;
    return (winnerA->annee - winnerB->annee);
}

void sortTabPrixTuring(tabPrixTuring *tab) {
    qsort(tab->tableauWinner, tab->tailleTableau, sizeof(prixTuring), comparePrixTuringParAnnee);
}

void infoAnnee(tabPrixTuring *cible, int anneeCible) {
    for (int i = 0; i<cible->tailleTableau; i++) {
        if (((cible->tableauWinner)+i)->annee == anneeCible) {
            printf("L'année %d le(s) gagnant(s) ont été : %s\nNature des travaux: %s\n", ((cible->tableauWinner)+i)->annee, ((cible->tableauWinner)+i)->noms, ((cible->tableauWinner)+i)->nature);
        }
    }
}