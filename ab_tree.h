
#ifndef ab_tree_h
    #define ab_tree_h
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    typedef struct ab_tree Tnode;
    typedef struct _root_ Troot;
    #ifdef ab_tree_c
        Tnode *ab_create();
        Tnode *ab_insert(Tnode *t, void *data);
        void ab_simetric(Tnode *t);
        void ab_search(Tnode *t, void *data);
        void ab_delete(Tnode *root, Tnode *t, void *data);
    #endif // ab_tree_c

#endif // ab_tree_h
