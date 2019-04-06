/// Implemente a seguinte função. A função deve imprimir os valores que estão no
/// buffer passado por parâmetro. Os valores estão intercalados na seguinte ordem:
/// int, float, double. A variável nTotal indica o total de trios (int, float e double)
/// no buffer.
///
/// void imprimeBuffer(void *pBuffer, unsigned int nTotal);


#include <stdio.h>
#include <stdlib.h>

void imprimeBuffer(void *pBuffer, unsigned int nTotal);

void *Temp;

int main()
{
    unsigned int nTotal = 3;
    void *pBuffer = malloc(nTotal*(sizeof(int)+sizeof(float)+sizeof(double)+1));       //+3 -> para receber separação entre os valores(\n, por exemplo)
    Temp = malloc(sizeof(*pBuffer));

    Temp = pBuffer;

    int i, Inteiro = 15;
    float PontoFlutuante = 2.9;
    double Duplo = 3.14;

    for(i = 0; i < nTotal; i++){
        *(int*)pBuffer = Inteiro;
        pBuffer += sizeof(int);
        Inteiro = 30;
        *(float*)pBuffer = PontoFlutuante;
        pBuffer += sizeof(float);
        *(double*)pBuffer = Duplo;
        if(i != nTotal-1)
            pBuffer += sizeof(double);
    }

    imprimeBuffer(pBuffer, nTotal);

    free(pBuffer);
    free(Temp);

    return 0;
}

void imprimeBuffer(void *pBuffer, unsigned int nTotal){
    int i;

    pBuffer = Temp;
    //free(Temp);          // << Causa falha nos valores impressos

    for(i = 0; i < nTotal; i++){
		printf("%d ", *(int*)pBuffer);
        pBuffer += sizeof(int);
        printf("%.2f ", *(float*)pBuffer);
        pBuffer += sizeof(float);
        printf("%.2lf\n", *(double*)pBuffer);
        if(i != nTotal-1)
            pBuffer += sizeof(double);
	}

    return;
}
