// Usando o TAD ponto construa o TAD retângulo com as seguintes funcionalidase:
// cria, libera, area, exibe, getRetangulo
// Ao criar um novo retângulo, é recebido as coordenadas do pie e do psd. 
// A struct deve armazenar os 4 pontos, a base e a altura
#include "ponto.h"
#include "retangulo.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct retangulo {
  Ponto* pie;
  Ponto* pse;
  Ponto* psd;
  Ponto* pid;
  double base;
  double altura;
};

Retangulo* rtg_cria (float xie, float yie, float xsd, float ysd)
{
    Retangulo* R = (Retangulo*)malloc(sizeof(Retangulo));
    if (R == NULL) {
      printf("Memória insuficiente!\n");
      exit(1);
    }
    R->pie = pto_cria(xie, yie);
    R->psd = pto_cria(xsd, ysd);
    R->pse = pto_cria(xie, ysd);
    R->pid = pto_cria(xsd, yie);
    
    R->base = pto_distancia(R->pie, R->pid);
    R->altura = pto_distancia(R->pse, R->psd);
    
    return R;
}

void rtg_libera (Retangulo* R)
{
    pto_libera (R->pie);
    pto_libera (R->pse);
    pto_libera (R->psd);
    pto_libera (R->pid);
    
    free(R);
}

float rtg_area (Retangulo* R)
{
    float area;

    return R->base * R->altura;    
}

void rtg_exibe (Retangulo* R)
{
    
}

char* rtg_getRetangulo (Retangulo* R)
{
    char* ret = (char*)malloc(sizeof(*R) + 8);
    
    sprintf(ret,"( %p , %p, %p, %p )", R->pid, R->pie, R->psd, R->pse);
    
    return ret;
}