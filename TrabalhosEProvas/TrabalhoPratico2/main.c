// Nao se preocupem com isso
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

#include <stdio.h>
#include <stdlib.h>

// numTrocas : recebe um vetor e seu tamanho, retorna o numero minimo de trocas necessarias para que o vetor respeito o criterio especificado.
int numTrocas(int * vetor, int tamanho) {
    /// Selection Sort
    ///
    /// O Selection Sort foi escolhido, pois ele possibilita se obter a ordenação
    /// com o menor numero de trocas possível, devido a encontrar o menor valor e
    /// compara-lo com todos os valores do vetor antes de realizar a troca.

    int count = 0;
    int min, minEnd, i, j, temp;

    /*
    /// Teste Antes da Ordenação

    for(i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    //*/

    for(i = 0; i < tamanho; i++){
        min = vetor[i];
        minEnd = i;
        for(j = i+1; j < tamanho; j++){
            if(vetor[j] < min){
                min = vetor[j];
                minEnd = j;
            }
        }
        if(min != vetor[i]){
            temp = vetor[i];
            vetor[i] = min;
            vetor[minEnd] = temp;

            count++;
        }
    }

    /*
    /// Teste da Ordenação

    for(i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    //*/

    return count;
}

int main() {
    int tamanho, resultado;
    int * vetor;

    printf("---Testes de Validacao---\n");
    printf("1. ");

    tamanho = 4;
    vetor = (int *) malloc(tamanho * sizeof(int));
    vetor[0] = 2;
    vetor[1] = 5;
    vetor[2] = 3;
    vetor[3] = 1;
    resultado = numTrocas(vetor, tamanho);

    if (resultado == 2) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 2\n" RESET, resultado);
    }
    free(vetor);

    printf("2. ");

    tamanho = 5;
    vetor = (int *) malloc(tamanho * sizeof(int));
    vetor[0] = 1;
    vetor[1] = 2;
    vetor[2] = 3;
    vetor[3] = 4;
    vetor[4] = 4;
    resultado = numTrocas(vetor, tamanho);

    if (resultado == 0) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != \n" RESET, resultado);
    }
    free(vetor);

    printf("3. ");

    tamanho = 12;
    vetor = (int *) malloc(tamanho * sizeof(int));
    vetor[0] = 17;
    vetor[1] = 23;
    vetor[2] = 44;
    vetor[3] = 11;
    vetor[4] = 3;
    vetor[5] = 17;
    vetor[6] = 31;
    vetor[7] = 55;
    vetor[8] = 12;
    vetor[9] = 91;
    vetor[10] = 47;
    vetor[11] = 19;
    resultado = numTrocas(vetor, tamanho);

    if (resultado == 10) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 10\n" RESET, resultado);
    }
    free(vetor);

    printf("4. ");

    tamanho = 27;
    vetor = (int *) malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) vetor[i] = (i%2 == 0) ? i : tamanho - i;

    resultado = numTrocas(vetor, tamanho);

    if (resultado == 12) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 12\n" RESET, resultado);
    }
    free(vetor);

    printf("5. ");

    tamanho = 12;
    vetor = (int *) malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) vetor[i] = (i%2 == 0) ? tamanho - i : i;

    resultado = numTrocas(vetor, tamanho);

    if (resultado == 9) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 9\n" RESET, resultado);
    }
    free(vetor);

    return 0;
}
