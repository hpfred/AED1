#include <stdio.h>
#include <stdlib.h>

void Quicksort(int array[], int left, int right);

int main()
{
    int array[12] = {26, 65, 45, 73, 10, 18, 78, 93, 70, 49, 23, 22};
    int left = 0, right = 11;
    int i;

    Quicksort(array, left, right);

    for(i = 0; i < 12; i++)
        printf("%d ", array[i]);
}

void Quicksort(int array[], int left, int right){
    int meio, temp, i, j;

    i = left;
    j = right;

    meio = array[(left + right)/2];
    do{
        while(array[i] < meio)
            i++;
        while(array[j] > meio)
            j--;
        if(i <= j){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }while(i <= j);
    if(left < j)
        Quicksort(array, left, j);
    if(right > i)
        Quicksort(array, right, i);
}
