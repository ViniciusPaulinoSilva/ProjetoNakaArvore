#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

enum Balance {E,C,D};

typedef struct tree no;

struct tree
{
    int chave;
    enum Balance bal;
    struct no *esq;
    struct no *dir;
};

typedef struct fila no_fila;

struct fila
{
    struct no *registro;
    struct no_fila *prox;
};

void insere(no **raiz, int n, int *h);
void deleta(no **raiz, int n);
int Menu(void);
void media(no *raiz, int *med);
void largura (no *raiz);
int contagem (no *raiz);
void pertence (no *raiz, int busca);
int cont_folhas(no *raiz);
int iguais(no *raiz, no *raiz2);

int main ()
{
    int choice, num, arvore, busca, folhas, same, med, cont_total;
    no *raiz = NULL;
    no *raiz2 = NULL;
    no* inicio;
    int h;
    printf("\n");
    printf("Qual árvore você deseja acessar? \n\n 1 = Árvore 1 \n 2 = Árvore 2");
    scanf("%d", &arvore);



   //MENU
    do
    {
        printf("\n");
        choice=Menu();
        switch (choice)
        {
           case 1:
                printf("Digite o numero para insercao:");
                scanf("%d",&num);
                h=0;
                insere(&raiz, num,&h);
                if(arvore == 2)
                {
                    insere(&raiz2, num, &h);
                }
                break;
           case 2:
                printf("Digite o numero para remocao:");
                scanf("%d",&num);
                deleta(&raiz, num);
                if(arvore == 2)
                {
                    deleta(&raiz2, num);
                }
                break;
           case 3:
                printf("Percurso preordem : ");
                pre_ordem(raiz);
                if(arvore == 2)
                {
                    pre_ordem(raiz2);
                }
                break;
           case 4:
                printf("Percurso em largura : ");
                if (raiz) largura(raiz);
                if(arvore == 2)
                {
                    if (raiz2) largura(raiz2);
                }
                else printf(" Arvore vazia!");
                break;
           case 5:
                printf("Digite o numero para consulta:");
                scanf("%d",&num);
                if (consulta(raiz, num)==1) printf("Numero encontrado\n");
                else printf("Numero NAO encontrado\n");
                if(arvore == 2)
                {
                if (consulta(raiz2, num)==1) printf("Numero encontrado\n");
                else printf("Numero NAO encontrado\n");
                }
                break;
            case 10:
                media(raiz, &med);
                if(arvore==2)
                {
                    media(raiz2, &med);
                }
                printf("\n A média é %d \n", med);
                break;
            case 11:
                cont_total = contagem(raiz);
                printf("\n Número total de nós é de %d \n", cont_total);
                if(arvore==2)
                {
                    cont_total = contagem(raiz2);
                    printf("\n Número total de nós é de %d \n", cont_total);
                }
                break;
            case 12:
                printf("\nQual valor deseja buscar?\n");
                scanf("%d", busca);
                pertence(raiz, busca);
                if(arvore ==2)
                {
                    printf("\nQual valor deseja buscar?\n");
                    scanf("%d", busca);
                    pertence(raiz2, busca);
                }
                break;
            case 13:
                folhas = cont_folhas(raiz);
                printf("\n Número de nós folhas é %d \n", folhas);
                if(arvore=2)
                {
                    folhas = cont_folhas(raiz2);
                    printf("\n Número de nós folhas é %d \n", folhas);
                }
                break;
            case 14:
                same = iguais(raiz, raiz2);
                if(same=1)
                {
                    printf("As Árvores são iguais");
                }
                else
                {
                    printf("As Árvores são diferentes");
                }
                break;
            }
                } while (choice != 0);

          return 0;
}

