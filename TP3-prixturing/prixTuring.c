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

void readWinners(FILE *f) {
    rewind(f);
    int numberWinners = numberOfWinners(f);
    char caracCourant;
    char anneeBuffer[4]; //peut etre un buffer pour tout
    int index = 0;
    prixTuring tab[numberWinners];
    Mode mode = ANNEE;

    caracCourant = fgetc(f);
    while (caracCourant != EOF) {
        while (caracCourant!=';') {
            switch (mode)
            {
            case ANNEE:
                anneeBuffer[index]=caracCourant;
                break;
            case NOMS: //TODO
                break;
            case NATURE:
                break;
            default:
                break;
            }
        }
        
    }
    
}