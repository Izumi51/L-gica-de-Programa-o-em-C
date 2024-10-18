#include "TADLista.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int s = 1;
    int n = 0;
    int max = 10;
    tLista* l1 = cria_lista_vazia(max, s, s);
    tLista* l2 = cria_lista_vazia(max, s, n);
    tLista* l3 = cria_lista_vazia(max, n, s);
    tLista* l4 = cria_lista_vazia(max, n, n);
    int i;
    for (i = 0; i < max; i++)
    {
        lista_inclui(l1, rand()%7);
    }
    lista_percorre(l1);
    
    printf("\n");printf("\n");
    
    for (i = 0; i < max; i++)
    {
        lista_inclui(l2, rand()%7);
    }
    lista_percorre(l2);
    printf("\n");printf("\n");
    for (i = 0; i < max; i++)
    {
        lista_inclui(l3, rand()%7);
    }
    lista_percorre(l3);
    printf("\n");printf("\n");
    for (i = 0; i < max; i++)
    {
        lista_inclui(l4, rand()%7);
    }
    lista_percorre(l4);
    printf("\n");printf("\n");
    return 0;
}