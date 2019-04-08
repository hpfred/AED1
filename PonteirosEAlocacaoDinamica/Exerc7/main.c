/// 7) Crie um programa para manipular vetores. O seu programa deve implementar uma
/// função que receba um vetor de inteiros V e retorne um outro vetor de inteiros alocado
/// dinamicamente com todos os valores de V que estejam entre o valor mínimo e
/// máximo (que também são passados como parâmetro para a função). A função deve
/// obedecer ao seguinte protótipo: int* valores_entre(int *v, int n, int min, int max, int
/// *qtd); A função recebe: • v: vetor de números inteiros; • n: a quantidade de elementos
/// do vetor v; • min: valor mínimo a ser buscado; • max: valor máximo a ser buscado; A
/// função deve: • Verificar a quantidade de elementos do vetor que sejam maiores do
/// que min e menores que max; • Caso a quantidade seja maior do que 0 (zero), alocar
/// dinamicamente uma área do exato tamanho necessário para armazenar os valores; •
/// Copia os elementos do vetor que sejam maiores do que min e menores que max para a
/// área alocada dinamicamente. A função retorna: • O endereço da área alocada
/// dinamicamente, preenchida com os números maiores do que min e menores que max,
/// ou NULL, caso essa relação de números não tenha sido criada; • A quantidade de
/// números carregados na área alocada dinamicamente, através do parâmetro qtd. Em

/// seguida, crie a função principal do programa para inicializar um vetor de inteiros, exibir
/// esses valores na tela e pedir para o usuário digitar o valor mínimo e máximo a ser
/// buscado. Em seguida o programa deverá chamar a função valores_entre e exibir na
/// tela os valores resultantes. Lembre-se de exibir uma mensagem de erro caso nenhum
/// valor seja encontrado. Não se esqueça de liberar a memória alocada dinamicamente.

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
