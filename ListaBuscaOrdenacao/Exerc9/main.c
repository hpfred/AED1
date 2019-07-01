#include <stdio.h>
#include <stdlib.h>

int main()
{                  //12 72 72
    int array[10] = {72,12,62,69,27,67,41,56,33,74};
    int i, j, temp, Ncopias = 0;

    for(i = 1; i < 10; i++){
        temp = array[i];
        j = i - 1;
        while((j >= 0) && (temp < array[j])){
            array[j+1] = array[j];
            array[j] = temp;
            j--;
            Ncopias++;
        }
        //array[j+1] = temp;
    }

    printf("Numero de copias: %d \nLista ordenada: ", Ncopias);
    for(i = 0; i < 10; i++){
        printf("%d ",array[i]);
    }
}