int Menu(void)
{
    int choice;
    printf("\n\n OPCOES \n\n");
    printf("1- Inserir\n");
    printf("2- Remover\n");
    printf("3- Percorrer em ordem\n");
    printf("4- Percorrer em largura\n");
    printf("5- Consulta\n");
    printf("6- Similares\n");
    printf("9- TESTE\n");
    printf("10- Média\n");
    printf("11- Contagem de Nós totais \n");
    printf("12- Verificar se valor pertence a árvore\n");
    printf("13- Contar nós folhas\n");
    printf("14- Verificar se as duas árvores são iguais\n");
    printf("0- Sair\n");
    scanf("%d", &choice);
    return(choice);
}

void insere(no **raiz, int n, int *h)
{
    no *p1 = (no*)malloc(sizeof(no));
    no *p2 = (no*)malloc(sizeof(no));

        if ((*raiz) == NULL)
        {
            (*raiz) = (no*) malloc(sizeof(no));
            *h=1;
            (*raiz) -> chave = n;
            (*raiz) -> esq = (*raiz) -> dir = NULL;
            (*raiz) -> bal=C;
        }
        else
            if (n < (*raiz)->chave)
            {
                insere (&(*raiz)->esq,n,h);
                if (*h)
                {
                    switch ((*raiz)->bal)
                    {
                        case D:
                        (*raiz)->bal = C;
                        *h=0;
                        break;

                        case C:
                        (*raiz)->bal = E;
                        break;

                        case E:
                        p1= (*raiz) -> esq;
                        if ((p1->bal) == E)
                        { // rebalanceamento simples
                            (*raiz) -> esq = p1->dir;
                            p1->dir = (*raiz);
                            (*raiz)->bal= C;
                            (*raiz) = p1;
                        }
                        else
                        { //rebalanceamento duplo
                            p2 = p1->dir;
                            p1->dir = p2->esq;
                            p2->esq = p1;
                            (*raiz)->esq=p2->dir;
                            p2->dir=(*raiz);
                            //printf("P1, bal : %d  %d\n", p1->chave, p1->bal);
                            //printf("P2, bal : %d  %d\n", p2->chave, p2->bal);
                            //printf("Raiz, bal : %d  %d\n", (*raiz)->chave, (*raiz)->bal); getchar();
                            if (p2->bal==E) (*raiz)->bal = D;
                            else (*raiz)->bal = C;
                            if (p2->bal==D) p1->bal = E;
                            else p1->bal = C;
                            (*raiz) = p2;
                        }
                        (*raiz)->bal = C;
                        *h=0;
                        break;
                    }
                }
            }
            else
            if (n > (*raiz)->chave)
            {
                insere (&(*raiz)->dir,n,h);
                if (*h)
                {
                    switch ((*raiz)->bal)
                    {
                        case E:
                        (*raiz)->bal = C;
                        *h=0;
                        break;

                        case C:
                        (*raiz)->bal = D;
                        break;

                        case D:
                        p1= (*raiz) -> dir;
                        if (p1->bal == D)
                        { // rebalanceamento simples
                            (*raiz) -> dir = p1->esq;
                            p1->esq = (*raiz);
                            (*raiz)->bal= C;
                            (*raiz) = p1;
                        }
                        else
                        { //rebalanceamento duplo
                            p2 = p1->esq;
                            p1->esq = p2->dir;
                            p2->dir = p1;
                            (*raiz)->dir=p2->esq;
                            p2->esq=(*raiz);
                            if (p2->bal==D) (*raiz)->bal = E;
                            else (*raiz)->bal = C;
                            if (p2->bal==E) p1->bal = D;
                            else p1->bal = C;
                            (*raiz) = p2;
                        }
                        (*raiz)->bal = C;
                        *h=0;
                        break;
                    }
                }
            }
}
/* REMOCAO DE ELEMENTO DA ARVORE */

int mydel(no **x)
   {
        if ((*x)->dir != NULL) return(mydel (&(*x)->dir));
        else
        {
            int n=(*x)->chave;
            (*x)=(*x)->esq;
            return(n);
        }
   }

