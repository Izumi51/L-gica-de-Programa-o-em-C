#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	tPilha* pilha = criaPilha();
	int x;

	for (int i = 0; i < 5; i++)
	{
		push(pilha, i+2);
	}

	exibePilha(pilha);

	printf("\n");

	pop(pilha, &x);
	printf("dado: %d\n", x);
	exibePilha(pilha);

	return 0;
}
