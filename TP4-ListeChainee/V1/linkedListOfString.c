#include <linkedList.h>
#include <stdio.h>
#include <stdlib.h>

void displayElement(char *e) {
	printf("%s ",e);
}

void freeElement(char *e) {
    free(e);
}

bool equalsElement(char *e1, char *e2){
	for (int i=0;true; i++) {
        if (e1[i]!=e2[i]) {
            return false;
        } else if (e1[i]=='\0') {
            return true;
        }
    }
}