#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 10;
char stringAux[10];
int contador = 0;

struct Pilha {
	char letras[10];
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

	struct Pilha pilha;

	char string[10];

	Reset(&pilha);

	printf("Digite a string: ");
	scanf("%s", string);
	
	for (int i = 0; i<strlen(string); i++) {
		Push(&pilha, string[i]);	
	}	
	for (int i = 0; i<strlen(string); i++) {
		Pop(&pilha, string[i]);	
	}	
	if (strcmp(string, stringAux) == 0) {
		printf("A string é um palindromo!");	
	}	else {
		printf("A string não é palindromo!");	
	}	
	
	
}
