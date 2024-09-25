#pragma once

#include <stdbool.h>

typedef void* Element;

struct cellule_s {
	Element val;
	struct cellule_s* suiv;
};

typedef struct cellule_s Cellule;

typedef Cellule* Liste;

// return true if l is empty else false
bool isEmpty(Liste l);

// generate a list with a single element v
Liste generate(Element v);

// add v at the beginning of the list
Liste addHead(Element v, Liste l);

extern void displayElement(Element e);

// display all elements of l
void displayList(Liste l);

// free element
extern void freeElement(Element e);

// free all elements of l
void freeList(Liste l);

// return a list with v at the end
Liste addTail(Element v, Liste l);

// return a pointer on the the first element of l with value v or NULL
Liste search(Element v,Liste l);

//compare two elements
extern bool equalsElement(Element e1, Element e2);

// return a list where the first occurence of v has been deleted
Liste removeFirstOccurence(Element v, Liste l);