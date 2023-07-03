#ifndef LISTALIGADA_H
#define LISTALIGADA_H

typedef struct SNode{
    int elemento;
    struct SNode *prox;
}TNode;

int Vazio(TNode *l);

TNode *InsereInicio(TNode *l, int valor);

TNode *InsereFim(TNode *l, int valor);

TNode *RemoveInicio(TNode *l);

TNode *RemoveFim(TNode *l);

TNode *RemoveElemento(TNode *l, int valor);

TNode *InverteLista(TNode *l);

TNode *OrdenaLista(TNode *l);

TNode *InsereOrdenado(TNode *l, int valor);

TNode *MesclaListas(TNode *l1, TNode *l2);

TNode *RemoveDuplos(TNode *l);

int Busca(TNode *l, int valor);

int ContaElementos(TNode *l);

int Imprime(TNode *l);

#endif
