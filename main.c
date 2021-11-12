#include<stdio.h>
#include<stdlib.h>
#include "Binary_Tree.h"
#include "Aluno.h"


int main(){
    Tnode *t = NULL;
    int flag = 1;

    while(flag){
        system("cls");
        char opt;

        printf(" a: Criar colecao \n b: Inserir tipo \n c: Remover Tipo \n d: Consultar tipo \n e: Listar elementos \n f: Destruir colecao \n g: exit\n");

        fflush(stdin);
        scanf("%c", &opt);

        if(opt == 'a'){
            if(t== NULL){
                t = abCreate(Aluno_Create());
            }
        }else if (opt == 'b'){

            Aluno *temp = Aluno_Create();
            int idade = get_Aluno_idade(temp);
            abInsert(t, temp,idade,  cmp);

        }else if(opt == 'c'){
              char nome[20];
              int idade;
              scanf("%s", &nome);
              scanf("%d", &idade);
              abRemove(t, nome, idade, cmp);
        }else if(opt =='d'){
            char nome[20];
            int idade;
            scanf("%s", &nome);
            scanf("%d", &idade);
            abSearch(t, nome, idade);
        }else if(opt == 'e'){

                Simetrica(t);

        }else if(opt == 'f'){
          t = abDestroy(t);
        }else if(opt== 'g'){
            flag = 0;
        }
        system("PAUSE");

    }

    return 0;
}


