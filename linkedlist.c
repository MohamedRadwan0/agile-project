
#include<stdlib.h>
#include "linkedList.h"


void creatList (List *pl){

    pl->top = NULL;
    pl->size=0;
}
int listEmpty(List *pl){
    return (!pl->size);
}
int listFull(List *pl){

    return 0;
}
int listSize (List *pl){

    return pl->size;
}
void destroyList(List *pl){

    listNode *pn ;
    while(pl->top){
        pn=pl->top->next;
        free(pl->top);
        pl->top=pn;
    }
    pl->size=0;
}
void insertList (int p,ListEntry e,List *pl){

    int i;
    listNode *pn,*pc;
    pn =(listNode *)malloc(sizeof(listNode));
    pn->entry= e;
    pn->next = NULL ; //in case last element
    if (p==0){
        pn->next=pl->top;
        pl->top=pn;
    }
    else{
        pc=pl->top;
            for (i=0;i<p-1;i++)
                pc=pc->next;
        pn->next=pc->next;
        pc->next=pn;
    }
    pl->size++;
}
void deletList (int p,ListEntry *pe,List *pl){
    int i;
    listNode *pn,*pc;
    if (p==0){
        *pe= pl->top->entry;
        pn=pl->top->next;
        free(pl->top);
        pl->top=pn;
    }
    else{
        pc=pl->top;
        for (i=0;i<p-1;i++)
            pc=pc->next;
        *pe=pc->next->entry;
        pn=pc->next->next;
        free(pc->next);
        pc->next=pn;
    }
    pl->size--;
}
void traverseList (List *pl ,void (*pf)(ListEntry)){

    listNode *pn =pl->top;
    while (pn){
        (*pf)(pn->entry);
        pn = pn->next;
    }
}
void retrieveList(int p,ListEntry *pe,List *pl){

    int i;
    listNode *pn;
    pn=pl->top;
    for (i=0;i<p;i++)
        pn=pn->next;
    *pe =pn->entry;
}
void replaceList(int p,ListEntry e,List *pl){

    int i;
    listNode *pn;
    pn=pl->top;
    for (i=0;i<p;i++)
        pn=pn->next;
   pn->entry= e;
}
/*
void joinList(List *pl1, List *pl2){
    listNode *pn = pl2->top;
    while(pn->next){
        pn = pn->next;
    }
    pn->next =pl1->top;
}
*/
listNode *search_acc(int id,List *pl){
    listNode *pn =pl->top;
    while (pn){
            if (pn->entry.accountid==id){

                return pn;
            }
        pn = pn->next;
    }
}
