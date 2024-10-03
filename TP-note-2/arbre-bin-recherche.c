#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a==NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire result = malloc(sizeof(Noeud));
	initialiser(&(result->filsDroit));
	initialiser(&(result->filsGauche));
	result->val=e;
	return result;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	if (estVide(a)) {
		return creer(e);
	}
	ArbreBinaire currentArbre = a;
	while (currentArbre->val!=e) {
		if (currentArbre->val<e) {
			if (currentArbre->filsDroit==NULL) {
				currentArbre->filsDroit = creer(e);
			} else {
				currentArbre = currentArbre->filsDroit;
			}
		} else if (currentArbre->val>e) {
			if (currentArbre->filsGauche==NULL) {
				currentArbre->filsGauche = creer(e);
			} else {
				currentArbre = currentArbre->filsGauche;
			}
		}
	}
	return a;
}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	if (estVide(a)) return creer(e);
	if (a->val<e) 
		a->filsDroit = insere_r(a->filsDroit, e);
	else 
		a->filsGauche = insere_r(a->filsGauche, e);
	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
		return estVide(a) ? 0 : 1 + nombreDeNoeud(a->filsDroit) + nombreDeNoeud(a->filsGauche);
}

void prettyPrint(ArbreBinaire a, int profondeur){
	for (int i=0; i<profondeur; i++) {
		printf("|--");
	}
	if (estVide(a)) {
		printf("X\n");
		return;
	}
	printf("%d\n",a->val);
	
	prettyPrint(a->filsDroit, profondeur+1);
	prettyPrint(a->filsGauche, profondeur+1);
}

void detruire_r(ArbreBinaire a){
		if (estVide(a)) return;
	detruire_r(a->filsGauche);
	detruire_r(a->filsDroit);
	free(a);
}

