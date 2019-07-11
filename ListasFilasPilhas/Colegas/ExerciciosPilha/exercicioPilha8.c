#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 15;
char stringAux[15];
int contador = 0;

struct Pilha {
	char letras[15];
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
int Push (struct Pilha *p, char letra) {
	if (!Full(p)) {
		p->letras[p->topo] = letra;
		p->topo++;
		return 1;	
	}	
	else {
		printf("\nNao foi possivel dar o push.\n");
		return 0;	
	}	
	
}
int Pop(struct Pilha *p, char letra) {
	if (!Empty(p)) {
		p->topo--;
		letra = p->letras[p->topo];
		
		stringAux[contador] = letra;
		contador++;
		return 1;	
	}		
	else {
		printf("\nNao foi possivel dar o POP.\n");
		return 0;	
	}	
}		
int main () {
	
	char string[15];
	
	struct Pilha pilha;
	
	Reset(&pilha);
	
	printf("Digite a string: ");
	scanf("%s", string);
	
	
	if (string[0] == '(') {
		for (int i = 0; i<strlen(string); i++) { // EMPILHA TODOS OS COLCHETES
			if (string[i] == '(') {
				Push(&pilha, string[i]);
			} else {
				Pop(&pilha, string[i]);	
			}			
		}		
	} else {
		printf("A funcao nao pode comecar com um ')'...\n ");	
		exit(1);
	}	
	if (pilha.topo == 0) {
		printf("A funçao esta CORRETA! ");	
	}	else {
		printf("A funçao estao INCORRETA!");	
	}	
	
	
}	
