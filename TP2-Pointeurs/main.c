#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

typedef enum {
    JANVIER = 1,
    FEVRIER,
    MARS,
    AVRIL,
    MAI,
    JUIN,
    JUILLET,
    AOUT,
    SEPTEMBRE,
    OCTOBRE,
    NOVEMBRE,
    DECEMBRE
} Mois;

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;


void initialiseDate(Date* d);
void afficheDate(Date* d);
Date creerDateParCopie();
Date* newDate();
int nbreJours(Mois mois, int annee);
bool estBissextile(int annee);
bool dateValide(Date date);
unsigned int jourDansAnnee(Date date);
void echangeContenu(int* a, int* b);
void matrix_mult(int64_t matriceResultat[SIZE][SIZE], int64_t matrice1[][SIZE],int64_t matrice2[][SIZE]);
void matrix_print(int64_t matrice[][SIZE]);

int main(void) {
    /*int64_t matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat[SIZE][SIZE];

    matrix_mult(matriceResultat, matrice1, matrice2);
    matrix_print(matriceResultat);*/

    Date d1 = creerDateParCopie();
    afficheDate(&d1);

    Date* d2 = newDate();
    initialiseDate(d2);
    afficheDate(d2);
    //printf(dateValide(*d2));
    //printf(jourDansAnnee(*d2));
    free(d2);

    return EXIT_SUCCESS;
}

void initialiseDate(Date* d) {
    printf("Indiquer le jour : ");
    scanf("%d", &d->jour);
    printf("Indiquer le mois : ");
    scanf("%d", &d->mois);
    printf("Indiquer l'annee : ");
    scanf("%d", &d->annee);
}

void afficheDate(Date* d) {
    printf("La date correspond a : %d/%d/%d\n", d->jour, d->mois, d->annee);
}

Date creerDateParCopie() {
    Date d;
    initialiseDate(&d);
    return d;
}

Date* newDate() {
    Date* pd;
    pd = malloc(sizeof(Date));
    return pd;
}


int nbreJours(Mois mois, int annee) {
    switch (mois)
    {
    case JANVIER:
    case MARS:
    case MAI:
    case JUILLET:
    case AOUT:
    case OCTOBRE:
    case DECEMBRE:
        return 31;
        break;
    case FEVRIER:
        if (estBissextile(annee)) {
            return 29;
        } else {
            return 28;
        }
        break;
    default:
        return 30;
        break;
    }
}

bool estBissextile(int annee) {
    if (annee%100 == 0) {
        return annee%400==0;
    } else {
        return annee%4==0;
    }
}


bool dateValide(Date date) {
    return date.mois <= DECEMBRE && date.jour < nbreJours(date.mois, date.annee);
}

unsigned int jourDansAnnee(Date date) {
    if (estBissextile(date.annee)) {
        return 366;
    } else {
        return 365;
    }
}

void echangeContenu(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void matrix_mult(int64_t matriceResultat[SIZE][SIZE], int64_t matrice1[][SIZE],int64_t matrice2[][SIZE]) {
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            matriceResultat[i][j] = 0;
            for (int k=0; k<SIZE; k++) {
                matriceResultat[i][j] += matrice1[i][k]*matrice2[k][j];
            }
        }
    }
}

void matrix_print(int64_t matrice[][SIZE]) {
    printf("[");
    for (int i=0; i<SIZE; i++) {
        printf("[%ld, ", matrice[i][0]);
        for (int j=1; j<SIZE-1; j++) {
            printf("%ld, ", matrice[i][j]);
        }
        printf("%ld]\n", matrice[SIZE-1][SIZE-1]);
    }
    printf("]");
}
