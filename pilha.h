#ifndef PILHA_H
#define PILHA_H

struct lista
{
	void *info;
	struct lista *proximo;
};

typedef struct lista Lista;


struct pilha 
{
	Lista *topo;
};

typedef struct pilha Pilha; 


Pilha* cria_pilha(void);

void pilha_push(Pilha *p, void *valor);

void pilha_pop(Pilha *p);

int pilha_vazia(Pilha* p);

void pilha_imprime(Pilha* p);

void* pilha_peek(Pilha *p);

void hanoi(int n, Pilha *p1, Pilha *p3, Pilha *p2, int opcaoImprime, char orig, char dest, char aux);

#endif
