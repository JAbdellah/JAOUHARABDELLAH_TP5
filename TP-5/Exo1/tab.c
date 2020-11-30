#include"tab.h"
#define TAB2SIZE 100
#define TAILLEAJOUT 50
int initTab(int* tab, int size) {
	for (int i = 0; i < size; i++)
	{
		tab[i] = 0;
	}
	if (tab = 0 || size < 0)
	{
		return -1;

	}

};

int afficheTab(int* tab, int size, int nbElts) {
	if (tab == NULL) {
		return -1;
	}
	if (size < 0) {
		return -1;
	}
	if (size < nbElts) {
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; ++i) {
			printf("%u ", tab[i]);
		}
		return 0;
	}
}

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (*nbElts == *size) {
		int* tabnew = (int*)realloc(tab, (TAB2SIZE + TAILLEAJOUT) * sizeof(int)); 
		if (tabnew == NULL) {
			return NULL;
		}
		else { 
			tab = tabnew;
			tab[*nbElts] = element;
			*nbElts = *nbElts + 1;
		}
	}
	else {
		tab[*nbElts] = element;
		*nbElts = *nbElts + 1;
	}
	return tab;
}