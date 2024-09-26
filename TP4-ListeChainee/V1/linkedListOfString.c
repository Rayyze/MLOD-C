#include <linkedList.h>
#include <stdio.h>
#include <stdlib.h>

void displayElement(Element e) {
	printf("%s ",(char *)e);
}

void freeElement(Element e) {}

bool equalsElement(Element e1, Element e2){
	for (int i=0;true; i++) {
        if (*((char *)e1 + i)!=*((char *)e2 + i)) {
            return false;
        } else if (*((char *)e1 + i)=='\0') {
            return true;
        }
    }
}