/// 3) Construa um programa (main) que aloque em tempo de execu��o (dinamicamente)
/// uma matriz de ordem m x n (linha por coluna), usando 1+m chamadas a fun��o malloc.
/// Agora, aproveite este programa para construir uma fun��o que recebendo os
/// parametros m e n aloque uma matriz de ordem m x n e retorne um ponteiro para esta
/// matriz alocada. Crie ainda uma fun��o para liberar a �rea de mem�ria alocada pela
/// matriz. Finalmente, crie um novo programa (main) que teste/use as duas fun��es
/// criadas acima.

#include <stdio.h>

int** AlocaMatriz(int m, int n);
void LiberaMatriz(int m, int** Matriz);

int main(){
    int m, n;
    int** Matriz;

    printf("Informe m: ");
    scanf("%d", &m);
    printf("Informe n: ");
    scanf("%d", &n);

    Matriz = AlocaMatriz(m, n);

    // Crie um novo programa (main) que teste/use as duas fun��es
        int i, j;

        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                scanf("%d", &Matriz[i][j]);
            }
        }

        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                printf("%d ", Matriz[i][j]);
            }
            printf("\n");
        }
    // Fim do programa de teste

    LiberaMatriz(m, Matriz);

    return 0;
}

int** AlocaMatriz(int m, int n){
    int** Matriz;
    int i;

    Matriz = (int**)malloc((sizeof(int*))*m);

    for(i = 0; i < m; i++)
        Matriz[i] = (int*)malloc((sizeof(int))*n);

    return Matriz;

}

void LiberaMatriz(int m, int** Matriz){
    int i;

    for(i = 0; i < m; i++)
        free(Matriz[i]);
    free(Matriz);

    return;
}
