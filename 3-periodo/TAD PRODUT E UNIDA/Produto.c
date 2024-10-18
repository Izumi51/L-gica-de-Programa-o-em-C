#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Produto.h"
#include "Unidade.h"
#include "Data.h"

struct p {
    char[] id;
    char[] cod;
    float preco;
    int quantUnidade;
    Unidade* unidade[]; 
};

tProduto* prod_cria(char* id, char* cod, float preco, int quantUnidade)
{
    tProduto* novoProduto = (tProduto*) malloc(sizeof(tProduto));
    
    if (novoProduto == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    } 

    novoProduto->id = (char*)malloc(sizeof(char)*((strlen(id) + 1)));
    novoProduto->cod = (char*)malloc(sizeof(char)*((strlen(cod) + 1)));
    novoProduto->id = strcpy(id);
    novoProduto->cod = strcpy(cod);
    novoProduto->preco = preco;
    novoProduto->quantUnidade = quantUnidade;
    novoProduto->unidade = (Unidade*) malloc(sizeof(Unidade) * quantUnidade);
    if (novoProduto->unidade == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    
    return novoProduto;
}

/* Função libera */

void prod_libera(tProduto* p)
{
    free(p);
}

/* Função exibe */

void prod_exibe(tProduto* p)
{
    printf("Nome: %s/Codigo: %s/Preco: %f/Quantidade: %d unidades", p->id, p->cod, p->preco, p->quantUnidade);
}

/* Função ehSemelhante*/

int prod_ehSemelhante(tProduto* p1, tProduto* p2)
{
    int resposta;
    
    resposta = strcmp(p1->id, p2->id);
    
    if(resposta == 0)
    {
        return 1;
    }
        else
        {
            return 0;
        }
}

/* Função reajuste */

void prod_reajuste(tProduto* p, float percentual)
{
    float novoPreco;
    
    percentual = percentual/100;
    novoPreco = percentual*(p->preco);
    p->preco = novoPreco;
}

/* Função getId*/

char* prod_getId(tProduto* p)
{
    char* id;
    id = (char*)malloc(20);
    sprintf(id, "%f", p->id);
    return id;
}

/* Função getCod*/

char* prod_getCod(tProduto* p)
{
    char* cod;
    cod = (char*)malloc(20);
    sprintf(cod, "%f", p->cod);
    return cod;
}

/* Função getPreco*/

char* prod_getPreco(tProduto* p)
{
    char* preco;
    preco = (char*)malloc(20);
    sprintf(preco, "%s", p->preco);
    return preco;
}

/* Função getQuant*/

char* prod_getQuant(tProduto* p)
{
    char* quant;
    quant = (char*)malloc(20);
    sprintf(quant, "%s", p->quantUnidade);
    return quant;
}

/* Função setId */

void prod_setId(tProduto* p, char* novoId)
{
    p->id = novoId;
}

/* Função setCod */

void prod_setCod(tProduto* p, char* novoCod)
{
    p->cod = novoCod;
}

/* Função setPreco */

void prod_setPreco(tProduto* p, float novoPreco)
{
    p->preco = novoPreco;
}

/* Função setQuant */

void prod_setQuant(tProduto* p, int novaQuant)
{
    p->quant = novaQuant;
}

/* Função getProduto*/

char* prod_getProduto(tProduto* p)
{
    char* prod;
    prod = (char*)malloc(50);
    sprintf(prod, "%s/%s/%f/%d", p->id, p->cod, p->preco, p->quantUnidade);
    return prod;
}

/* Função compara*/

int prod_compara(tProduto* pt1, tProduto* pt2)
{
    if(ehSemelhante(pt1, pt2) == 0)
    {
        if (strcmp(pt1->cod, pt2->cod) == 0)
        {
            if(pt1->preco == pt2->preco)
            {
                return 1;
            }
                else
                {
                  return 0;  
                }
        }
    }
    
    return 0;
}