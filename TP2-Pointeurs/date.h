#pragma once

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
