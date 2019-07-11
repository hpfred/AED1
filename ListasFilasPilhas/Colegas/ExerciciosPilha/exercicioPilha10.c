#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 8;
int maior, menor;
float ma = 0;

struct Pilha {
	char numeros[8];
	int topo;
	int base;
	int limite;	
};	

void Reset(struct Pilha *p) {
	p->topo = 0;
	p->limite = MAX;
	p->base = 0;	
}	
int Empty(struct Pilha *p) {
	return p->topo == 0;	
}	
int Full (struct Pilha *p) {
	return p->topo == p->limite;	
}	
int Push (struct Pilha *p, int numero) {
	if (!Full(p)) {
		p->numeros[p->topo] = numero;
		p->topo++;
		return 1;	
	}	
	else {
		printf("\nNao foi possivel dar o push.\n");
		return 0;	
	}	
	
}
int Pop(struct Pilha *p, int numero) {
	if (!Empty(p)) {
		p->topo--;
		numero = p->numeros[p->topo];
		
		if (p->topo+1 == p->limite) {
			maior = numero;
			menor = numero;
		}	else {
			if (numero > maior) {
				maior = numero;	
			}		
			if (numero < menor) {
				menor = numero;	
			}	
		}	
		ma += numero;
		
		return 1;	
	}		
	else {
		printf("\nNao foi possivel dar o POP.\n");
		return 0;	
	}	
}		
int main () {
	
	int vetor[8];
	
	struct Pilha pilha;
	
	Reset(&pilha);
	
	for (int i = 0; i<8; i++) {
		scanf("%d" , &vetor[i]);
	}	
	
	for (int i = 0; i<8; i++) { // EMPILHA TODOS NUMEROS
		Push(&pilha, vetor[i]);	
	}	
	
	for (int i = 0; i<8; i++) { // DESEMPILHA	
		Pop(&pilha, vetor[i]);	
	}
	ma = ma/8;
	
	printf("Maior: %d\nMenor: %d\nMedia: %f", maior, menor, ma);
}	
	
	
