#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// funcao que cria a pilha
Pilha *cria_pilha(void)
{
	Pilha *p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}


// funcao que empilha um elemento no topo da pilha
void pilha_push(Pilha *p, void *valor)
{
	Lista *novo = (Lista*) malloc(sizeof(Lista));
	novo->info = valor;
	novo->proximo = p->topo;

	p->topo = novo;
}


// funcao que desempilha um elemento do topo da pilha
void pilha_pop(Pilha *p)
{
	Lista *t;
	void *v;
	
	if(pilha_vazia(p))
		exit(1);	//aborta o programa
	
	t = p->topo;
	v = t->info;
	p->topo = t->proximo;
	
	free(t);
}


// funcao que verifica se a pilha esta vazia
int pilha_vazia(Pilha *p)
{
	return(p->topo==NULL);
};


// funcao que imprime a pilha
void pilha_imprime(Pilha *p)
{
	while(!pilha_vazia(p))
	{
		int *dado = (int*) p->topo->info;
		printf("%d\n", *dado);
		pilha_pop(p);
	}
}


// funcao que inspeciona o elemento do topo da pilha
void* pilha_peek(Pilha *p)
{
	void *t;
	t = p->topo->info;
	
	return t;
}


// funcao torre de hanoi
void hanoi(int n, Pilha *p1, Pilha *p3, Pilha *p2, int opcaoImprime, char orig, char dest, char aux)
{
	if (n==1)
	{ 
		// verifica se o programa foi executado com a opcao -v
		if (opcaoImprime  == 0)
			printf("Move disk 1 from %c to %c\n", orig, dest);
		pilha_push(p3, &n);
		pilha_pop(p1);
   		return;
	}
	
	hanoi(n-1, p1, p2, p3, opcaoImprime, orig, aux, dest);
	pilha_push(p3, pilha_peek(p1));
	
	// verifica se o programa foi executado com a opcao -v
	if (opcaoImprime  == 0)
		printf("Move disk %d from %c to %c\n", n, orig, dest);
	
	pilha_pop(p1);
	hanoi(n-1, p2 ,p3 ,p1, opcaoImprime, aux,dest,orig);
}

