#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int info;
    struct No *esq;
    struct No *dir;
} No;

typedef struct No* ArvBin;

void imprime_NO(No* no, const char *prefixo, int ehUltimo, char lado)
{
    if(no == NULL)
    {
        return;
    }
    printf("%s", prefixo);
    if(ehUltimo)
    {
        printf("└── ");
    }
    else
    {
        printf("├── ");
    }
    if(lado == 'E')
    {
        printf("E: ");
    }
    else if(lado == 'D')
    {
        printf("D: ");
    }
    printf("%d\n", no->info);
    char novoPrefixo[1000];
    snprintf(novoPrefixo,sizeof(novoPrefixo),"%s%s",prefixo,ehUltimo ? "    " : "│   ");
    if(no->esq != NULL)
    {
        imprime_NO(no->esq, novoPrefixo, no->dir == NULL, 'E');
    }
    if(no->dir != NULL)
    {
        imprime_NO(no->dir, novoPrefixo, 1, 'D');
    }
}
/* Função principal de impressão */
void imprime_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL || *raiz == NULL)
    {
        printf("Árvore vazia.\n");
        return;
    }
    printf("%d\n", (*raiz)->info);
    if((*raiz)->esq != NULL)
    {
        imprime_NO((*raiz)->esq, "", (*raiz)->dir == NULL, 'E');
    }
    if((*raiz)->dir != NULL)
    {
        imprime_NO((*raiz)->dir, "", 1, 'D');
    }
}


ArvBin* cria_arvBin()
{
    ArvBin *raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz!=NULL)
    {
        *raiz = NULL;
    }
    return raiz;
}

int inserir_ArvBin(ArvBin *raiz, int valor)
{
    if(raiz == NULL)
    {
        return 0;
    }

    No* no = (No*)malloc(sizeof(No));
    if(no == NULL)
    {
        return 0;
    }

    no->esq = NULL;
    no->dir = NULL;
    no->info = valor;

    if(*raiz == NULL){
        *raiz = no;
        return 1;
    }
    
    No* temp = *raiz;

    while(temp != NULL)
    {
        if(no->info == temp->info)
        {
            free(no);
            return 0;
        }
        if(no->info < temp->info)
        {
            if(temp->esq == NULL)
            {
                temp->esq = no;
                return 1;
            }
            else
            {
                temp = temp->esq;
            }
        }
        else
        {
            if(temp->dir == NULL)
            {
                temp->dir = no; 
                return 1;
            }
            else
            {
                temp = temp->dir;
            }
        }
    }
    return 0;
}

int main()
{
    printf("Árvore Binária de Busca\n");
    ArvBin* arv = cria_arvBin();
    printf("%d\n", inserir_ArvBin(arv, 10));
    printf("%d\n", inserir_ArvBin(arv, 29));
    printf("%d\n", inserir_ArvBin(arv, 6));
    printf("%d\n", inserir_ArvBin(arv, 6));
    printf("%d\n", inserir_ArvBin(arv, 90));
    printf("%d\n", inserir_ArvBin(arv, 67));
    printf("%d\n", inserir_ArvBin(arv, 69));
    printf("%d\n", inserir_ArvBin(arv, 495));
    printf("%d\n", inserir_ArvBin(arv, 8));
    printf("%d\n", inserir_ArvBin(arv, 5));
    printf("\n");
    imprime_ArvBin(arv);
    return 0;
}
