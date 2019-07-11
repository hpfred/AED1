#include <stdio.h>
#include <stdlib.h>

const int MAX =	 10;

struct Aluno {
	int ra;
	char nome[20];
};

struct Pilha {
	struct Aluno alunos[10];
	int topo;
	int base;
	int limite;	
};

void Reset(struct Pilha *p) {
	p->topo = 0;
	p->base = 0;
	p->limite = MAX;	
}		

int Empty(struct Pilha *p) {
	return p->topo == 0;
}	

int Full(struct Pilha *p) {
	return p->topo == MAX;	
}	

int Push(struct Pilha *p, struct Aluno *item) {
	
	if (!Full(p)) {
		p->alunos[p->topo] = *item;
		p->topo++;
		return 1;	
	}		
	else {
		return 0;	
	}	
		
}	
int Pop(struct Pilha *p, struct Aluno *item) {
	
	if (p->topo == 0) {
		printf("\nA pilha esta vazia!\n");
		return 0;	
	}	
	else {
		p->topo--;
		*item = p->alunos[p->topo];	
		return 1;
	}	
}	
void Listar(struct Pilha *p) {
	
	if (Empty(p)) {
		printf("\nA pilha está vazia!\n");	
	}	
	else {
		printf("\nListando...\n");
		while (!Empty(p)) {
			struct Aluno aluno;
			Pop(p, &aluno);
			printf("\nNome aluno: %s\nIdade aluno: %d\n", aluno.nome, aluno.ra);	
		}
		Reset(p);	
	}	
}


int main () {

	struct Pilha pilha;
	int resposta;
	
	struct Aluno a;
	
        Reset(&pilha);
        
	while (resposta !=  4) {
		printf("[0] Insere pessoa\n[1] Deleta pessoa do topo\n[2] Limpa pilha\n[3] Listar\n[4] Sair\n");
		scanf("%d", &resposta);	
		
		switch (resposta) {
			
			case 0:
				printf("Nome: ");
				scanf("%s", a.nome);
				printf("Idade: ");
				scanf("%d", &a.ra);
				if (Push(&pilha, &a)) {
					printf("\n\nInserido com sucesso!\n\n");	
				}	else {
					printf("Falha ao inserir!\n");	
				}	
				break;
			case 1:
				if (Pop(&pilha, &a)) {
					printf("\n\n Pessoa do topo deletada com sucesso!\n\n");	
				}		
				else {
					printf("\n\n Falha ao deletar pessoa do topo. \n\n");	
				}	
				break;
			case 3:
				Listar(&pilha);
				break;	
			case 2:
				Reset(&pilha);
				break;	
			
		}	
	}	


}
