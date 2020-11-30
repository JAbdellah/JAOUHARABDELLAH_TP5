#include"tab2.h"
#define TAILLEINITIALE 100
TABLEAU newArray() {
    TABLEAU tab;
    tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));
    tab.eltsCount = 0;
    tab.size = TAILLEINITIALE;
    if (tab.elt != NULL) {
        for (int i = 0; i < TAILLEINITIALE; ++i) {
            tab.elt[i] = 0;
        }
        return tab;
    }
    else {
        tab.elt = NULL;
        return tab;
    }
}
int incrementArraySize(TABLEAU* tab, int incrementValue) {
    if ((*tab).elt == NULL || ((*tab).size + incrementValue) <= 0) {        
        return -1;
    }

    int* save;
    save = (int)realloc((*tab).elt, ((*tab).size + incrementValue) * sizeof(int));       

    if (save == NULL) {                                                                   
                                                                            
        return -1;
    }
    (*tab).elt = save;
    for (int i = (*tab).size; i < (*tab).size + incrementValue; i++) {                      
        (*tab).elt[i] = 0;
    }
    (*tab).size += incrementValue;                          
    return (*tab).size;
}
int setElement(TABLEAU* tab, int pos, int element) {
    if (pos - 1 < tab->size) {

        (*tab).elt[pos - 1] = element;
        return pos;
    }
    else {
        if (incrementArraySize(tab, pos - tab->size) != -1) {
            (*tab).elt[pos - 1] = element;
            return pos;
        }
        else
        {
            return 0;
        }
    }
}
int displayElements(TABLEAU* tab, int startPos, int endPos) {
    for (int i = startPos - 1; i < endPos; i++)
    {
        printf("%u ", (*tab).elt[i]);
    }
}
int deleteElements(TABLEAU* tab, int startPos, int endPos) {
    int temp = 0;
    if (startPos<1 || endPos<1 || startPos>(*tab).size || endPos>(*tab).size) {       
        return -1;
    }
    if (startPos > endPos) {
        temp = startPos;
        startPos = endPos;                                                             
        endPos = temp;
    }
    if (startPos == endPos) {                                                        
        if (startPos == (*tab).size) {
            incrementArraySize(tab, -1);   
            return (*tab).size;
        }
        for (int i = 0; i < (*tab).size - startPos; ++i) {
            (*tab).elt[startPos + i - 1] = (*tab).elt[startPos + i];   
        }
        if (incrementArraySize(tab, -1) == -1) {
            return -1;
        }
        return (*tab).size;
    }
    for (int c = 0; c < (endPos - startPos) + 1; ++c) {               
        for (int i = 0; i < (*tab).size - startPos; ++i) {
            (*tab).elt[startPos + i - 1] = (*tab).elt[startPos + i];;
        }
        incrementArraySize(tab, -1);
    }
    return (*tab).size;
};