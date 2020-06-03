#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

enum Balance {E,C,D};

typedef struct tree no;

struct tree
{
    int chave;
    enum Balance bal;
    struct tree *esq;
    struct tree *dir;
};

typedef struct fila no_fila;

struct fila
{
           no *registro;
    struct no_fila *prox;
};

void insere(no **raiz, int n, int *h);
void deleta(no **raiz, int n);
int menu(void);
int media(no *raiz, int *med);
void largura (no *raiz);
int contagem (no *raiz);
void pertence (no *raiz, int busca);
int cont_folhas(no *raiz);
int iguais(no *raiz, no *raiz2);
void ordem(no *raiz);
void pre_ordem(no *raiz);
void pos_ordem(no *raiz);
int um_filho(no *raiz);
int dois_filhos(no *raiz);
void menor_valor(no *raiz);
void maior_valor(no *raiz);
int consulta( no* raiz, int n);

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int num, busca, folhas, same, cont_total, filhos;
    int quant = 0;
    int quant2 = 0;
    int arvore = 1;
    int med = 0;
    int result = 0;
    no *raiz = NULL;
    no *raiz2 = NULL;
    no* inicio;
    int h;
    printf("\n");
    while (arvore == 1 || arvore == 2)
    {
        printf("Qual arvore voce deseja acessar?\n\n1 = Arvore 1\n2 = Arvore 2\n\n");
        scanf("%d", &arvore);

        if(arvore != 1 && arvore != 2)
        {
            return(0);
        }
        int choice = -1;

   //menu
    while (choice != 0)
    {
        printf("\n");
        choice = menu();
        switch(choice)
        {
           case 1:
                do{
                    printf("Digite o numero para insercao: ");
                    scanf("%d",&num);
                    h = 0;
                    if(arvore == 2)
                    {
                        insere(&raiz2, num, &h);
                        quant2++;
                        med += num;
                    }
                    else
                    {
                        insere(&raiz, num, &h);
                        quant++;
                        med += num;
                    }
                } while(num<0);

                break;
           case 2:
                printf("Digite o numero para remocao: ");
                scanf("%d",&num);
                if(arvore == 2)
                {
                    deleta(&raiz2, num);
                    quant--;
                    med-=num;
                }
                else
                {
                    deleta(&raiz, num);
                    quant--;
                    med-=num;
                }
                break;
           case 3:
                if(arvore == 2)
                    ordem(raiz2);
                else
                    ordem(raiz);
                break;
            case 4:
                pre_ordem(raiz);
                if(arvore == 2)
                {
                    pre_ordem(raiz2);
                }
                break;
            case 5:
                pos_ordem(raiz);
                if(arvore == 2)
                {
                    pos_ordem(raiz2);
                }
                break;
           case 6:
                if(arvore == 2)
                    largura(raiz2);
                else
                    largura(raiz);
                break;
            case 7:
                if(arvore == 2)
                {
                    cont_total = contagem(raiz2);
                    printf("\nNumero total de nos e de %d\n", cont_total);
                }
                else
                {
                    cont_total = contagem(raiz);
                    printf("\nNumero total de nos e de %d\n", cont_total);
                }
                break;
            case 8:
                if(arvore == 2)
                {
                    folhas = cont_folhas(raiz2);
                    printf("\nNumero de nos folhas e %d\n", folhas);
                }
                else
                {
                    folhas = cont_folhas(raiz);
                    printf("\nNumero de nos folhas e %d\n", folhas);
                }
                break;
            case 9:
                if(arvore == 2)
                {
                    filhos=um_filho(raiz2);
                    printf("Numero de nos com 1 filho %d\n", filhos);
                }
                else
                {
                    filhos=um_filho(raiz);
                    printf("Numero de nos com 1 filho %d\n", filhos);
                }
                break;
            case 10:
                if(arvore == 2)
                {
                    filhos = dois_filhos(raiz2);
                    printf("Numero de nos com 2 filhos %d\n", filhos);
                }
                else
                {
                    filhos = dois_filhos(raiz);
                    printf("Numero de nos com 2 filhos %d\n", filhos);
                }
                break;
            case 11:
                //printf("Altura da arvore: %d", altura(raiz));
                break;
            case 12:
                if(arvore == 2)
                {
                    result=(med/quant2);
                    printf("A média é %d \n", result);
                }
                else
                {
                    result=(med/quant);
                    printf("A média é %d \n", result);
                }
                break;
            case 13:
                if(arvore == 2)
                {
                    menor_valor(raiz2);
                }
                else
                {
                    menor_valor(raiz);
                }
                break;
            case 14:
                if(arvore == 2)
                {
                    maior_valor(raiz2);
                }
                else
                {
                    maior_valor(raiz);
                }
                break;
            case 15:
                same = iguais(raiz, raiz2);
                if(same = 1)
                {
                    printf("As Arvores sao iguais");
                }
                else
                {
                    printf("As Arvores sao diferentes");
                }
                break;
            case 18:
                if(arvore == 2)
                {
                    printf("\nQual valor deseja buscar?\n");
                    scanf("%d", busca);
                    pertence(raiz2, busca);
                }
                else
                {
                    printf("\nQual valor deseja buscar?\n");
                    scanf("%d", &busca);
                    pertence(raiz, busca);
                }
                break;
                default:
                break;
             }
        }
    }
}

