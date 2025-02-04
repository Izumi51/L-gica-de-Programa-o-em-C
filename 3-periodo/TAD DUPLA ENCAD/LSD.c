#include "TADduplaEnc.h"
#include <stdio.h>
#include <stdlib.h>

struct no{
    int info;
    tNo* prox;
    tNo* ant;
};

struct lista{
    tNo* inicio;
    int classif;
    int repet;
};

tNo* cria_no(int valor){
    tNo* no = (tNo*) malloc(sizeof(tNo));
    no->info = valor;
    no->prox = NULL;
    no->ant = NULL;
    return no;
}

tLista* cria_lista_vazia(int classif, int repet){
    tLista* l = (tLista*)malloc(sizeof(tLista));
    l->inicio = NULL;
    l->classif = classif;
    l->repet = repet;
    return l;
}

int lista_vazia(const tLista *pl){
    return (pl->inicio == NULL);
}

int lista_repet(const tLista *pl){
    return pl->repet;
}

int lista_classif(const tLista *pl){
    return pl->classif;
}

void lista_percorre(const tLista *pl){
    tNo* noAux = pl->inicio;
    while(noAux != NULL){
        exibe(noAux->info);
        noAux = noAux->prox;
    }
}

int lista_inclui(tLista *pl, int valor) {

    if (!pl->repet) {
        tNo* aux = pl->inicio;
        while (aux != NULL) {
            if (aux->info == valor) return 0; 
            aux = aux->prox;
        }
    }

    tNo* novo = cria_no(valor);

    if (pl->inicio == NULL || !pl->classif) {
        if (pl->inicio != NULL) {
            pl->inicio->ant = novo;
        }
        novo->prox = pl->inicio;
        pl->inicio = novo;
        return 1;
    }

    tNo* atual = pl->inicio;
    tNo* anterior = NULL;

    while (atual != NULL && atual->info < valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        novo->prox = pl->inicio;
        if (pl->inicio != NULL) pl->inicio->ant = novo;
        pl->inicio = novo;
    } else {
        novo->prox = atual;
        novo->ant = anterior;
        anterior->prox = novo;
        if (atual != NULL) atual->ant = novo;
    }

    return 1;
}

int lista_remove(tLista *pl, int valor){
    if (lista_vazia(pl)) 
        return 0;

    tNo* atual = pl->inicio;

    while (atual != NULL && atual->info != valor) {
        atual = atual->prox;
    }

    if (atual == NULL) 
        return 0;

    if (atual->ant != NULL) {
        atual->ant->prox = atual->prox;
    } else {
        pl->inicio = atual->prox;
    }

    if (atual->prox != NULL) {
        atual->prox->ant = atual->ant;
    }

    free(atual);
    return 1;
}

void exibe(int valor) {
    printf("%d\n", valor);
}

void libera_lista(tLista *pl){
    tNo* noAux;
    while(pl->inicio != NULL){
        noAux = pl->inicio;
        pl->inicio = pl->inicio->prox;
        free(noAux);
    }
    free(pl);
}
