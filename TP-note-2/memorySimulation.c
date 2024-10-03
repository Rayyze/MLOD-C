#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <memorySimulation.h>
#include <string.h>

memoryManager createMemoryManager(int startAdress, int maxSize) {
    memoryManager result;

    result.allocatedList = malloc(sizeof(Cellule));
    Cellule emptyCell;
    Bloc emptyBloc;
    emptyBloc.maxSize = 0;
    emptyBloc.startAddress = -1;
    emptyCell.bloc = emptyBloc;
    emptyCell.suiv = NULL;
    *(result.allocatedList) = emptyCell;

    result.freeList = malloc(sizeof(Cellule));
    Cellule firstCell;
    Bloc firstBloc;
    firstBloc.maxSize = maxSize;
    firstBloc.startAddress = startAdress;
    firstCell.bloc = firstBloc;
    firstCell.suiv = NULL;
    *(result.freeList) = firstCell;

    return result;

}

int myalloc(memoryManager *mm, int size) {
    if (mm == NULL) return -1;
    Cellule *currentCell;
    currentCell = mm->freeList;
    while (currentCell != NULL && currentCell->bloc.maxSize<size) {
        currentCell = currentCell->suiv;
    }
    if (currentCell==NULL || isEmtyBloc(currentCell->bloc)) {
        return -1;
    }
    Bloc newBloc;
    newBloc.maxSize = size;
    newBloc.startAddress = currentCell->bloc.startAddress;
    mm->allocatedList = addHead(newBloc, mm->allocatedList);

    //découpage du bloc existant
    currentCell->bloc.maxSize = currentCell->bloc.maxSize - size;
    if (currentCell->bloc.maxSize == 0) {
        currentCell->bloc.startAddress = -1;
    } else {
        currentCell->bloc.startAddress = currentCell->bloc.startAddress + size;
    }

    return newBloc.startAddress;
}

bool isEmtyBloc(Bloc bloc) {
    return bloc.maxSize == 0 && bloc.startAddress == -1;
}


BlocList addHead(Element b, BlocList l) {
    BlocList new_cell = malloc(sizeof(Cellule));
    new_cell->bloc = b;
    new_cell->suiv = l;

    return new_cell;
}

int myfree(memoryManager *mm, int address) {
    if (mm == NULL) return -1;
    BlocList foundCell = search(address, mm->allocatedList);
    if (foundCell == NULL) return -1;

    Bloc newFreeBloc;
    newFreeBloc.maxSize = foundCell->bloc.maxSize;
    newFreeBloc.startAddress = foundCell->bloc.startAddress;
    mm->freeList = addHead(newFreeBloc, mm->freeList);

    mm->allocatedList = removeFirstOccurence(address, mm->allocatedList);
    return newFreeBloc.startAddress;
}

BlocList search(int adr,BlocList l) {
	if(equalsElement(l->bloc, adr)) {
        return l;
    }
    if (l->suiv==NULL) {
        return l->suiv;
    }
    return search(adr, l->suiv);
}

bool equalsElement(Bloc bloc1,int adr) {
    return bloc1.startAddress == adr;
}

BlocList removeFirstOccurence(int adr, BlocList l) {
    if(l==NULL) return l;
	if (equalsElement(l->bloc, adr)) {
        Cellule * temp_cell = l->suiv;
        free(l);
        return temp_cell;
    }
    l->suiv = removeFirstOccurence(adr, l->suiv);
    return l;
}

void displayList(BlocList l) {
    printf("[");
	while (l != NULL) {
        displayElement(l->bloc);
        l = l->suiv;
    }
    printf("end]\n");
    
}

void displayElement(Bloc b) {
    if (!isEmtyBloc(b)) {
        printf("(addr: %d | size: %d)", b.startAddress, b.maxSize);
        printf("->");
    }
}

void freeMemoryManager(memoryManager mm) {
    freeList(mm.allocatedList);
    freeList(mm.freeList);
}

void freeList(BlocList l) {
	if (l != NULL) {
        freeList(l->suiv);
        free(l);
    }
}

//Pas terminé mais en bonne voie
/*void readFromFile(char fpath[]) {
    FILE *f = fopen(fpath, "r");
    memoryManager mm;

    char lineBuffer[512];
    fgets(lineBuffer, sizeof(lineBuffer), f);

    int mmSize;
    int mmStartAdr;
    char *line_copy = strdup(lineBuffer);
    char *token;
    token = strsep(&line_copy, " ");
    if (token != NULL) 
        mmStartAdr = atoi(token);
    token = strsep(&line_copy, ",");
    if (token != NULL) 
        mmSize = atoi(token);
    mm = createMemoryManager(mmStartAdr, mmSize);
    free(line_copy);
        
    while(fgets(lineBuffer, sizeof(lineBuffer), f)) {
        token = strsep(&line_copy, " ");
        if (token != NULL) 
            mmStartAdr = atoi(token);
        token = strsep(&line_copy, ",");
        if (token != NULL) 
            mmSize = atoi(token);
        free(line_copy);
    }
    freeMemoryManager(mm);
    fclose(f);
}*/