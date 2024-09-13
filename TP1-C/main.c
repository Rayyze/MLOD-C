#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool estParfait(int nombre);
void nombreParfaitAvant(void);
typedef unsigned long long TypeEntier;
TypeEntier factorielle(TypeEntier);

int main(void) {
    int nombre;
    scanf("%i", &nombre);
    printf("%llu \n", factorielle(nombre));
    nombreParfaitAvant();
}

void nombreParfaitAvant() {
    int nombre;
    int i = 0;
    scanf("%i", &nombre);
    while (i <= nombre) {
        if (estParfait(i)) {
            printf("%d \n", i);
        }
        i++;
    }
}

bool estParfait(int nombre) {
    int somme = 0;
    for (int i = 1; i<nombre; i++) {
        if (nombre%i==0) {
            somme+=i;
        }
    }
    return somme==nombre;
}


TypeEntier factorielle(TypeEntier nombre) {
    if (nombre == 0) {
        return 1;
    }
    return factorielle(nombre-1)*nombre;
}
