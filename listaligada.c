#include <stdio.h>
#include <stdlib.h>
#include "listaligada.h"

int Vazio(TNode *l){
    return (l == NULL)? 1 : 0;
}

TNode *InsereInicio(TNode *l, int valor){
    TNode *aux;
    aux = malloc(sizeof(TNode));
    aux->elemento = valor;
    aux->prox = l;
    l = aux;

    return l;
}

TNode *InsereFim(TNode *l, int valor){
    if(l == NULL)
        return l = InsereInicio(l, valor);

    TNode *aux, *p;
    aux = malloc(sizeof(TNode));
    aux->elemento = valor;
    aux->prox = NULL;

    p = l;
    while(p->prox != NULL)
        p = p->prox;

    p->prox = aux;
    return l;
}

TNode *RemoveInicio(TNode *l){
    if(l == NULL){
        printf("\n\n   LISTA VAZIA\n\n");
        system("pause");

        return l;
    }

    TNode *aux = l;
    l = l->prox;
    free(aux);

    printf("\n\n   ITEM REMOVIDO\n\n");
    system("pause");
    return l;
}

TNode *RemoveFim(TNode *l){
    if(l == NULL){
        printf("\n\n   LISTA VAZIA\n\n");
        system("pause");

        return l;
    }else if(l->prox == NULL)
        return l = RemoveInicio(l);

    TNode *aux = l;

    while(aux->prox->prox != NULL) //Procura pelo PENÚLTIMO elemento
        aux = aux->prox;

    free(aux->prox);
    aux->prox = NULL;

    printf("\n\n   ITEM REMOVIDO\n\n");
    system("pause");
    return l;
}

TNode *RemoveElemento(TNode *l, int valor){
    if(l == NULL){
        printf("\n\n   LISTA VAZIA\n\n");
        system("pause");
        return l;
    }
    //Apenas Um Elemento OU Elemento Buscado ao Início
    if(l->elemento == valor || (l->elemento == valor && l->prox == NULL))
        return l = RemoveInicio(l);

    TNode *aux = l;
    while(aux->prox != NULL){ //Varre Lista
        if(aux->prox->elemento == valor){ //Elemento Encontrado no Nó à Frente
            TNode *p = aux->prox; //Ponteiro Auxiliar
            aux->prox = aux->prox->prox; //Próximo Nó Aponta Dois Nós à Frente
            free(p);

            printf("\n\n   %d REMOVIDO\n\n", valor);
            system("pause");
            return l;
        }
        aux = aux->prox;
    }

    printf("\n\n   ELEMENTO NAO ENCONTRADO...\n\n");
    system("pause");
    return l;
}

TNode *InverteLista(TNode *l){
    if(Vazio(l)){
        printf("\n\n   LISTA VAZIA\n\n");
        system("pause");
        return l;
    }
    TNode *l2 = NULL;
    TNode *aux = l;
    while(aux != NULL){
        l2 = InsereInicio(l2, aux->elemento);
        aux = aux->prox;

        l = RemoveInicio(l);
    }

    return l2;
}

TNode *OrdenaLista(TNode *l){
    if(Vazio(l)){
        printf("\n\n   LISTA VAZIA\n\n");
        system("pause");
        return l;
    }
    TNode *l2 = NULL; //Inicia Lista Auxiliar
    TNode *aux = l;

    while(l != NULL){ //Enquanto Lista Original Não Estiver Vazia
        int maior = 0; //Não Comporta Números Negativos
        aux = l;
        while(aux != NULL){ //Procura Pelo Maior Elemento
            if(aux->elemento > maior) maior = aux->elemento;
            aux = aux->prox;
        }

        l2 = InsereInicio(l2, maior);
        l = RemoveElemento(l, maior);
    }

    printf("\n\n   LISTA ORDENADA\n\n");
    system("pause");
    return l2;
}

TNode *InsereOrdenado(TNode *l, int valor){
    if(Vazio(l)) return InsereInicio(l, valor); //Se Vazio - Insere No Início

    TNode *aux, *p;
    p = malloc(sizeof(TNode));
    p->elemento = valor;
    p->prox = NULL;

    aux = l;

    if(aux->elemento >= valor) return InsereInicio(l, valor); //Se Primeiro Elem >= Valor
    if(aux->prox == NULL) return InsereFim(l, valor); // Se Apenas UM Elemento
    while(aux->prox->elemento < valor){
        if(aux->prox->prox == NULL) return InsereFim(l, valor); //Último Elemento > Valor - Insere No Fim
        aux = aux->prox;
    }
    p->prox = aux->prox; //Insere na Prox Posição
    aux->prox = p;

    return l;
}

TNode *MesclaListas(TNode *l1, TNode *l2){
    if(Vazio(l1) || Vazio(l2)){
        printf("\n\n   LISTA VAZIA\n\n");
        system("pause");
        return;
    }

    TNode *aux = l1;
    while(aux->prox != NULL)
        aux = aux->prox;
    aux->prox = l2;
    l1 = OrdenaLista(l1);

    return l1;
}

TNode *RemoveDuplos(TNode *l){
    if(Vazio(l)){
        printf("\n\n   LISTA VAZIA\n\n");
        system("pause");
        return;
    }
    TNode *l2 = NULL; //Inicia Lista Auxiliar
    TNode *aux = l;

    while(aux != NULL){
        l2 = InsereFim(l2, aux->elemento); //Carrega Elementos de l1 para l2
        aux = aux->prox;
    }
    l2 = OrdenaLista(l2); //Ordena l2
    aux = l2;
    while(aux->prox != NULL){
        if(aux->elemento == aux->prox->elemento) //Se Dois Elementos Iguais em Sequência
            l = RemoveElemento(l, aux->elemento);
        aux = aux->prox;
    }

    printf("\n\n   DUPLOS REMOVIDOS\n\n");
    system("pause");
    return l;
}

int Busca(TNode *l, int valor){
    if(l == NULL){
        printf("\n\n   LISTA VAZIA\n\n");
        system("pause");
        return -1;
    }

    TNode *aux = l;
    int i = 0;
    while(aux != NULL){
        if(aux->elemento == valor)
            return i;
        aux = aux->prox;
        i++;
    }

    return -1;
}

int ContaElementos(TNode *l){
    if(Vazio(l)){
        printf("\n\n   LISTA VAZIA\n\n");
        system("pause");
        return -1;
    }

    TNode *aux = l;
    int cont = 0;
    while(aux != NULL){
        aux = aux->prox;
        cont++;
    }

    return cont;
}

int Imprime(TNode *l){
    if(l == NULL){
        printf("\n\n   LISTA VAZIA\n\n");
        system("pause");
        return 1;
    }

    TNode *aux = l;
    while(aux->prox != NULL){
        printf("%d   ", aux->elemento);
        aux = aux->prox;
    }
    printf("%d", aux->elemento);

    printf("\n\n");
    system("pause");
}
