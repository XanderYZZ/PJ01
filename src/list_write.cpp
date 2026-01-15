#include "list_read.h"
#include "list_write.h"
#include <stdio.h>
#include <stdlib.h>

void listRelease(LIST *pLIST){
    NODE *curr = pLIST->head;

    while (curr != NULL) {
        NODE *temp = curr;
        curr = curr->next;
        free(temp); 
    }

    pLIST->head = NULL;
    pLIST->tail = NULL;
    pLIST->length = 0;
}

// Inserting at the head.
NODE * listInsert(LIST *pLIST, double key){
    NODE *pNODE = (NODE *) malloc(sizeof(NODE));
    if (!pNODE) { return NULL; }

    pNODE->key = key;
    pNODE->next = pLIST->head;
    pLIST->head = pNODE;

    if (pLIST->tail == NULL) {
        pLIST->tail = pNODE;
    }

    pLIST->length += 1;

    return pNODE;
}

// Inserting at the tail.
NODE * listAppend(LIST *pLIST, double key){
    NODE *pNODE;

    
    return pNODE;
}


NODE * listDelete(LIST *pLIST, double key){
    NODE *pNODE;
    pNODE = NULL;
    fprintf(stderr, "You need to write the function listDelete\n");
    return pNODE;
}

