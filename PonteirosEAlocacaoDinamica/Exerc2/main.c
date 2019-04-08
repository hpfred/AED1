/// 2) Fa�a uma fun��o que receba um valor n e crie dinamicamente um vetor de n
/// elementos e retorne um ponteiro. Crie uma fun��o que receba um ponteiro para um
/// vetor e um valor n e imprima os n elementos desse vetor. Construa tamb�m uma
/// fun��o que receba um ponteiro para um vetor e libere esta �rea de mem�ria. Ao final,
/// crie uma fun��o principal que leia um valor n e chame a fun��o criada acima. Depois, a
/// fun��o principal deve ler os n elementos desse vetor. Ent�o, a fun��o principal deve
/// chamar a fun��o de impress�o dos n elementos do vetor criado e, finalmente, liberar a
/// mem�ria alocada atrav�s da fun��o criada para libera��o.

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

