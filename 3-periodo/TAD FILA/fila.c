#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

struct no {
  int num; 
  tNo* prox;
};

struct fila {
    tNo* f;
    tNo* r;
};

// Função para criar uma Fila
tFila *criaFila()
{
    tFila* fila = (tFila*) malloc(sizeof(tFila));//cabeça
  
    fila->f = NULL;
    fila->r = NULL;

    return fila;
}

// Função para emFilar
int enfileirar(tFila *fila, int dado)
{
    tNo* no = (tNo*) malloc(sizeof(tNo));
    
    if(!no)
    {
        return 0;
    }

    no->num = dado;
    no->prox = NULL;
    
    if (filaVazia(fila))
    {
        fila->f = no;
        fila->r = no;
        
        return 1;
    }
    
    fila->r->prox = no;
    fila->r = no;    
    
    return 1;
}
 
// Função para desemFilar
int desenfileirar(tFila *fila)
{
    if(filaVazia(fila))
    {
        return 1;
    }
    
    tNo* aux = (tNo*) malloc(sizeof(tNo));
    
    aux = fila->f;
    fila->f = aux->prox;
    
    free(aux);
    
    return 1;
}

// libera a fila
void liberaFila(tFila *fila)
{
    while(!filaVazia(fila))
    {
        desenfileirar(fila);
    }
    
    free(fila);
}

// Função para exibir os elementos da Fila (só para teste)
void exibeFila(tFila *fila)
{
    tNo* exibe = (tNo*) malloc(sizeof(tNo));
    
    exibe = fila->f;
    
    while (exibe != NULL)
    {
        printf("%d\t", exibe->num);
        exibe = exibe->prox;
    }
}

// Verifica se a Fila está vazia
int filaVazia(tFila *fila)
{
    return fila->f == NULL;
}