/*
Construa um programa que - monte  e preencha um  vetor  de ponteiros para n (perguntado ao usuário) candidatos.
Obs: Utilize a função sorteio abaixo para simular a idade, nota ao jogo 1, nota ao jogo 2 eo índice do vetor de nomes

char vNome[10][5]={“Dodo”,”Dede”,”Didi”,”Zizo”,”Vava”,”Dudu”,”Mimi”,”Lala”,”Lele”};

// Sorteia  um número inteiro entre lInf e lSup inclusive
int sorteio(int lInf,int lSup){
  return (rand()%((lSup-lInf)+1))+lInf;

Construa um novo vetor com ponteiros para os candidatos que podem ser testadores

Mostre os selecionados, ordenados crescentemente por idade.
*/

#include <stdio.h>
#include "Candidato.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void inicializarCandidatos (Candidato* cand);
void inicializarTestadores (Candidato* cand);
int sorteio(int lInf,int lSup);

int main(void)
{
    
    Candidato *cands[];
    Candidato *testadores[];
    int quantCand;
    int indices[];
    int quantTest = 0;
    
    printf ("Quantos candidatos terao: ");
    scanf ("%d", quantCand);
    
    *cand = (Candidato*) malloc(sizeof(Candidato) * quantCand);
    indices = (int*)malloc(sizeof(int)*quantCand);
    
    for (i = 0; i < quantCand; i++)
    {
        cands[i] = inicializarCandidatos (cand[i]);
        if (cad_ehTestador (cands[i], cands->resp->x, cands->resp->y, 1.5) == 1)
        {
            quantTest += 1;
            indices[i];
        }
    }
    
    *testadores = (Candidato*) malloc(sizeof(Candidato) * quantTest);
    
    for (i = 0; i < quantTest; i++)
    {
        testadores[i] = cands[indices[i]];
    }
    
}

int sorteio(int lInf,int lSup)
{
    return (rand()%((lSup-lInf)+1))+lInf;
}

void inicializarCandidatos (Candidato* cand)
{
    int idade = sorteio(20, 80);
    char vNome[9][5]={“Dodo”,”Dede”,”Didi”,”Zizo”,”Vava”,”Dudu”,”Mimi”,”Lala”,”Lele”};
    int nota1 = sorteio(0, 10);
    int nota2 = sorteio(0, 10);
    int posiNome = sorteio(0, 8);
    
    return cand = cad_cria (nome[posiNome], idade, nota1, nota2);
}

Construa um novo vetor com ponteiros para os candidatos que podem ser testadores



