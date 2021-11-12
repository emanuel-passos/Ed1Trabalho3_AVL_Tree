
#ifndef ab_tree_c

    #define ab_tree_c
    #include "ab_tree.h"

    /*Tree struct with left and right */

    typedef struct ab_tree {
        struct _ab_tree *l, *r;
        void *data;
    }Tnode;

    /*Create binary tree */

    Tnode *ab_create(void *data){
        Tnode *t = (Tnode*)malloc(sizeof (Tnode));
        if(t != NULL){
            t->l = NULL;
            t->r = NULL;
            t->data = data;
            return t;
        }
        printf("error during root creation\n");
        return NULL;
    }

    /*Tree insert*/
    Tnode *ab_insert(Tnode *t, void *data){

        if(t!= NULL){

            if(data >= t->data){

                t->r = ab_insert(t->r, data);
            }else{
                t->l = ab_insert(t->l, data);
            }


        }else{

            Tnode *newt = (Tnode*)malloc(sizeof(Tnode));
            if(newt != NULL){
                newt->l = NULL;
                newt->r = NULL;
                newt->data = data;
                return newt;
            }
            printf("error during node creation\n");
            return NULL;
        }
    }
    /*ab_search*/
    void ab_search(Tnode *t, void *data){
        int found = 0;
        if(t!= NULL){
            if(data == t->data){
                printf("found %d \n", t->data);
                found = 1;
            }
            if(found != 1){
                ab_search(t->l, data);
                ab_search(t->r, data);
            }
        }
    }
    /*AB delete*/
    void ab_delete(Tnode *root, Tnode *t, void *data){
        int found = 0;

        if(t!= NULL){
            if(data == t->data){
                /*case 1 : leaf node*/
                if(t->l == NULL && t->r == NULL){
                    free(t->data);
                    free(t);
                    return NULL;
                }
                /*case 2:Node to be deleted has one child*/
                if(t->l != NULL && t->r == NULL){
                    Tnode *temp = t->l;
                    free(t->data);
                    free(t);
                    return temp;
                }
                if(t->l == NULL && t->r != NULL){
                    Tnode *temp = t->r;
                    free(t->data);
                    free(t);
                    return temp;
                }
                if(t->l != NULL && t->r != NULL){
                    Tnode *lower = abLower(t->r);

                }
                /*case 3: node to be deleted has two childs*/
                found = 1;
            }
            if(found != 1){
                ab_delete(root, t->l, data);
                ab_delete(root, t->r, data);
            }
        }
    }
    /*get the lower right node*/
    Tnode *abLower(Tnode *t){
    Tnode* m = NULL, *m2= NULL;
    if(t != NULL){
        m = t;
        m2 = abLower(t->l);
        if(m2 != NULL){
            if(m->data <= m2->data){
                return m;
            }
            return m2;
        }
        return m;
    }
    return NULL;
}

    void ab_simetric(Tnode *t){
        if(t!= NULL){
            ab_simetric(t->l);
            printf("%d\n", t->data);

            ab_simetric(t->r);
        }
    }


#endif // ab_tree_c