int menu(void)
{
    int choice;
    printf("\n\nOPCOES\n\n");
    printf("1 - Inserir\n");
    printf("2 - Remover\n");
    printf("3 - Percorrer em ordem\n");
    printf("4 - Percorrer em pre ordem\n");
    printf("5 - Percorrer em pos ordem\n");
    printf("6 - Percorrer em largura\n");
    printf("7 - Contagem de nos totais \n");
    printf("8 - Contar nos folhas\n");
    printf("9 - Contar nos com 1 filho\n");
    printf("10 - Contar nos com 2 filhos\n");
    printf("11 - Verificar altura\n");
    printf("12 - Media dos valores\n");
    printf("13 - Verificar o menor valor na arvore\n");
    printf("14 - Verificar o maior valor na arvore\n");
    printf("15 - Verificar se as duas arvores sao iguais\n");
    printf("16 - Verificar se as duas arvores sao semelhantes\n");
    printf("17 - Verificar se as duas arvores sao simetricas\n");
    printf("18 - Verificar se valor pertence a alguma ou as duas arvores\n");
    printf("19 - Verificar quais valores pertencem as duas arvores\n");
    printf("20 - Verificar quais valores pertencem a pelo menos uma arvore\n");
    printf("0 - Sair\n\n\n");
    scanf("%d", &choice);
    system("cls");
    return(choice);
}

