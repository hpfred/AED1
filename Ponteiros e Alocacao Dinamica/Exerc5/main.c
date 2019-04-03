/// Criar um tipo abstrato de dados que represente uma pessoa, contendo nome, data de
/// nascimento e CPF. Crie uma variável que é um ponteiro para este TAD (no programa
/// principal). Depois crie uma função que receba este ponteiro e preencha os dados da
/// estrutura e também uma uma função que receba este ponteiro e imprima os dados da
/// estrutura. Finalmente, faça a chamada a esta função na função principal.

#include <stdio.h>

typedef struct{
    char nome[30];
    int data[3];
    char cpf[11];
}pessoa;


//typedef pessoa;

preenche();
imprime();

int main(){
    pessoa *aluno = malloc(sizeof(pessoa));
    //struct pessoa *aluno;

    preenche(aluno);
    imprime(aluno);

    return 0;
}


preenche(pessoa *aluno){
    printf("Informe o nome: ");
    scanf("%s",aluno->nome);
    printf("Informe a data de nascimento: ");
    scanf("%d %d %d",&aluno->data[0], &aluno->data[1], &aluno->data[2]);
    printf("Informe o CPF: ");
    scanf("%s", aluno->cpf);

    return;
}

imprime(pessoa *aluno){
    printf("Nome: %s\n", aluno->nome);
//    fgets(aluno->nome,30,stdin);
    printf("Data de Nascimento: %2d/%2d/%4d\n", aluno->data[0], aluno->data[1], aluno->data[2]);
    printf("CPF: %s\n", aluno->cpf);


    return;
}
