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
    strcpy(lista, "\0");

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

    printf("Informe nome: ");
    scanf("%s",nome);
    tamanho = strlen(nome);
    TamanhoLista = strlen(lista);

    lista = realloc(lista, tamanho + TamanhoLista);

    strcat(lista, nome);
    strcat(lista, "\n");
}

void RemoveNome(){

    //Algoritmo de busca de nome
    //Algoritmo de remoçãode de nome
        //Ao remover é necessário mover todos caracteres pós nome removido 'tamanho' para a esquerda
        //Fazer realloc de TamanhoLista - tamanho

}

void Lista(){
    puts(lista);
}
