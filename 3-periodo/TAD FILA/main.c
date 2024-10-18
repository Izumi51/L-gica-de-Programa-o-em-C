#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	tFila* fila = criaFila();
	int x;

	for (int i = 0; i < 5; i++)
	{
		enfileirar(fila, i+2);
	}

	exibeFila(fila);

	printf("\n");

	desenfileirar(fila);
	exibeFila(fila);

    liberaFila(fila);
    
	return 0;
}
