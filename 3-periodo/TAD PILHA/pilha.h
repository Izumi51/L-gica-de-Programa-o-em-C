// Definição do tipo nó (Nozin)
typedef struct no tNo;

// Definição do tipo pilha (Pilha)
typedef struct pilha tPilha;

// Função para criar uma pilha
tPilha *criaPilha();

// Função para empilhar (push)
int push(tPilha *p, int dado);

// Função para desempilhar (pop)
int pop(tPilha *p, int *dado);

// Função para exibir os elementos da pilha (só para teste)
void exibePilha(tPilha *p);

// Verifica se a pilha está vazia
int pilhaVazia(tPilha *p);
