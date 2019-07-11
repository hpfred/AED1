#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stringAux[10]; // VARIAVEIS AUXILIARES PARA SALVAR A STRING QUE SERA FORMADA AO CONTRARIO
int i = 0;

struct Pilha {
	char letra[10];
	int topo;
	int base;
	int limite;	
};

void Reset(struct Pilha *p) {
	p->topo = 0;
	p->base = 0;
	p->limite = 10;	
}		

int Empty(struct Pilha *p) {
	return p->topo == 0;
}	

int Full(struct Pilha *p) {
	return p->topo == 10;	
}	

int Pop(struct Pilha *p, char letra) {
	
	if (Empty(p)) {
		printf("\nA pilha esta vazia!\n");
		return 0;	
	}	
	else {
		p->topo--;
		letra = p->letra[p->topo];	
		
		stringAux[i] = letra;
		i++;
		
		return 1;
	}	
}
int Push (struct Pilha *p, char letra) {
	if (Full(p)) {
		printf("\nNao foi possivel dar o push...\n");
		return 0;	
	}	else {
		
		p->letra[p->topo] = letra;	
		p->topo++;
		return 1;
	}	
}		

int main () {
	
	int tamanho;
	char string1[10], string2[10];
	struct Pilha pilha;

	printf("Escreva as strings: \n");
	scanf("%s", string1);
	scanf("%s", string2);
    
    Reset(&pilha);
    
    tamanho = strlen(string1);
    
    for (int i = 0; i<tamanho; i++) { // COLOCA TODAS LETRAS NA PILHA
		Push(&pilha, string1[i]);	
	}	
	for (int i = 0; i<tamanho; i++) { // RETIRA TODAS LETRAS DA PILHA E POE EM ORDEM INVERSA
		Pop(&pilha, string1[i]);	
	}	
	
	/*for(int i = 0; i<tamanho; i++) {
		printf("%c", pilha.letra[i]);
	}	
	printf("\n%s", stringAux);*/
	
	if (strcmp(stringAux, string2) == 0 ){
		printf("As strings estao no formato XY!");	
	}	
	else {
		printf("As strings NAO estao no formato XY!");	
	}	
        
	
}	



