#include <stdlib.h>
#include <prixTuring.h>

int main(void) {
    char inFilePath[] = "../TP3-prixturing/turingWinners.csv";
    char outFilePath[] = "../TP3-prixturing/out.csv";
    FILE *pFile = fopen(inFilePath,"r");
    tabPrixTuring result = readWinners(pFile);
    fclose(pFile);
    pFile = fopen(outFilePath, "w");
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
    printf("%d", result);
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
    result[index+1] = '\0';
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