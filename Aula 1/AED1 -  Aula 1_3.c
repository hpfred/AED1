#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AdicionaNome();
void RemoveNome();
void Lista();

char *lista;

int main(){
	int escolha;

    lista = malloc(1);
    strcpy(lista, "");

	for(;;){
		printf("1) Adicionar nome\n2) Remover nome\n3) Listar\n4) Sair\n");
		scanf("%d",&escolha);
		switch(escolha){
			case 1: AdicionaNome();
					break;
			case 2: RemoveNome();
					break;
			case 3: Lista();
					break;
			case 4: exit(0);
					break;
		}
	}
	return 0;
}

void AdicionaNome(){
    char nome[50];
    int tamanho, TamanhoLista;

    printf("Informe nome a ser adicionado: ");
    scanf("%s",nome);
    tamanho = strlen(nome);
    TamanhoLista = strlen(lista);

    lista = realloc(lista, tamanho + TamanhoLista + 2);
	//lista = realloc(lista, tamanho + TamanhoLista);

    strcat(lista, nome);
    strcat(lista, "\n");
}

void RemoveNome(){
	char nome[50];
	int i = 0, j = 0, tamanho, TamanhoLista;
	
	printf("Informe o nome a ser removido: ");
	scanf("%s", nome);
    tamanho = strlen(nome);
    TamanhoLista = strlen(lista);
	
	//for(i=0; nome != "\0"; i++){
		//for(j=0; 
	while(lista[j] != '\0'){
		if(nome[i] == lista[j]){		
			i++;
			j++;
		}
		
		else{
			
			while(lista[j] != '\n'){
				j++;
			}
			i = 0;
			j++;
		}
		
		if(nome[i] == '\0'){
			while(lista[j] != '\0'){
				lista[j - tamanho - 1] = lista[j];
				//lista[j - tamanho] = lista[j];
				j++;
			}
			//printf("%d %d", TamanhoLista, tamanho);
			TamanhoLista = TamanhoLista - tamanho - 1;				// -1 caso no inicio +2 (1 para /n e 1 para /0
			//printf("%d", TamanhoLista);
			lista = realloc(lista, TamanhoLista);			//reclamando do tamanho antigo, mas ele n pede posição antiga?
		}
	
	}

}

void Lista(){
    puts(lista);
}
