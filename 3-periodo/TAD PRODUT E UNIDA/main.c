/*
    Construa um programa que, usando o TAD Produto, monte um vetor de ponteiros para
    produtos ( pode ser com dados exemplos) e mostre:
    
    -- Para cada produto, quais as unidades vencem em uma determinada data
    perguntada ao usuário (data alvo)
    -- Para os produtos que tenham pelo menos uma unidade que vencem em 3 dias
    da data alvo aplicar 25% de desconto.
    
    ALUNOS:
        JOÃO PAULO IZUMI DE OLIVEIRA
        FILIPE RODRIGUES ALBUQUERQUE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Produto.h"
#include "Unidade.h"

void mostrar_-

int main(void)
{
    tData* data_alvo;
    int dia, mes, ano;
    int quantProd;
    tProduto* produtos*;
    int i;
    
    printf("Digite a data alvo (dd mm yyyy): ");
    scanf("%d %d %d", dia, mes, ano);

    data_alvo = dta_cria(int dia, int mes, int ano);

    // Criando o vetor de produtos
    
    printf("Digite a quantidade de produtos: ");
    scanf("%d", quantProd);
    
    produtos = (tProduto*)malloc(sizeof(tProduto) * quantProd);
    if (produtos == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }

    // Exemplo de criação de produtos (id, código, preço, quantidade de unidades)
    produtos[0] = prod_cria("P001", "ABC123", 10.0, 5);
    produtos[1] = prod_cria("P002", "DEF456", 20.0, 3);

    // Função que verifica produtos com unidades vencendo na data e aplica desconto
    mostrar_produtos_vencendo_na_data(produtos, 2, data_alvo);

    // Liberar a memória dos produtos
    for (i = 0; i < quantProd; i++) 
    {
        prod_libera(produtos[i]);
    }
}

// Função para aplicar o desconto se o produto tem unidade vencendo em até 3 dias
void aplicar_desconto_se_vencendo_em_3_dias(tProduto *produto, Data data_alvo) 
{
    int i;
    int dia, mes, ano;
    
    dta_acessa(data_alvo, &dia, &mes, &ano);
    
    for (i = 0; i < produto->quantUnidade; i++) 
    {
        // Checa se a unidade vence em até 3 dias da data alvo
        if (uni_idade (produto->unidade[i], dia, mes, ano) <= 3) 
        {
            printf("Aplicando desconto de 25%, ao produto %s\n", prod_getId(produto));
            prod_reajuste(produto, 25);  // Aplica 25% de desconto
            break;
        }
    }
}

// Função para verificar e mostrar produtos com unidades vencendo na data alvo
void mostrar_produtos_vencendo_na_data(tProduto *produtos[], int qtd_produtos, Data data_alvo) 
{
    int i;
    int j;
    int dia, mes, ano;
    
    dta_acessa(data_alvo, &dia, &mes, &ano);
    
    for (i = 0; i < qtd_produtos; i++) 
    {
        printf("Verificando produto %s...\n", prod_getId(produtos[i]));
        
        for (j = 0; j < produtos[i]->quantUnidade; j++) 
        {
            if (uni_idade (produto->unidade[i], dia, mes, ano) == 0) 
            {
                printf("Produto %s tem unidades que vencem na data fornecida.\n", prod_getId(produtos[i]));
                // Aplica desconto se alguma unidade está vencendo em até 3 dias
                aplicar_desconto_se_vencendo_em_3_dias(produtos[i], data_alvo);
            }
        }
    }
}