/// 2) Faça uma função que receba um valor n e crie dinamicamente um vetor de n
/// elementos e retorne um ponteiro. Crie uma função que receba um ponteiro para um
/// vetor e um valor n e imprima os n elementos desse vetor. Construa também uma
/// função que receba um ponteiro para um vetor e libere esta área de memória. Ao final,
/// crie uma função principal que leia um valor n e chame a função criada acima. Depois, a
/// função principal deve ler os n elementos desse vetor. Então, a função principal deve
/// chamar a função de impressão dos n elementos do vetor criado e, finalmente, liberar a
/// memória alocada através da função criada para liberação.

#include <stdio.h>

int* CriaVetor(int n);
void ImprimeVetor(int* vetor, int n);
void LiberaVetor(int *vetor);

int main(){
    int n, i;
    int* vetor;

    scanf("%d", &n);
    vetor = CriaVetor(n);

    for(i = 0; i < n; i++){
        printf("Informe o elemento %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    ImprimeVetor(vetor, n);
    LiberaVetor(vetor);

    return 0;
}

int* CriaVetor(int n){                                  //Passagem por Parametro ou por Referencia???
    int *vetor = (int*) malloc(n*(sizeof(int)));

    return vetor;
}

void ImprimeVetor(int *vetor, int n){
    int i;

    for(i = 0; i < n; i++){
        printf("Elemento %d: %d\n", i+1, vetor[i]);
    }

}

void LiberaVetor(int *vetor){
    free(vetor);
}

