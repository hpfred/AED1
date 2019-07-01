#include <stdio.h>
#include <stdlib.h>

typedef long TipoChave;

//struct Registro{
typedef struct Registro{
   TipoChave Chave;
}Registro;

typedef struct No *Apontador;

//struct No{
//    struct Registro Reg;
typedef struct No{
    Registro reg;
    Apontador pEsq, pDir;
}No;

int main()
{
    int in, valor;

    No *Raiz = malloc(sizeof(No));

    do{
        printf("Informe a funcao a ser executada:\n1- Adiciona nó àrvore\n2- Conta o número de nós\n0- Sai do programa\n");
        scanf("%d", &in);
        switch(in){
            case 1: printf("\nInforme o valor a ser inserido na árvore:\n");
                    scanf("%d", &valor);
                    Add(Raiz, valor);
                    break;
            case 2: CountNos();
                    break;
            case 0: exit(1);
        }
    }while(in!=0);
}

void Add(No *Raiz, int valor){
    if(Raiz->reg == NULL){
        No *NovoNo = malloc(sizeof(no));
        NovoNo->reg = valor;
        return NovoNo;
    }

    if(Raiz->reg < valor){
        Add(Raiz->pEsq, valor);
    }
    else{
        Add(Raiz->pDir, valor);
    }

    if

}

void CountNos(){


}

