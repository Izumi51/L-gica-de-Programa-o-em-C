#include "Unidade.h"
#include "Data.h"
#include <stdlib.h>
#include <stdio.h>

struct unidade {
  tData* data;
  int lote;
};

Unidade* uni_cria(int lote, int dia, int mes, int ano)
{
    Unidade* uni = (Unidade*) malloc(sizeof(Unidade));
    if (uni == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    
    uni->lote = lote;
    uni->data = dta_cria(dia, mes, ano);
    
    return uni;
}

void uni_libera(Unidade* uni) 
{
    free(uni->data);
    free(uni);
}

void uni_exibe (Unidade* uni)
{
    printf("(lote: %d, data: %s)", uni->lote, dta_getData(uni->data));

}

char* uni_getUnidadeData(Unidade* uni)
{
    char* unid;
    unid = (char*)malloc(20);
    sprintf(unid, "data: %s", dta_getData(uni->data));
    return unid;
}

char* uni_getUnidadeLote(Unidade* uni)
{
    char* unid;
    unid = (char*)malloc(20);
    sprintf(unid, "lote: %d", uni->lote);
    return unid;
}

void uni_setUnidadeData(Unidade* uni, int novoAno, int novoMes, int novoDia)
{
    dta_atribui(uni->data, novoDia, novoMes, novoAno);
}

void uni_setUnidadeLote(Unidade* uni, int novoLote)
{
    uni->lote = novoLote;
}

// Idade : retorna o número de dias entre a data alvo e a data de fabricação
int uni_idade (Unidade* uni, int dia, int mes, int ano)
{
    return dta_diferenca(uni->data, dta_cria(dia, mes, ano));
}

int uni_compara (Unidade* uni1, Unidade* uni2)
{
    int dia2, mes2, ano2;
    int dia1, mes1, ano1;
    int d1, d2;
    
    dta_acessa(uni1->data, &dia1, &mes1, &ano1);
    dta_acessa(uni2->data, &dia2, &mes2, &ano2);
    d1 = convDataDiaJuliano(dia1, mes1, ano1);
    d2 = convDataDiaJuliano(dia2, mes2, ano2);
    
    if (d1 > d2){
        return 1; 
    }else{
        if (d1 < d2){
            return 0;
        }else{
            if (uni1->lote > uni2->lote){
                return 1;
            }else{
                if (uni1->lote < uni2->lote)
                {
                    return 0;
                }
                else {
                    return -1; //dias iguais
                }
            }
        }
    }
}