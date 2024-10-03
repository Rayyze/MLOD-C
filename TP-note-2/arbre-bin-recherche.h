#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int Element;

struct noeud_s {
	Element val;
	struct noeud_s* filsGauche;
	struct noeud_s* filsDroit;
};

typedef struct noeud_s Noeud;
typedef Noeud* ArbreBinaire;

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a);

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a);

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e);

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e);

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e);

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a);

void prettyPrint(ArbreBinaire a, int profondeur);

void detruire_r(ArbreBinaire a);

