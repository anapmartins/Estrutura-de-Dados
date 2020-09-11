#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"


int main (int argc, char *argv[])
{
	// declaracao de variaveis
	int n, i, *disco, opcaoImprime; 
	
	// quantidade de discos
	// atoi converte de alfanumerico para inteiro
	n = atoi(argv[1]);
	
	if (argc > 2)
	{
		opcaoImprime = strcmp(argv[2], "-v");
		// imprime configuracao inicial se o programa for executado com a opcao -v
		if (opcaoImprime == 0)
		{
			printf("=> Solving the Tower of Hanoi with %d disks.\n", n);
			printf("=> Initial configuration:\n");
			printf("A: ");

			for (i=n; i>0; i--)
				printf("%d ", i);

			printf("\nB:\nC:\n");
			printf("=> Moves:\n");
		}
	}
	
	else
		opcaoImprime = 1;
		
	// criacao das pilhas
	Pilha *p1, *p2, *p3;
	p1 = cria_pilha();
	p2 = cria_pilha();
	p3 = cria_pilha();
	
	// insere discos na torre 1
	for (i=n; i>0; i--)
	{
		disco = (int*) malloc(sizeof(int));
		*disco = i;
		pilha_push(p1, disco);
	}
	
	// realiza os movimentos da torre de hanoi
	hanoi(n, p1, p3, p2, opcaoImprime, 'A', 'C', 'B');
	
	if (argc > 2)
	{
		// imprime a configuracao final se o programa for executado com -v
		if (opcaoImprime == 0)
		{
				printf("=> Final configuration:\n");
			printf("A:\nB:\n");
			printf("C: ");
			for (i=n; i>0; i--)
					printf("%d ", i);
			printf("\n");
		}
	}
	
	return 0;
}

