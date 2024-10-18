typedef struct unidade Unidade;

// Criar
Unidade* uni_cria(int lote, int dia, int mes, int ano);
// liberar
void uni_libera(Unidade* uni);
// exibir
void uni_exibe(Unidade* uni);
// get para cada atributo
char* uni_getUnidadeData(Unidade* uni);
char* uni_getUnidadeLote(Unidade* uni);
// set para cada atributo
void uni_setUnidadeData(Unidade* uni, int novoAno, int novoMes, int novoDia);
void uni_setUnidadeLote(Unidade* uni, int novoLote);

// Idade : retorna o número de dias entre a data alvo e a data de fabricação
int uni_idade (Unidade* uni, int dia, int mes, int ano);

// Saber se uma unidade “é menor” que outra: se foi fabricado há menos tempo que o
// outro (menor idade). Caso os dois produtos tenham a mesma idade, considerar o lote
// Ex P1  fabricado em 12/12/2019 lote 3
// P2  fabricado em 1/12/2019 lote 5
// P3  fabricado em 1/12/2019 lote 2
// P1 < P2  True
// P2<P3  False
int uni_compara (Unidade* uni1, Unidade* uni2);

//  getUnidade: retorna uma string com os valores
char* uni_getUnidade(Unidade* uni);