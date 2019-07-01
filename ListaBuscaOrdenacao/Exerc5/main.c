#include <stdio.h>
#include <stdlib.h>

#define N 9

int main()
{
    int vetor[N] = {1,2,4,5,6,22,3,11};
    int i, j, temp;

    for(i = 0; i < N-1; i++){
        for(j = 0; j < N-i-1; j++){
            if(vetor[j] < vetor[j+1]){
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }

    for(i = 0; i < N; i++){
        printf("%d ", vetor[i]);
    }
}
