#include <linkedList.h>
#include <stdlib.h>
#include <stdio.h>

bool isEmpty(Liste l) {
    return (l == NULL);
}

Liste generate(Element v) {
    Liste result = malloc(sizeof(Cellule));
    result->val = v;
    result->suiv = NULL;
    return result;
}

Liste addHead(Element v, Liste l) {
    Liste new_cell = malloc(sizeof(Cellule));
    new_cell->val = v;
    new_cell->suiv = l;

    return new_cell;
}

void displayList(Liste l) {
    printf("[");
	while (l != NULL) {
        afficheElement(l->val);
        printf("->");
        l = l->suiv;
    }
    printf("end]\n");
    
}

void freeList(Liste l) {

	if (l != NULL) {
        detruireElement(l->val);
        detruire_r(l->suiv);
        free(l);
    }
}

Liste addTail(Element v, Liste l) {
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

Liste search(Element v,Liste l) {
	if(equalsElement(l->val, v)) {
        return l;
    }
    if (l->suiv==NULL) {
        return l->suiv;
    }
    return cherche_r(v, l->suiv);
}

Liste removeFirstOccurence(Element v, Liste l) {
    if(l==NULL) {
        return l;
    }
	if (equalsElement(l->val, v)) {
        Cellule * temp_cell = l->suiv;
        detruireElement(l->val);
        free(l);
        return temp_cell;
    }
    l->suiv = retirePremier_r(v, l->suiv);
    return l;
}