#pragma once

#include <stdbool.h>

typedef struct {
    int startAddress;
    int maxSize;
} Bloc;

typedef Bloc Element;

typedef struct Cellule{
	Element bloc;
	struct Cellule* suiv;
} Cellule;

typedef Cellule* BlocList;

typedef struct {
    BlocList allocatedList;
    BlocList freeList;
} memoryManager;

memoryManager createMemoryManager(int startAdress, int maxSize);

int myalloc(memoryManager *mm, int size);

bool isEmtyBloc(Bloc bloc);

BlocList addHead(Element b, BlocList l);

int myfree(memoryManager *mm, int address);

BlocList search(int adr,BlocList l);

bool equalsElement(Bloc bloc1,int adr);

BlocList removeFirstOccurence(int adr, BlocList l);

void displayList(BlocList l);

void displayElement(Bloc b);

void freeMemoryManager(memoryManager mm);

void freeList(BlocList l);

void readFromFile(char fpath[]);