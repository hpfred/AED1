#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, j, l=0, k=0;
    int *vetor, *vetor2;

    printf("Informe o numero 'n' de decimais a serem lidos: ");
    scanf("%d",&n);

	vetor = malloc(n*(sizeof(int)));

	//int vetor[n];
	///"Não é bom fazer isso" - Professor -> Fazer com malloc

	//*
    for(i = 0; i < n; i++){
        printf("Informe o %dº numero: ",i+1);
        scanf("%d",&vetor[i]);
    }

    vetor2 = malloc(sizeof(int));

    for(i = 0; i < n; i++){								// Gera problema na situação de n=1
        for(j = i+1; j <= n; j++){						// Gera problema por quando i = ultimo valor, j está testando com algum valor posterior
            if(vetor[i] != vetor[j]){
                vetor2 = realloc(vetor2, (sizeof(vetor2)) + (sizeof(int)));
                vetor2[k] = vetor[i];					// Gera problema por estar gravando devidos as situações especificas q não são iguais
                //printf("%ld",sizeof(vetor2));
            }
            else
                l = 1;
        }
        if(l!=1)
            k++;
        l = 0;
    }

	///n = 3;	1 3 1
	///


    free(vetor);

    printf("\nVetor resultante:\n");

    i = 0;
    while(i < k){
        printf("%d ",vetor2[i]);
        i++;
    }

    free(vetor2);

	//*/
    return 0;
}
