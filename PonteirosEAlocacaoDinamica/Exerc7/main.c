/// 7) Crie um programa para manipular vetores. O seu programa deve implementar uma
/// fun��o que receba um vetor de inteiros V e retorne um outro vetor de inteiros alocado
/// dinamicamente com todos os valores de V que estejam entre o valor m�nimo e
/// m�ximo (que tamb�m s�o passados como par�metro para a fun��o). A fun��o deve
/// obedecer ao seguinte prot�tipo: int* valores_entre(int *v, int n, int min, int max, int
/// *qtd); A fun��o recebe: � v: vetor de n�meros inteiros; � n: a quantidade de elementos
/// do vetor v; � min: valor m�nimo a ser buscado; � max: valor m�ximo a ser buscado; A
/// fun��o deve: � Verificar a quantidade de elementos do vetor que sejam maiores do
/// que min e menores que max; � Caso a quantidade seja maior do que 0 (zero), alocar
/// dinamicamente uma �rea do exato tamanho necess�rio para armazenar os valores; �
/// Copia os elementos do vetor que sejam maiores do que min e menores que max para a
/// �rea alocada dinamicamente. A fun��o retorna: � O endere�o da �rea alocada
/// dinamicamente, preenchida com os n�meros maiores do que min e menores que max,
/// ou NULL, caso essa rela��o de n�meros n�o tenha sido criada; � A quantidade de
/// n�meros carregados na �rea alocada dinamicamente, atrav�s do par�metro qtd. Em

/// seguida, crie a fun��o principal do programa para inicializar um vetor de inteiros, exibir
/// esses valores na tela e pedir para o usu�rio digitar o valor m�nimo e m�ximo a ser
/// buscado. Em seguida o programa dever� chamar a fun��o valores_entre e exibir na
/// tela os valores resultantes. Lembre-se de exibir uma mensagem de erro caso nenhum
/// valor seja encontrado. N�o se esque�a de liberar a mem�ria alocada dinamicamente.

#include <stdio.h>

int* valores_entre(int* v, int n, int min, int max, int* qtd);

int main()
{
    int n, min, max, i, cont;
    int* qtd;
    int* NovoVetor;

    printf("Informe a quantidade de elemntos a serem lidas: ");
    scanf("%d", &n);

    int* v = (int*)malloc((sizeof(int))*n);

    for(i = 0; i < n; i++){
        printf("Informe o %do inteiro: ", i+1);
        scanf("%d", &v[i]);
    }
    printf("\n");
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n\n");

    printf("Digite o valor minimo a ser buscado: ");
    scanf("%d", &min);
    printf("Digite o valor maximo a ser buscado: ");
    scanf("%d", &max);

    NovoVetor = valores_entre(v, n, min, max, qtd);

    free(v);
    //cont = *qtd;

    if(NovoVetor != NULL){
        printf("\nValores resultantes:\n");
        //for(i = 0; i < cont; i++){
        for(i = 0; i < (int*)qtd; i++){         //Ainda n ta funcionando, e deveria ser? *qtd
            printf("%d ", NovoVetor[i]);
        }

        free(NovoVetor);
    }
    else
        printf("ERRO: Nenhum valor encontrado\n");

    return 0;
}

int* valores_entre(int* v, int n, int min, int max, int* qtd){
    int i, j=0, cont=0;
    int* NovoVetor;
    qtd = &cont;

    for(i = 0; i < n; i++){
        if((v[i]) > min){
            if((v[i]) < max){
                cont++;
            }
        }
    }

    if(cont > 0){
        NovoVetor = (int*)malloc((sizeof(int))*cont);

        for(i = 0; i < n; i++){
            if(v[i] > min){
                if(v[i] < max){
                    NovoVetor[j++] = v[i];
                }
            }
        }

    return NovoVetor;
    }
    else
        return NULL;
}
