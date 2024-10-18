#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_MAX_NOMES 20

struct resposta {
    int resposta1;
    int resposta2;
};

typedef struct resposta TResposta;

struct pessoa {
    char *nome;
    TResposta respostas;
};

typedef struct pessoa TPessoa;

int calcularDistancia(TPessoa *pessoa1, TPessoa *pessoa2);
void encontrarCompatibilidade(TPessoa *pessoas, int numPessoas, float limiar, char *nome);
void inicializarPessoas(int quantPessoas, TPessoa *pessoas, char *vNomAux[]);
void exibe(TPessoa pessoa);
void perguntarNome(char **nome);

int main(void) {
    int numPessoas;
    int i;
    float limiar;
    char *vNomAux[NUM_MAX_NOMES] = {
        "Max", "Leo", "Lia", "Zoe", "Eli",
        "Gus", "Mia", "Ava", "Dan", "Ray",
        "Sam", "Joy", "Ted", "Sue", "Bob",
        "Ivy", "Ben", "Ana", "Kim", "Ira"
    };
    TPessoa *pessoas;
    char *nome;

    printf("Qual sera o numero de pessoas: ");
    scanf("%d", &numPessoas);

    pessoas = (TPessoa *)malloc(sizeof(TPessoa) * numPessoas);

    inicializarPessoas(numPessoas, pessoas, vNomAux);

    for (i = 0; i < numPessoas; i++)
    {
        exibe(pessoas[i]);
    }

    perguntarNome(&nome);

    printf("Digite o limiar de compatibilidade: ");
    scanf("%f", &limiar);

    for (i = 0; i < numPessoas; i++)
    {
        exibe(pessoas[i]);
    }

    encontrarCompatibilidade(pessoas, numPessoas, limiar, nome);

    for (i = 0; i < numPessoas; i++)
    {
        free(pessoas[i].nome);
    }
    free(pessoas);
    free(nome);

    return 0;
}

void perguntarNome(char **nome)
{
    char tempNome[100];

    printf("Insira o nome: ");
    scanf (" %[^\n]", tempNome);

    *nome = (char *)malloc(strlen(tempNome) + 1);

    strcpy(*nome, tempNome);
}

void inicializarPessoas(int quantPessoas, TPessoa *pessoas, char *vNomAux[])
{
    int i;

    for (i = 0; i < quantPessoas; i++)
    {
        pessoas[i].nome = (char *)malloc(strlen(vNomAux[i]) + 1);

        strcpy(pessoas[i].nome, vNomAux[i]);
        pessoas[i].respostas.resposta1 = rand() % 10;
        pessoas[i].respostas.resposta2 = rand() % 10;
    }
}

int calcularDistancia(TPessoa *pessoa1, TPessoa *pessoa2)
{
    return sqrt(pow((pessoa1->respostas.resposta1 - pessoa2->respostas.resposta1), 2) +
                pow((pessoa1->respostas.resposta2 - pessoa2->respostas.resposta2), 2));
}

void encontrarCompatibilidade(TPessoa *pessoas, int numPessoas, float limiar, char *nome) {
    int cert;
    float dist;
    int i;

    for (i = 0; i < numPessoas; i++)
    {
        if (strcmp(pessoas[i].nome, nome) == 0)
        {
            cert = i;
            break;
        }
    }

    for (i = 0; i < numPessoas; i++)
    {
        if (i != cert)
        {
            dist = calcularDistancia(&pessoas[cert], &pessoas[i]);

            if (dist <= limiar)
            {
                printf("%s e compativel com %s Limiar: %.2f\n", pessoas[i].nome, pessoas[cert].nome, dist);
            }
        }
    }
}

void exibe(TPessoa pessoa)
{
    printf("Nome: %s\t", pessoa.nome);
    printf("resp1: %d\t", pessoa.respostas.resposta1);
    printf("resp2: %d\t\n", pessoa.respostas.resposta2);
}
