#include <linkedList.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
	Liste l, p;

	l = NULL;
	printf("isEmpty(l) = %s\n",isEmpty(l)?"TRUE":"FALSE");

	l = addHead(1,l);
	l = addHead(2,l);
	l = addHead(4,l);
	l = addHead(1,l);
	l = addHead(5,l);
	l = addHead(6,l);
	l = addHead(2,l);
	l = addHead(4,l);
	l = addHead(1,l);

	displayList(l);

	addTail(99,l);
	displayList(l);

	addTail(100,l);
	displayList(l);

	p = search(200,l);
	printf("search(200) : %s\n",isEmpty(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = search(99,l);
	if(isEmpty(p))
		printf("search(99) : [ERREUR] pas trouve \n");
	else {
		printf("search(99) : trouve ");
		displayElement(p->val);
		printf("\n");
	}

	p = cherche_r(200,l);
	printf("cherche_r(200) : %s\n",isEmpty(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_r(99,l);
	if(isEmpty(p))
		printf("cherche_r(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_r(99) : trouve ");
		displayElement(p->val);
		printf("\n");
	}

	printf("removeFirstOccurence(1)   : ");
	l = removeFirstOccurence(1,l);
	displayList(l);

	printf("removeFirstOccurence(1)   : ");
	l = removeFirstOccurence(1,l);
	displayList(l);

	printf("removeFirstOccurence(100) : ");
	l = removeFirstOccurence(100,l);
	displayList(l);

	printf("removeFirstOccurence(4)   : ");
	l = removeFirstOccurence(4,l);
	displayList(l);

	printf("removeFirstOccurence(4)   : ");
	l = removeFirstOccurence(4,l);
	displayList(l);

	printf("removeFirstOccurence(99)  : ");
	l = removeFirstOccurence(99,l);
	displayList(l);

	freeList(l);

	return EXIT_SUCCESS;
}