#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[50], i, j=0;
    while(scanf("%d",&vetor[j]) != EOF){
        j++;
    }

    for(i=0; i<j-1;i++){
        if(vetor[i] > vetor[i+1]){
            exit(0);
        }
    }

    //printf("Hello World");

    for(i=0; i < j; i++){
        printf("%d ",vetor[i]);
    }
}
