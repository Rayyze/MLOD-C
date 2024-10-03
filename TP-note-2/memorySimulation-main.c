#include <memorySimulation.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){

	memoryManager m = createMemoryManager(0, 100);
	myalloc(&m, 8);
	myalloc(&m, 15);
	myalloc(&m, 5);

	displayList(m.allocatedList);
	printf("\n");
	displayList(m.freeList);
	printf("\n");

	myfree(&m, 8);

	displayList(m.allocatedList);
	printf("\n");
	displayList(m.freeList);
	printf("\n");

	freeMemoryManager(m);

	//char *fpath = "memorySimulation-small.txt";
	//readFromFile(fpath);

	return EXIT_SUCCESS;
}