#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct p tProduto;


/* Função cria */

tProduto* prod_cria(char* id, char* cod, float preco, int quantUnidade);

/* Função libera */

void prod_libera(tProduto* p);

/* Função exibe */

void prod_exibe(tProduto* p);

/* Função ehSemelhante*/

int prod_ehSemelhante(tProduto* p1, tProduto* p2)

/* Função reajuste */

void prod_reajuste(tProduto* p, float percentual);

/* Função getId*/

char* prod_getId(tProduto* p);

/* Função getCod*/

char* prod_getCod(tProduto* p);

/* Função getPreco*/

char* prod_getPreco(tProduto* p);

/* Função getQuant*/

char* prod_getQuant(tProduto* p);

/* Função setId */

void prod_setId(tProduto* p);

/* Função setCod */

void prod_setCod(tProduto* p);

/* Função setPreco */

void prod_setPreco(tProduto* p);

/* Função setQuant */

void prod_setQuant(tProduto* p);

/* Função getProduto*/

char* prod_getProduto(tProduto* p);

/* Função compara*/

int prod_compara(tProduto* pt1, tProduto* pt2);