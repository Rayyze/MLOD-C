#include <linkedList.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *title;
    char *artist;
    char *album;
    char *genre;
    int disc;
    int track;
    int year;
} Music;

void displayElement(Element e) {
    Music *toBeDisplayed = (Music *)e;
	printf("The song %s by %s of %s in the album %s, disc %d, track %d, published in %d\n",toBeDisplayed->title, toBeDisplayed->artist, toBeDisplayed->genre, toBeDisplayed->album, toBeDisplayed->disc, toBeDisplayed->track, toBeDisplayed->year);
}

void freeElement(Element e) {
    //TODO
}

bool equalsElement(Element elt1, Element elt2){
    Music *e1 = (Music *)elt1;
    Music *e2 = (Music *)elt2;
	return (equalsChars(e1->title, e2->title)*equalsChars(e1->artist, e2->artist)*equalsChars(e1->album, e2->album)*equalsChars(e1->genre, e2->genre)) && e1->disc==e2->disc && e1->track==e2->track && e1->year == e2->year;
}

bool equalsChars(char *e1, char *e2) {
    return strcmp(e1, e2) == 0;
}