/* Tipo exportado */

typedef struct circulo Circulo;

/* Funções exportadas */

/* Função cria - Aloca e retorna um círculo com centro (x,y) e raio r */

Circulo* circ_cria(float x, float y, float r);

/* Função libera - Libera a memória de um círculo previamente criado */

void circ_libera(Circulo* c);

/* Função area - Retorna o valor da área do círculo */

float circ_area(Circulo* c);

/* Função interior - Verifica se um dado ponto p está dentro do círculo */

int circ_interior(Circulo* c, Ponto* p);

/* Função getCirculo - Retorna uma string lo no formato (c:centro,r:raio)*/

char* circ_getCirculo(Circulo* p);

/* Função exibe -Escreve na tela o círculo no formato (c:centro,r:raio)*/

void circ_exibe(Circulo* p);

/* Função compara - Retorna 1 se o 1º círculo é == ao 2º*/

int circ_compara(Circulo* c1, Circulo* c2);

/* Função clona – cria um novo cículo igual ao recebido*/

Circulo* circ_clona(Circulo* c1);