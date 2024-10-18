#include "ponto.h"
#include "Circulo.h"
#include "retangulo.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159

struct circulo {

Ponto* p;

float r;

};

/* Funções exportadas */

Circulo* circ_cria (float x, float y, float r)
{

    Circulo* c = (Circulo*)malloc(sizeof(Circulo));
    
    c->p = pto_cria(x, y);
    c->r = r;

}

void circ_libera (Circulo* c)
{

    pto_libera (c->p); free(c);

}

float circ_area (Circulo* c)
{

    return PI * c->r * c->r;

}

int circ_interior (Circulo* c, Ponto* p)
{

    float d = pto_distancia (c->p, p);

    return (d < c->r);

}

char* circ_getCirculo (Circulo* p)
{

    char* pt = (char*)malloc(sizeof(*p) + 8);

    sprintf(pt, "(centro:%s , raio:%.2f )",
    pto_getPonto (p->p), p->r);

    return pt;

}

void circ_exibe (Circulo* p)
{
    
    printf("(centro: % s, raio: % .2f)",
    pto_getPonto (p->p), p->r);

}

int circ_compara (Circulo* c1, Circulo* c2)
{

    return (c1->r == c2->r && pto_compara (c1->p, c2->p));

}

Circulo* circ_clona (Circulo* cO)
{
    
    Circulo* cD = (Circulo*)malloc(sizeof(Circulo));
    
    cD->p = pto_copia (cO->p);
    
    cD->r = cO->r;
    
    return cD;

}