#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 8;
int vetorAux[8];
int contador = 0;

void insertionSort(int *vet, int tamanho);

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
		
		vetorAux[contador] = numero;
		contador++;
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
	
	for (int i = 0; i<8; i++) { // DESEMPILHA E COLOCA TODOS EM UM VETOR AUXILIAR
		Pop(&pilha, vetor[i]);	
	}
	
	insertionSort(vetorAux, 8); // ORDENA O VETOR AUXILIAR
	
	for (int i = 0; i<8; i++) { // EMPILHA TODOS NUMEROS ORDENADOS DE MANEIRA CRESCENTE
		Push(&pilha, vetorAux[i]);	
	}	
	
	
}	
void insertionSort(int *vet, int tamanho) {
		
	int i, j, temp, contador=0;
	
	for (j=1; j<tamanho; j++) {
		
		i = j - 1;
		temp = vet[j];
		
		while ((i>=0) && (temp < vet[i])) {
			vet[i+1] = vet[i];
			i--;
			contador++;	
		}
		
		vet[i+1] = temp;		
	}		
	
}	
