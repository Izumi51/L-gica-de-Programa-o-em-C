#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct no {
  int num; 
  tNo* prox;
};

struct pilha {
    tNo* topo;
};

// Função para criar uma pilha
tPilha *criaPilha()
{
    tPilha* pL = (tPilha*) malloc(sizeof(tPilha));//cabeça
  
    pL->topo = NULL;

    return pL;
}

// Função para empilhar (push)
int push(tPilha *p, int dado)
{
    tNo* no = (tNo*) malloc(sizeof(tNo));
    
    if(!no)
    {
        return 0;
    }
    
    no->num = dado;
    no->prox = p->topo;
    p->topo = no;
    
    return 1;
}

// Função para desempilhar (pop)
int pop(tPilha *p, int *dado)
{
    if(pilhaVazia(p))
    {
        return 1;
    }
    
    tNo* aux = (tNo*) malloc(sizeof(tNo));
    
    *dado = p->topo->num;
    
    aux = p->topo;
    p->topo = aux->prox;
    
    free(aux);
    
    return 1;
}

// Função para exibir os elementos da pilha (só para teste)
void exibePilha(tPilha *p){
    tNo* exibe = (tNo*) malloc(sizeof(tNo));
    
    exibe = p->topo;
    
    while (exibe != NULL)
    {
        printf("%d\n", exibe->num);
        exibe = exibe->prox;
    }
}

// Verifica se a pilha está vazia
int pilhaVazia(tPilha *p){
    // if (p->topo == NULL){
    //     return 1;
    // }else{
    //     return 0;
    // }
    
    return p->topo == NULL;
}