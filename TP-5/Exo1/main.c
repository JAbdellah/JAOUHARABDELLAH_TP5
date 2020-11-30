#include"tab.h"
#define TAB2SIZE 100
#define TAILLEAJOUT 50




void main() {
	int Mytab1[10];
	int tabSize = TAB2SIZE;
	int nbElts = 0;
	int* myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));
	if (myTab2 != NULL) {
		initTab(myTab2, tabSize);


	}
	else {
		printf("mémoire insuffisante");
		return(-1);
	}

	for (int j = 0; j < 20; j++)
	{
		myTab2[j] = j + 1;
		nbElts++;
	}
	afficheTab(myTab2, tabSize, nbElts);
	

	free(myTab2);

}
