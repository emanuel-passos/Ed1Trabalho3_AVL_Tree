#ifndef Aluno_h

    #define Aluno_h
    #include<stdlib.h>
    #include<stdio.h>

    #define TRUE 1
    #define FALSE !TRUE
    typedef struct _aluno_ Aluno;

    #ifdef Aluno_c
        void *Aluno_create();
        void show_Aluno(void*elm);
        int comp(Aluno *c, char *nome, int idade, int *temp);
        int get_Aluno_nota(Aluno *a);
        int comp_ab(Aluno *c, char *nome, int idade);
        int comp_ab_insert(Aluno *c,int idade);
        char *get_Aluno_nome(Aluno *a);

    #endif // Aluno_c
#endif // Aluno_h


