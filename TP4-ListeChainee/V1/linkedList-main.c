#include <linkedList.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
	Liste l, p;

	l = NULL;
	printf("isEmpty(l) = %s\n",isEmpty(l)?"TRUE":"FALSE");

	l = addHead("hello",l);
	l = addHead("world",l);
	l = addHead("of",l);
	l = addHead("c",l);
	l = addHead("developpment",l);
	l = addHead("hello",l);
	l = addHead("world",l);
	l = addHead("of",l);
	l = addHead("c",l);

	displayList(l);

	addTail("or",l);
	displayList(l);

	addTail("not",l);
	displayList(l);

	p = search("200",l);
	printf("search(\"200\") : %s\n",isEmpty(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = search("or",l);
	if(isEmpty(p))
		printf("search(\"or\") : [ERREUR] pas trouve \n");
	else {
		printf("search(\"or\") : trouve ");
		displayElement(p->val);
		printf("\n");
	}

	printf("removeFirstOccurence(\"hello\")   : ");
	l = removeFirstOccurence("hello",l);
	displayList(l);

	printf("removeFirstOccurence(\"hello\")   : ");
	l = removeFirstOccurence("hello",l);
	displayList(l);

	printf("removeFirstOccurence(\"not\") : ");
	l = removeFirstOccurence("not",l);
	displayList(l);

	printf("removeFirstOccurence(\"c\")   : ");
	l = removeFirstOccurence("c",l);
	displayList(l);

	printf("removeFirstOccurence(\"c\")   : ");
	l = removeFirstOccurence("c",l);
	displayList(l);

	printf("removeFirstOccurence(\"or\")  : ");
	l = removeFirstOccurence("or",l);
	displayList(l);

	freeList(l);

	return EXIT_SUCCESS;
}