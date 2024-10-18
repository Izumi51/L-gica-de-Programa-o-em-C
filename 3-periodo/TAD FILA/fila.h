// Definição do tipo nó (Nozin)
typedef struct no tNo;

// Definição do tipo Fila (Fila)
typedef struct fila tFila;

// Função para criar uma Fila
tFila *criaFila();

// Função para emFilar
int enfileirar(tFila *fila, int dado);
 
// Função para desemFilar
int desenfileirar(tFila *fila); 

// libera a fila
void liberaFila(tFila *fila); 
 
// Função para exibir os elementos da Fila (só para teste)
void exibeFila(tFila *fila);

// Verifica se a Fila está vazia
int filaVazia(tFila *fila);