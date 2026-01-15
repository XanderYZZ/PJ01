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
    NODE *pNODE = (NODE *) malloc(sizeof(NODE));
    if (!pNODE) { return NULL; }

    pNODE->key = key;
    pNODE->next = NULL;         

    if (pLIST->tail != NULL) {
        pLIST->tail->next = pNODE;
    }

    pLIST->tail = pNODE;

    if (pLIST->head == NULL) {
        pLIST->head = pNODE;
    }

    pLIST->length += 1;

    return pNODE;
}

NODE * listDelete(LIST *pLIST, double key){
    NODE *prev = NULL;
    NODE *curr = pLIST->head;
    
    while (curr != NULL) {
        if (curr->key == key) {
            if (curr == pLIST->head) {
                pLIST->head = curr->next;

                if (curr == pLIST->tail) {
                    pLIST->tail = NULL;
                }
            } else {
                prev->next = curr->next;

                if (curr == pLIST->tail) {
                    pLIST->tail = prev;
                }
            }

            pLIST->length -= 1;

            return curr;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return NULL;
}