void insere(no **raiz, int n, int *h)
{
    no *p1 = (no*)malloc(sizeof(no));
    no *p2 = (no*)malloc(sizeof(no));

    if ((*raiz) == NULL)
    {
        (*raiz) = (no*)malloc(sizeof(no));
        *h = 1;
        (*raiz)->chave = n;
        (*raiz)->esq = (*raiz)->dir = NULL;
        (*raiz)->bal = C;
    }
    else if (n < (*raiz)->chave)
    {
        insere (&(*raiz)->esq,n,h);
        if (*h)
        {
            switch ((*raiz)->bal)
            {
                case D:
                    (*raiz)->bal = C;
                    *h = 0;
                    break;
                case C:
                    (*raiz)->bal = E;
                    break;
                case E:
                    p1 = (*raiz)->esq;
                    if ((p1->bal) == E)
                    { // rebalanceamento simples
                        (*raiz)->esq = p1->dir;
                        p1->dir = (*raiz);
                        (*raiz)->bal= C;
                        (*raiz) = p1;
                    }
                    else
                    { //rebalanceamento duplo
                        p2 = p1->dir;
                        p1->dir = p2->esq;
                        p2->esq = p1;
                        (*raiz)->esq = p2->dir;
                        p2->dir = (*raiz);
                        //printf("P1, bal : %d  %d\n", p1->chave, p1->bal);
                        //printf("P2, bal : %d  %d\n", p2->chave, p2->bal);
                        //printf("Raiz, bal : %d  %d\n", (*raiz)->chave, (*raiz)->bal); getchar();
                        if (p2->bal == E)
                            (*raiz)->bal = D;
                        else
                            (*raiz)->bal = C;
                        if (p2->bal == D)
                            p1->bal = E;
                        else p1->bal = C;
                            (*raiz) = p2;
                    }
                    (*raiz)->bal = C;
                    *h=0;
                    break;
            }
        }
    }
    else if (n > (*raiz)->chave)
    {
        insere (&(*raiz)->dir,n,h);
        if (*h)
        {
            switch ((*raiz)->bal)
            {
                case E:
                    (*raiz)->bal = C;
                    *h = 0;
                    break;
                case C:
                    (*raiz)->bal = D;
                    break;
                case D:
                    p1 = (*raiz)->dir;
                    if (p1->bal == D)
                    { // rebalanceamento simples
                        (*raiz)->dir = p1->esq;
                        p1->esq = (*raiz);
                        (*raiz)->bal = C;
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
                    *h = 0;
                    break;
            }
        }
    }
}
/* REMOCAO DE ELEMENTO DA ARVORE */

int mydel(no **x)
{
    if ((*x)->dir != NULL) return(mydel(&(*x)->dir));
    else
    {
        int n = (*x)->chave;
        (*x) = (*x)->esq;
        return(n);
    }
}

void deleta(no **raiz, int n)
{
    if (*raiz != NULL)
    {
        if (!consulta(*raiz, n))
        {
            printf("Elemento nao encontrado");
            return;
        }
        if ((*raiz)->chave == n)
        {
            if ((*raiz)->esq == NULL)
                (*raiz) = (*raiz)->dir;
            else if ((*raiz)->dir == NULL)
                (*raiz) = ((*raiz)->esq);
            else
                (*raiz)->chave = mydel(&(*raiz)->esq);
        }
        else if (n > (*raiz)->chave)
            deleta(&(*raiz)->dir, n);
        else if (n < (*raiz)->chave)
            deleta(&(*raiz)->esq, n);
    }
    else
    {
        printf("Arvore vazia");
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
        {
            (aux) = (aux)->prox;
        }
        aux->prox = (no_fila*) malloc(sizeof(no_fila));
        aux = aux->prox;
        aux->registro = raiz;
        aux->prox = NULL;
    }
}

no_fila *dequeue(no_fila **fila)
{
    if (*fila != NULL) {
        no_fila *aux;
        aux = *fila;
        if (aux->prox == NULL) {
            *fila = NULL;
            return(aux);
        }
        else {
            aux = *fila;
            *fila = (*fila)->prox;
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
        aux = dequeue(&fila);
         printf("%d (%d)", aux->registro->chave, aux->registro->bal);
         if (aux->registro->esq)
             enqueue (aux->registro->esq, &fila);
         if (aux->registro->dir)
             enqueue (aux->registro->dir, &fila);
    }
    printf("\n");
}


/* CONSULTA */

int consulta(no *raiz, int n)
{
    if (raiz == NULL)
        return (0);
    else if (raiz->chave == n)
        return (1);
    else if (n < raiz->chave)
        return(consulta(raiz->esq, n));
    else
        return(consulta(raiz->dir, n));
}

// NUMERO DE NoS

int contagem(no *raiz)
{
    if(raiz == NULL)
    {
        return(0);
    }
    return(1 + contagem(raiz->esq) + contagem(raiz->dir));
}

// SE VALOR ESTA CONTIDO NA ARVORES

void pertence(no *raiz, int busca)
{

    if(raiz->chave == busca)
    {
        printf("Valor Pertence\n");
        return;
    }
    if(busca < raiz->chave)
    {
        return(pertence(raiz->esq, busca));
    }
    return(pertence(raiz->dir, busca));
}

// NuMERO DE FOLHAS

int cont_folhas(no *raiz)
{
    if(raiz == NULL)
    {
        return(0);
    }
    if((raiz->esq == NULL) && (raiz->dir == NULL))
    {
        return(1);
    }
    return(cont_folhas(raiz->esq) + cont_folhas(raiz->dir));
}

// ARVORES IGUAIS

int iguais (no* raiz, no *raiz2)
{
    if((raiz == NULL) && (raiz2 == NULL))
    {
        return(1);
    }
    if((raiz == NULL) || (raiz2 == NULL))
    {
        return(0);
    }
    if(raiz->chave != raiz2->chave)
    {
        return(0);
    }
    return(iguais(raiz->esq, raiz2->esq) && iguais(raiz->dir, raiz2->dir));
}

// PERCURSO EM ORDEM

void ordem(no *raiz)
{
    if(raiz != NULL)
    {
        if (raiz->esq != NULL)
            ordem(raiz->esq);
        printf("%d\n", raiz->chave);
        if (raiz->dir != NULL)
            ordem(raiz->dir);
    }
    else
    {
        return;
    }
}

//PERCURSO EM PRÉ ORDEM

void pre_ordem(no *raiz)
{
    if(raiz != NULL)
    {
        printf("%d\n", raiz->chave);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
    else
    {
       return;
    }
}

//PERCRUSO EM PoS ORDEM

void pos_ordem(no *raiz)
{
    if(raiz != NULL)
    {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d\n", raiz->chave);
    }
    else
    {
        return;
    }
}

//NoS COM 1 FILHO

int um_filho(no *raiz)
{
    if(raiz == NULL)
    {
        return(0);
    }
    if(raiz->esq == NULL)
    {
        return(1 + um_filho(raiz->dir));
    }
    if(raiz->dir == NULL)
    {
        return(1 + um_filho(raiz->esq));
    }
    um_filho(raiz->esq);
    um_filho(raiz->dir);
}

//NoS COM 2 FILHOS

int dois_filhos(no *raiz)
{
    if(raiz == NULL)
    {
        return(0);
    }
    if(raiz->esq == NULL)
    {
        return(dois_filhos(raiz->dir));
    }
    if(raiz->dir == NULL)
    {
        return(dois_filhos(raiz->esq));
    }
    return(1 + dois_filhos(raiz->esq) + dois_filhos(raiz->dir));
}

//MENOR VALOR NA ARVORE

void menor_valor(no *raiz)
{
    int menor = 99999;

    if(raiz == NULL)
        return;
    if(raiz->chave < menor)
    {
        menor = raiz->chave;
        menor_valor(raiz->esq);
    }
    if(raiz->chave > menor)
    {
        menor_valor(raiz->esq);
    }
    if(raiz->esq==NULL)
    {
    printf("O menor valor na arvore e: %d\n", menor);
    }
}

//MAIOR VALOR NA ARVORE

void maior_valor(no *raiz)
{
    int maior = -1;

    if(raiz == NULL)
        return;
    if(raiz->chave > maior)
    {
        maior = raiz->chave;
        maior_valor(raiz->dir);
    }
    if(raiz->dir == NULL)
    {
        printf("O maior valor na arvore e: %d\n", maior);
    }
}
