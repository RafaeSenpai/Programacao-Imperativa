/*funções da ficha 7 exercicio 2*/
#include <stdio.h>
#include "estruturas.h"

void getFichaAluno(Aluno x){
	printf("Nome: %s\n",x.nome);
	printf("Numero: %d\n",x.numero);
	printf("Nota: %f\n",x.nota);
}





/*Função auxiliar de impressão de uma turma, RECEBENDO POR APONTADOR*/
void printTurma1(Turma *t){
Turma *aux = t;
	if(!(*aux)){
		printf("Turma vazia!\n");
		getchar();
	}else{
		while((*aux)->prox!=NULL){
			printf("Nome: %s\n",(*aux)->nome);
			printf("Nome: %d\n",(*aux)->numero);
			printf("Nome: %f\n",(*aux)->nota);
			printf("----------------------------\n");
			aux = &((*aux)->prox);
		}
		printf("Fim da turma!\n");	
	}
}



/*Função auxiliar de impressão de uma turma*/
void printTurma2(Turma t){
Turma aux2 = t;
	if(aux2==NULL){
		printf("Turma vazia!\n\n\n");
	}
	while(aux2){
		printf("Nome: %s\n",aux2->nome);
		printf("Numero: %d\n",aux2->numero);
		printf("Nota: %f\n",aux2->nota);
		printf("------------------------------\n");
		aux2=aux2->prox;
	}
}

int acrescentaAluno(Turma *t, Aluno a){
Turma *aux = t;

	if(!(*aux)){
		(*aux)=&a;
		return 0;
	}else{
		while((*aux)->prox){
			aux=&((*aux)->prox);
		}
		(*aux)->prox = &a;
		return 0;
	}
	return 1;
}



