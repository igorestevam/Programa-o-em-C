/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
	int conteudo;
	struct cel *seg;
} cel;

typedef struct cel* Lista;

Lista* cria_lista() {
	Lista* li = (Lista*) malloc (sizeof(Lista));
	if(li != NULL) {
		*li = NULL;
	}
	return li;
}

//----------------------------------------------------------------

int insere_lista_fim(Lista *lista, int x){
    if(lista == NULL){
        return 0;
    }
    
    cel* aux = (cel*) malloc (sizeof(cel));
    
    if(aux == NULL){
        return 0;
    }
    
    aux->conteudo = x;
    aux->seg = NULL;
    
    if(*lista == NULL){ //se a lista estiver vazia, o primeiro elemento é igual à aux.
        *lista = aux;
    }else{ //caso contrário, ele percorerá a lista até o final para adicionar aux no fim.
        cel *temp;
        temp = *lista;
        while(temp->seg != NULL){ //anda até o fim da lista
            temp = temp->seg;
        }
        temp->seg = aux;
    }
    return 1;
}

//----------------------------------------------------------------

int insere_lista_inicio(Lista *lista, int x){
    if(lista == NULL){
        return 0;
    }
    
    cel* aux = (cel*) malloc (sizeof(cel));
    
    if(aux == NULL){
        return 0;
    }
    
    aux->conteudo = x;
    aux->seg = *lista;
    *lista = aux;
    return 1;
}

//----------------------------------------------------------------

int buscarNaLista(Lista *lista, int x){
    if(lista == NULL){
        return 0;
    }
    
    if(*lista == NULL){
        return 0;
    }
    
    cel *temp;
    temp = *lista;
    while(temp->seg != NULL){ //anda até o fim da lista
        if(temp->conteudo == x){
            return 1;
        }
        temp = temp->seg;
    }
    return 0;
}
//----------------------------------------------------------------
int buscarNaLista2(Lista *lista, int x){
    if(lista == NULL){
        return 0;
    }
    
    cel *temp;
    
    for(temp = *lista; temp!=NULL; temp=temp->seg){
        if(temp->conteudo == x){
            return 1;
        }
    }
    return 0;
}
    
//----------------------------------------------------------------
int contar(Lista *lista, int x){
    if(lista == NULL){
        return 0;
    }
    
    cel *temp;
    int count = 0;
    
    for(temp = *lista; temp!=NULL; temp=temp->seg){
        count++;
    }
    return count;
}
//----------------------------------------------------------------
int remover(Lista *lista, int x){
    if(lista == NULL){
        return 0;
    }
    if(*lista == NULL){
        return 0;
    }
    
    cel *ant;
    cel *temp;
    
    for(temp = *lista; temp!=NULL; temp=temp->seg){
        if(temp->conteudo == x){
            if(temp == *lista){
                *lista = temp->seg;
            }else{
                ant->seg = temp->seg;
            }
            free(temp);
            return 1;
            
        }
        ant = temp;
    }
    return 0;
}


//----------------------------------------------------------------
void liberarLista(Lista *lista){
    if(lista != NULL){
        cel *temp;
        while(*lista != NULL){
            temp = *lista;
            *lista = temp->seg;
            free(temp);
        }
        imprimir_lista(lista);
        free(lista);
    }
}
//----------------------------------------------------------------

void imprimir_lista(Lista* lista){
    if(lista == NULL){
        printf("\nLista não existe\n");
    }else{
        if(*lista == NULL){
            printf("\nLista vazia\n");
        }else{
            cel *temp;
            temp = *lista;
            printf("\nLista: ");
            while(temp != NULL){
                printf(" %d |", temp->conteudo);
                temp = temp->seg;
            }
            printf("\n");
        }
    }
    
    
}

//----------------------------------------------------------------

int main()
{
	printf("Início\n");
	Lista *lst;
	lst = cria_lista();

    insere_lista_fim(lst, 8);
    insere_lista_fim(lst, 37);
    insere_lista_fim(lst, 71);
    insere_lista_fim(lst, 43);
    insere_lista_fim(lst, 25);
     
    imprimir_lista(lst);
    
    //printf("%d\n", remover(lst, 25));
    
    liberarLista(lst);
    
    imprimir_lista(lst);
    
	return 0;
}
