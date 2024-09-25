#include <liste-chainee.h>
#include <stdlib.h>
#include <stdio.h>

bool estVide(Liste l) {
    return (l == NULL);
}

Liste creer(Element v) {
    Liste result = malloc(sizeof(Cellule));
    result->val = v;
    result->suiv = NULL;
    return result;
}

Liste ajoutTete(Element v, Liste l) {
    Liste new_cell = malloc(sizeof(Cellule));
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
    printf("[");
	while (l != NULL) {
        afficheElement(l->val);
        printf("->");
        l = l->suiv;
    }
    printf("end]\n");
    
}

// version recursive
void afficheListe_r(Liste l) {

    printf("[");
	if (l != NULL) {
        afficheElement(l->val);
        printf("->");
        afficheListe_r(l->suiv);
    } else {
        printf("end]\n");
    }
}

void detruireElement(Element e) {}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
    Cellule *temp_cell;
	while (l != NULL) {
        detruireElement(l->val);
        temp_cell = l;
        l = l->suiv;
        free(temp_cell);
    }
}

// version récursive
void detruire_r(Liste l) {

	if (l != NULL) {
        detruireElement(l->val);
        detruire_r(l->suiv);
        free(l);
    }
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative

Liste ajoutFin_i(Element v, Liste l) {
    Cellule *current_cell = l;
    while(current_cell->suiv != NULL) {
        current_cell = current_cell->suiv;
    }

    Cellule *new_cell = malloc(sizeof(Cellule));
    new_cell->val = v;
    new_cell->suiv = NULL;
    current_cell->suiv = new_cell;

    return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
    if (l->suiv == NULL) {
        Cellule * new_cell = malloc(sizeof(Cellule));
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
    Cellule *current_cell = l;
    while(current_cell->suiv != NULL) {
        if (current_cell->val==v) {
            return current_cell;
        }
        current_cell = current_cell->suiv;
    }
    return current_cell->suiv;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(l->val==v) {
        return l;
    }
    if (l->suiv==NULL) {
        return l->suiv;
    }
    return cherche_r(v, l->suiv);
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
    if(l==NULL) {
        return l;
    }

    if (l->val==v) {
        Cellule *temp_cell;
        detruireElement(l->val);
        temp_cell=l->suiv;
        free(l);
        return temp_cell;
    }

    Cellule *previous_cell = l;
    Cellule *current_cell = l;
    while(current_cell != NULL) {
        if (current_cell->val==v) {
            previous_cell->suiv = current_cell->suiv;
            detruireElement(current_cell->val);
            free(current_cell);
            return l;
        }
        previous_cell = current_cell;
        current_cell = current_cell->suiv;
    }
    return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
    if(l==NULL) {
        return l;
    }
	if (l->val==v) {
        Cellule * temp_cell = l->suiv;
        detruireElement(l->val);
        free(l);
        return temp_cell;
    }
    l->suiv = retirePremier_r(v, l->suiv);
    return l;
}


void afficheEnvers_r(Liste l) {
	NULL;
}