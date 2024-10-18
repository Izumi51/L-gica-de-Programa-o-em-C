/* Tipo exportado */
typedef struct ponto Ponto;

/* Funções exportadas */
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
Ponto* pto_cria(float x, float y);

/* Função libera - Libera a memória de um ponto previamente criado */
void pto_libera(Ponto* p);

/* Função acessa - Retorna os valores das coordenadas de um ponto */
void pto_acessa(Ponto* p, float* x, float* y);

/* Função atribui - Atribui novos valores às coordenadas de um ponto */
void pto_atribui(Ponto* p, float x, float y);

/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia(Ponto* p1, Ponto* p2);

/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* pto_getPonto(Ponto* p);

/* Função exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/

/* Função exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/
void pto_exibe(Ponto* p);

int pto_compara(Ponto* pt1,Ponto* pt2);
/* Função compara -recebe dois pontos e retorna:
0 se os pontos são iguais
valor negativo se o ponto 1 1 está mais próximo da origem que o pto 2
valor positivo,  cc*/


/* Função pto_soma, recebe dois pontos e retorna um
novo ponto, com as soma das coordenadas */
Ponto* pto_soma(Ponto * p1, Ponto* p2);

/*comparar dois pontos*/
void pto_atribui (Ponto *p,double x,double y);  

void pto_atribuiX (Ponto *p,double x);

void pto_atribuiY (Ponto *p,double y);

void pto_obtem (Ponto *p1, Ponto *p2);

float pto_obtemX (Ponto * p,double *x);

float pto_obtem Y (Ponto * p,double *y); 

Ponto *pto_copia (Ponto *p);

pto_desloca (Ponto *p, int n1, int n2);

pto_deslocaX (Ponto *p, int n1, int n2);

pto_deslocaY (Ponto *p, int n1, int n2);
/**/
/**/
/**/
/**/
/**/
/**/