
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE !1

#ifndef _Binary_Tree_H
#define _Binary_Tree_H

typedef struct _tree_ Tnode;

int cmp(void *a , void *b);

Tnode *abCreate(void *data);
void *abSearch(Tnode *t,char *nome, int idade);
Tnode *abInsert(Tnode *t, void *data,int nota, int(*cmp)(void *, void *));
Tnode *abMenor(Tnode *t, int (*cmp)(void*, void*))
;int abRemove(Tnode *t, char *nome, int idade,  int(*cmp)(void *, void*));
void Simetrica(Tnode *t);
Tnode* abDestroy(Tnode *t);
#endif
