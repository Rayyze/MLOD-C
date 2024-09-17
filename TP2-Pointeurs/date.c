#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include <date.h>

int main(void) {

    Date d1 = creerDateParCopie();
    afficheDate(&d1);

    Date* d2 = newDate();
    initialiseDate(d2);
    afficheDate(d2);
    printf("Date valide ? %d\n", dateValide(*d2));
    printf("nombre de jours dans le mois : %d\n", nbreJours(d2->mois, d2->annee));
    printf("il y a %d jours dans cette annee", jourDansAnnee(*d2));
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
        return 31;
        break;
    case MARS:
        return 31;
        break;
    case MAI:
        return 31;
        break;
    case JUILLET:
        return 31;
        break;
    case AOUT:
        return 31;
        break;
    case OCTOBRE:
        return 31;
        break;
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
    return date.mois <= DECEMBRE && date.jour <= nbreJours(date.mois, date.annee);
}

unsigned int jourDansAnnee(Date date) {
    if (estBissextile(date.annee)) {
        return 366;
    } else {
        return 365;
    }
}
