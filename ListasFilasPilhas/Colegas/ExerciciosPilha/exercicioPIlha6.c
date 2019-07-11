#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 10;
int contador = 0;
char stringAux[10];

struct Pilha {
	char letras[10];
	int topo;
	int base;
	int limite;	
};
	
void Reset(struct Pilha *p) {
	p->topo = 0;
	p->base = 0;
	p->limite = 0;
}	
int Empty(struct Pilha *p) {
	return p->topo == 0;	
}	
int Full(struct Pilha *p) {
	return p->topo == MAX;	
}	
int Pop (struct Pilha *p) {
	if (!Empty(p)) {
		
		char letra;
		
		p->topo--;
		letra = p->letras[p->topo];	
		
		stringAux[contador] = letra;
		contador++;
		return 1;
	}		
	else {
		printf("\nNao e possivel retirar o topo, pilha vazia!\n");	
		return 0;
	}	
}	
int Push(struct Pilha *p, char letra) {
	if (!Full(p)) {
		p->letras[p->topo] = letra;
		p->topo++;	
		return 1;
	}		
	else {
		printf("\nNao foi possivel dar o push!\n");
		return 0;	
	}	
}	



int main () {
	
	int num_words;
	struct Pilha pilha;
	
	Reset(&pilha);
	
	printf("Número de palavras: ");
	scanf("%d", &num_words);
	
	char words[num_words][10];
	
	for (int i = 0; i<num_words; i++) {
		scanf("%s", words[i]);	
	}	
	
	
	for (int j = 0; j<num_words; j++) {
		//strcpy(palavra, words[j]);
                int i;
                
		for (i = 0; i < strlen(words[j]); i++) { // EMPILHA AS LETRAS
			Push(&pilha, words[j][i]);
		}	
		
		for (i = 0; i< strlen(words[j]); i++) { // DESEIMPILHA E JÁ COLOCA ELAS AO CONTRRARIO EM STRINGAUX
			Pop(&pilha);	
		}	
		
        stringAux[i] = '\0'; // TIRA A LETRA QUE N FAZ PARTE DA PALAVRA        
		strcpy(words[j], stringAux);
		contador = 0;
                
        Reset(&pilha);
		//printf("%s", words[j]);
		//for (int i = 0; i< strlen(words[0]); i++) {
			//printf("%c", pilha.letras[i]);	
		//}	
	}	
	//for (int i = 0; i< strlen())
	
	for (int i = 0; i<num_words; i++) {
		printf("%s ", words[i]);	
	}	


}
