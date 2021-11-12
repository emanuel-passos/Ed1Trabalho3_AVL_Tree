
#include "Binary_Tree.h"
#include "Aluno.h"
typedef struct _tree_{
  struct _tree_ *l, *r;
  void *data;

}Tnode;

/*funcao que compara o dado do no da arvore com o no recebido como parametro, orientando se vai para esquerda ou direita*/

int cmp(void *a , void *b){
  if(a > b){
    return -1;
  }else if (a == b){

    return 0;
  }else{

    return 1;
  }

}
/*cria o primeiro no da arvore, a raiz, ja armazenando um dado de entrada nela*/
Tnode *abCreate(void *data){
    Tnode *t = (Tnode*)malloc(sizeof(Tnode));
    if(t != NULL){
        t->l = NULL;
        t->r = NULL;
        t->data = data;
        return t;
    }
}



//Pesquisa na arvore o elemento;
void *abSearch(Tnode *t,char *nome, int idade){
  if(t != NULL){
    int stat = comp_ab(t->data, nome, idade);

    if(stat == 0){
        show_Aluno(t->data);
        return t->data;
    }else if (stat < 0 ){

      return abSearch(t->r ,nome,idade);

    }else {

      return abSearch(t->l,nome, idade);
    }
  }

   return NULL;
}
/*recebe o dado e a idade, a idade serve para utilizar na funcao de comparacao para saber onde o novo no sera armazenado*/
Tnode *abInsert(Tnode *t, void *data,int idade, int(*cmp)(void *, void *)){
  int stat; Tnode *newt;

  /* se o no existe, compara com o no atual para ir para esquerda se o dado a ser inserido for menor e se for maior vai para a direita*/
  if(t != NULL){

    stat = comp_ab_insert(t->data , idade);

    if(stat > 0){

        t->l = abInsert(t->l, data,idade, cmp);


    }else if(stat < 0){

      t->r = abInsert(t->r, data,idade, cmp);


/* se o elemento ja existir na arvore ele nao é inserido*/
    }else{
        return t;

    }

  }else{
/* quando encontrar a folha da arvore o no é alocado e armazenado*/
    newt = (Tnode*)malloc (sizeof(Tnode));
    if(newt != NULL){
      newt->data = data;
      newt->l = NULL;
      newt->r = NULL;

      return newt;
    }
  }

}
/*procura o menor elemento do ramo esquerdo*/
Tnode *abMenor(Tnode *t, int (*cmp)(void*, void*)){
    Tnode* m = NULL, *m2= NULL;
    if(t != NULL){
        m = t;
        m2 = abMenor(t->l, cmp);
        if(m2 != NULL){
            if(get_Aluno_idade(m->data) <= get_Aluno_idade(m2->data)){
                return m;
            }
            return m2;
        }
        return m;
    }
    return NULL;
}
/*remove um elemento da arvore*/
int abRemove(Tnode *t, char *nome, int idade,  int(*cmp)(void *, void*)){
    int stat; Tnode *newt;
/*verifica se o no existe e percorre a arvore*/
  if(t != NULL){

    stat = comp_ab(t->data ,nome, idade);

    if(stat > 0){

        t->l = abRemove(t->l, nome, idade, cmp);


    }else if(stat < 0){

      t->r = abRemove(t->r, nome, idade, cmp);


    }else{
/*no no a ser removido, verifica se ele tem algum filho*/
        if((t->l == NULL) || (t->r == NULL)){
            Tnode * temp = t->l ? t->l : t->r;
            if (temp == NULL){
                /*nao existe filho*/
                temp = t;

                t = NULL;
            }
            else{
                /*existe apenas um filho, pois entrou na condicao sabendo que no minimo exitia um NULL pela primeira condicao*/
                *t = *temp;
            }
            free(temp);

        }
        else
            /*o no a ser removido tem dois filhos e o menor no do filho direito é substituido pelo no a ser removido*/
        {
            Tnode* temp = abMenor(t->r, cmp);
            t->data = temp->data;
        /* com o no a ser removido colocado na posicao do menor a direita, roda-se a funcao de remover novamente, mas dessa vez o no a ser removido cai no caso de nao ter nenhum filho existente*/
            t->r = abRemove(t->r, get_Aluno_nome(temp->data), get_Aluno_idade(temp->data), cmp);
        }
    }

        return t;


    }
}
/*quando tem apenas um filho na arvore, quer dizer que tem apenas o raiz e este deve ser deletado junto com a arvore*/
Tnode *abDestroy(Tnode *t){
    if(t!= NULL){
        if(t->l == NULL && t->r == NULL){
            free(t->data);
            free(t);
            t = NULL;
            return NULL;
        }
    }
    return t;
}
/*mostra a arvore de forma simetrica*/
Simetrica(Tnode *t){


    if(t != NULL){
        Simetrica(t->l);
        show_Aluno(t->data);
        Simetrica(t->r);

    }

}


