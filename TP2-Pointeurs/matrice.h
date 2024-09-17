#pragma once
#include <stdint.h>

#define SIZE 5

typedef int** Matrice; 

void echangeContenu(int* a, int* b);
void matrix_mult(int64_t matriceResultat[SIZE][SIZE], int64_t matrice1[][SIZE],int64_t matrice2[][SIZE]);
void matrix_print(int64_t matrice[][SIZE]);
Matrice creer(int valeurInitiale, int nbreLignes, int nbre);
void initialiserLigne(int numeroLigne, int valeur, Matrice cible);
Matrice multiplier(Matrice A, Matrice B);