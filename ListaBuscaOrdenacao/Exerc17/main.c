#include <stdio.h>
#include <stdlib.h>

///Ordenando conforme ir adicionando
///Lista não necessaraiamente só uma string, entaum para facilitrar pode ser vetor de vetor

int main()
{
    int n, i, TamanhoNome, TamanhoLista;
    char comp1, comp2;
    char nome[50];
    scanf("%d",&n);
    char *lista = (char*) malloc(1);
    char *lista2 = lista;

    //lê nomes
    for(i = 0; i<n; i++){
        gets(nome);         //scanf("%s",nome);
        TamanhoNome = trlen(nome);
        tamanhoLista = strlen(lista);
        lista = realloc(ref, TamanhoLista+TamanhoNome+1);
        strcat(lista,nome);
        strcat(lista,'\n');
        lista2 += TamanhoNome*sizeof(char);
    }

    lista2 = lista;

    //ordena nomes
    while(*lista2 != '\0'){
        comp1 = *lista2;
        while(*lista2 != '\n'){
            lista2 += sizeof(char);
        }
        lista2 += sizeof(char);
        comp2 = *lista2;

        if(comp2 < comp1){
            //inverte
            //comp1 = comp2
            //comp2 = próximo
        }

    }


    //imprime nomes
}