void deleta(no **raiz, int n)
{
    if (*raiz != NULL)
    {
        if ((*raiz)->chave == n)
        {
            if ((*raiz)->esq==NULL) (*raiz)=(*raiz)->dir;
            else if ((*raiz)->dir==NULL) (*raiz)=((*raiz)->esq);
            else (*raiz)->chave= mydel(&(*raiz)->esq);
        }
        else if (n > (*raiz)->chave) deleta((*raiz)->dir, n);
        else if (n < (*raiz)->chave) deleta((*raiz)->esq, n);
    }
}

/* FILA */

   void enqueue(no *raiz, no_fila **fila)
   {
        if (*fila==NULL){
                        *fila=(no_fila*) malloc(sizeof(no_fila));
                        (*fila)->registro = raiz;
                        (*fila)->prox = NULL;
                        } else {
                               no_fila *aux;
                               aux = *fila;
                               while ((aux)->prox != NULL)
                                     (aux) = (aux)->prox;
                               aux->prox = (no_fila*) malloc(sizeof(no_fila));
                               aux = aux->prox;
                               aux->registro = raiz;
                               aux->prox = NULL;
                               }
   }
   no_fila *dequeue(no_fila **fila)
   {
           if (*fila!=NULL) {
                 no_fila *aux;
                 aux = *fila;
                 if (aux->prox==NULL) {
                                      *fila=NULL;
                                      return(aux);
                                      }
                                      else {
                                           aux=*fila;
                                           *fila=(*fila)->prox;
                                           return(aux);
                                           }
                 }
   }


/* PERCURSO EM LARGURA */

void largura (no *raiz)
{
     no_fila *fila = NULL;
     no_fila *aux = NULL;

     enqueue (raiz, &fila);
     while (fila) {
           aux=dequeue(&fila);
           printf("%d ( %d )  ", aux->registro->chave, aux->registro->bal);
           if (aux->registro->esq) enqueue (aux->registro->esq, &fila);
           if (aux->registro->dir) enqueue (aux->registro->dir, &fila);
           }
     printf("\n");
}


/* CONSULTA */

int consulta( no* raiz, int n)
{
    if (raiz==NULL) return (0);
    else if (raiz->chave == n) return (1);
    else if (n< raiz->chave) return(consulta (raiz->esq,n));
    else return(consulta (raiz->dir,n));
}

/* MEDIA */

void media(no *raiz, int *med)
{
    if(raiz == NULL)
    {
        printf(" \n\nÁrvore Vazia! \n");
    }
    else if(raiz->dir==NULL)
    {
        *med += raiz->chave;
        media(raiz->esq,*med);
    }
    else if(raiz->esq==NULL)
    {
        *med+= raiz->chave;
        media(raiz->dir,*med);
    }
    *med += raiz->chave;
    return(media(raiz->dir,*med) + media(raiz->esq,*med));
}

int contagem (no *raiz)
{
    if(raiz==NULL)
    {
        return (0);
    }
    return(1 + contagem(raiz->esq) + contagem(raiz->dir));
}

void pertence(no *raiz, int busca)
{
    if(raiz==NULL)
    {
        printf("Valor não encontrado \n");
        return;
    }
    if(raiz->chave == busca)
    {
        printf("Valor Pertence \n");
    }
    if(busca < raiz->chave)
    {
        return(pertence(raiz->esq, busca));
    }
    return(pertence(raiz->dir, busca));
}

int cont_folhas(no *raiz)
{
    if(raiz==NULL)
    {
        return(0);
    }
    if((raiz->esq==NULL) && (raiz->dir==NULL))
    {
        return(1);
    }
    return(cont_folhas(raiz->esq) + cont_folhas(raiz->dir));
}

int iguais (no* raiz, no *raiz2)
{
    if((raiz==NULL) && (raiz2==NULL))
    {
        return (1);
    }
    if((raiz==NULL) || (raiz2==NULL))
    {
        return (0);
    }
    if(raiz->chave != raiz2->chave)
    {
        return(0);
    }
    return(iguais(raiz->esq, raiz2->esq) && iguais(raiz->dir, raiz2->dir));
}
