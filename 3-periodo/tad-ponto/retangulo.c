// Usando o TAD ponto construa o TAD retângulo com as seguintes funcionalidase:
// cria, libera, area, exibe, getRetangulo
// Ao criar um novo retângulo, é recebido as coordenadas do pie e do psd. 
// A struct deve armazenar os 4 pontos, a base e a altura
#include 'ponto.h'
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
    Retangulo* r = (Retangulo*)malloc(sizeof(Retangulo));
    if (r == NULL) {
      printf("Memória insuficiente!\n");
      exit(1);
    }
    r->pie = pto_cria(xie, yie);
    r->psd = pto_cria(xsd, ysd);
    r->pse = pto_cria(xie, ysd);
    r->pid = pto_cria(xsd, yie);
    
    r->base = pto_distancia(pie, pid);
    r->altura = pto_distancia(pse, psd);
    
    return r;
}

void rtg_libera (Retangulo* R)
{
    pto_libera (r->pie);
    pto_libera (r->pse);
    pto_libera (r->psd);
    pto_libera (r->pid);
    
    free(r);
}

float rtg_area (Retangulo* R)
{
    float area;

    return r->base * r->altura;    
}

void rtg_exibe (Retangulo* R)
{
    
}

char* rtg_getRetangulo (Retangulo* R)
{
    char* ret = (char*)malloc(sizeof(*p) + 8);

    sprintf(ret, "(x1: %s, x2: %s, y1: %s, y2: %s)", pto_getPonto (p->p), p->r);

    return ret;
}