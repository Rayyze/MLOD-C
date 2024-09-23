#include <liste-chainee.h>
#include <stdlib.h>
#include <stdio.h>

bool estVide(Liste l) {
    return (l == NULL);
}

Liste creer(Element v) {
    Liste result;
    result->val = v;
    result->suiv = NULL;
    return result;
}

Liste ajoutTete(Element v, Liste l) {
    Liste new_cell;
    new_cell->val = v;
    new_cell->suiv = l;

    return new_cell;
}


void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
    Cellule * current_cell = l;
    printf("[");
	while (current_cell->suiv != NULL) {
        afficheElement(current_cell->val);
        printf("->");
    }
    printf("end]");
    
}

// version recursive
void afficheListe_r(Liste l) {

    afficheElement(l->val);
    printf("->");
	if (l->suiv == NULL) {
        printf("end]");
    } else {
        afficheListe_r(l->suiv);
    }
}

void detruireElement(Element e) {}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
    Cellule * current_cell = l;
	while (current_cell->suiv != NULL) {
        detruireElement(current_cell->val);
    }
}

// version récursive
void detruire_r(Liste l) {

    detruireElement(l->val);
	if (l->suiv != NULL) {
        detruire_r(l->suiv);
    }
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative

Liste ajoutFin_i(Element v, Liste l) {
    Cellule *current_cell = l;
    while(current_cell->suiv != NULL) {
        current_cell = current_cell->suiv;
    }

    Cellule *new_cell;
    new_cell->val = v;
    new_cell->suiv = NULL;
    current_cell->suiv = new_cell;

    return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
    if (l->suiv == NULL) {
        Cellule * new_cell;
        new_cell->val = v;
        new_cell->suiv = NULL;
        l->suiv = new_cell;
    } else {
        ajoutFin_r(v, l->suiv);
    }

	return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	return TODO;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	return TODO;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	return TODO;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	return TODO;
}


void afficheEnvers_r(Liste l) {
	TODO;
}