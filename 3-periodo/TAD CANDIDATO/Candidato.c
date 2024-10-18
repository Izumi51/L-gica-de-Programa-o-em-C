#include "ponto.h"
#include "Candidato.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/* Implementação TAD: Ponto (x,y) */
/*definição do tipo exportado*/
struct candidato {
    char *nome;
    int idade;
    Ponto* resp;
};

double calcularDistancia(Candidato* cand, int ntJ1, int ntJ2);

Candidato* cad_cria(char* nome, int idade, int nota1, int nota2)
{
    Candidato* cand = (Candidato*) malloc(sizeof(Candidato));
    if (cand == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    
    cand->nome = (char*) malloc((strlen(nome) + 1) * sizeof(char));
    cand->idade = idade;
    cand->resp = pto_cria(nota1, nota2);
    
    return cand;
}

void cad_libera(Candidato* cand)
{
    free(cand->nome);
    free(cand->resp);
    free(cand);
}

void cad_exibe (Candidato* cand)
{
    printf("(nome: %s, idade: %d, notas: %s)", cand->nome, cand->idade, pto_getPonto(cand->resp));
}

char* cad_getCandidato(Candidato* cand)
{
    char* candi;
    candi = (char*)malloc(30);
    sprintf(candi, "(nome: %s, idade: %d, notas: %s)", cand->nome, cand->idade, pto_getPonto(cand->resp));
    return candi;
}

// Compara : recebe dois candidatos e  retorna -1, se o primeiro é mais jovem que o segundo, 0 se tem a mesma idade e +1,caso contrário
int cad_compara (Candidato* cand1, Candidato* cand2)
{
    if (cand1->idade = cand2->idade)
    {
        return 0;
    }else{
        if(cand1->idade < cand2->idade)
        {
            return -1;
        }else{
            return 1;
        }
    }
}
/* ehTestador: recebe a pontuação para cada jogo  do testador ideal  e um limiar. Retorna True  se o candidato pode 
ser um testador do novo jogo ou 0, caso contrário. (nesse exemplo: nota 5 ao primeiro jogo e nota 8  ao 2º) Para ser 
testador, as notas do candidato  devem estar a uma distância menor ou igual ao limiar das notas do testador ideal.*/
int cad_ehTestador (Candidato* cand, int ntJ1, int ntJ2, float limiar)
{
    float dist;
    
    dist = calcularDistancia(cand, ntJ1, ntJ2);

    if (dist <= limiar)
    {
        return 1;
    }
    
    return 0;
}

double calcularDistancia(Candidato* cand, int ntJ1, int ntJ2)
{
    return sqrt(pow((cand->resp->x - cand->resp->y), 2) + pow((ntJ1 - ntJ2), 2));
}
