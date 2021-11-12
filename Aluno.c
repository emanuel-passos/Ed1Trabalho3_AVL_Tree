#ifndef Aluno_c
    #define  Aluno_c
        #include"Aluno.h"

        typedef struct _aluno_ {
        char *nome;
        int idade;
        float nota;

        }Aluno;

//---------------------------------------------------//

    void *Aluno_Create(){

        Aluno *p = (Aluno*)malloc(sizeof(Aluno));
        p->nome = (char*)malloc(20*sizeof(char));
                if(p != NULL){
                    if(p->nome != NULL){
                        printf(" Nome = ");
                        fflush(stdin);
                        char nome[20];
                        scanf("%s", &nome);

                        strcpy(p->nome,nome);


                        printf("\n idade = ");
                        fflush(stdin);
                        scanf("%d", &p->idade);

                        printf("\n nota = ");
                        fflush(stdin);
                        scanf("%f", &p->nota);


                    return p;
                }
            }
            return NULL;

    }
    int get_Aluno_idade(Aluno *a){
        if(a != NULL){
            return a->idade;
        }
    }
    char *get_Aluno_nome(Aluno *a){
        if(a != NULL){

            return a->nome;
        }
    }
//-------------------------------------------------------------//

    void show_Aluno(void*elm){
        Aluno *p = (Aluno*)elm;
        printf("--------------------------------------------------\n");
        printf("Nome %s\n Idade %d\n Nota : %f\n", p->nome, p->idade, p->nota);
        printf("---------------------------------------------------\n");
    }

    int comp(Aluno *c, char *nome, int idade, int *temp){

        if(strcmp(c->nome,nome) == 0 && idade == c->idade){
            *temp = 1;

            return TRUE;
        }
        return FALSE;
    }
    int comp_ab(Aluno *c, char *nome, int idade){

        if(strcmp(c->nome,nome) == 0 && idade == c->idade){

            return 0;
        }else if(idade > c->idade){
            return -1;
        }else{
            return 1;
        }

    }
    int comp_ab_insert(Aluno *c,int idade){

        if(idade > c->idade){
            return -1;
        }else{
            return 1;
        }

    }
#endif // Aluno_c


