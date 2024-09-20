#include <prixTuring.h>

int main(void) {

}

int numberOfWinners(FILE *f) {
    rewind(f);
    int result = 0;
    while (fgetc(f) != EOF) {
        result++;
    }
    return result;
}

tabPrixTuring readWinners(FILE *f) {
    rewind(f);
    int numberWinners = numberOfWinners(f);
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
        if (caracCourant!=';') {
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
}

int power_of_10(int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= 10;
    }
    return result;
}