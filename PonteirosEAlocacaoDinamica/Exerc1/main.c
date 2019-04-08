/// 1) Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos
/// e passe esse vetor para uma função que vai ler os elementos desse vetor. Depois, no
/// programa principal, o vetor preenchido deve ser impresso. Além disso, antes de
/// finalizar o programa, deve-se liberar a área de memória alocada.

#include <stdio.h>

void LeElementos(int *vetor, int n);

int main(){
    int n, i;

    scanf("%d",&n);
    int *vetor = (int*)malloc(n*(sizeof(int)));
    int *Temp = vetor;

    LeElementos(vetor, n);

    vetor = Temp;
    for(i = 0; i < n; i++){
        //printf("%d ", *vetor);
        printf("%d ", vetor[i]);
        //if(i != n-1)
        //    vetor = vetor + sizeof(int);
    }

    vetor = Temp;

    free(vetor);

    return 0;
}

void LeElementos(int *vetor, int n){
    int i;

    for(i = 0; i < n; i++){
        printf("Informe o %do valor: ", i+1);
        //scanf("%d", vetor);
        scanf("%d", &vetor[i]);
        //if(i != n-1)
        //    vetor = vetor + sizeof(int);
    }

    return;
}
