#include <stdlib.h>
#include <stdio.h>
#include <string.h>/*para usar a função strcpy() que é invocada no exercicio 2 b)*/
/*EStrutura de dados usada para o exercico 1*/
typedef struct slist *LInt;

typedef struct slist {
	int valor;
	LInt prox;
} Nodo;



/*Estrutura usada para o exercio 2*/
/*Exercicio2 a)*/
typedef struct aluno *Turma;

typedef struct aluno {
	char nome[60];
	int numero;
	float nota;
	Turma prox;
} Aluno;




Turma t = NULL;
/*DADOS USADOS NA OPÇÃO - EXTRA - DO MENU*/
Turma teste;
Aluno novo1;
Aluno novo2;
/*---------------------------------------*/



/*função auxiliar - impressão da lista ligada!*/
void printLInt(LInt x){
LInt temp = x;
	
		while(temp!=NULL){
			if(temp->prox!=NULL){
				printf("%d -> ", temp->valor);
				temp = temp->prox;
			}else{
				printf("%d\n",temp->valor);
				temp=temp->prox;
			}
		}
}



/*Exercicio1 a)*/
LInt cons(LInt l, int x){
LInt new = malloc(sizeof(struct slist));

	if(!new){
		printf("Erro de alocação de memória!\n");
		return 0;
	}

	new->valor=x;
	new->prox=l;

	return new;
}



/*Exercicio1 b)*/
LInt mytail(LInt l){
LInt cabeca;

	cabeca = l->prox;
	free(l);
	l=cabeca;
	return l;
}

/*Exercicio1 c)*/
LInt myinit(LInt l){
LInt tmp=l;

	while(tmp->prox!=NULL){
		tmp=tmp->prox;
	}
	free(tmp);

return l;
}

/*Exercicio1 d)*/
LInt mysnoc(LInt l, int x){
LInt anterior=NULL;
LInt aux=NULL;
aux = l;
LInt new = malloc(sizeof(struct slist));
	
	if(!new){
		printf("Erro de alocação de memória!\n");
		return 0;
	}

	new->valor = x;
	new->prox = NULL;

	if(aux==NULL){
		l=new;
		return l;
	}else{
		while(aux!=NULL){
			anterior=aux;
			aux=aux->prox;
		}
		anterior->prox = new;
	}
return l;
}

/*exercicio1 e)*/
LInt myconcat(LInt a, LInt b){
LInt aux = a;

	while(aux->prox!=NULL){
		aux = aux->prox;
	}
	aux->prox = b;

	return a;
}

//----------------função auxiliar para a 2º versão do myconcat-----------------
LInt newLInt(LInt l, int x){
LInt aux = l;
LInt new = malloc(sizeof(struct slist));

	if(!new){
		printf("Erro de alocação de memoria!\n");
	}else{
		new->valor = x;
	}

	if(aux==NULL){
		new->prox=NULL;
		l=new;
		return l;
	}else{
		while(aux->prox!=NULL){
			aux=aux->prox;
		}
		aux->prox=new;
		new->prox=NULL;
		return l;
	}
}

LInt myconcat2(LInt a, LInt b){
LInt auxA = a;
LInt auxB = b;

	while(auxA->prox!=NULL){
		auxA=auxA->prox;
	}
	auxA->prox=auxB;
	if(auxB!=NULL){
		while(!auxB){
			auxA=newLInt(auxA,auxB->valor);
			auxB=auxB->prox;
		}
		auxA->prox=NULL;
	}
	return a;
}

/*Função auxiliar de impressão de uma turma*/
void printTurma(Turma t){
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
/*Exercicio 2b)*/
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



/*Exercicio 2c)*/
Aluno *procura(Turma t, int num){
Turma aux=t;

	if(aux==NULL){
		return NULL;
	}else{
		while(aux){
			if(aux->numero==num){
				return aux;
			}else{
				aux=aux->prox;
			}
		}
	}
	return NULL;	
}


/*Função auxiliar de impressão de ficha de um aluno*/
void printFichaAluno(Aluno a){ //as setas usam-se para apontadores que apontam para structs, os pontos usam-se para structs
	printf("Nome: %s\n",a.nome);
	printf("Numero: %d\n",a.numero);
	printf("Nota: %f\n",a.nota);
}

/*Exercicio 2d)*/
int numAprovados(Turma t){
Turma aux = t;
int count=0;

	if(!aux){
		return 0;
	}else{
		while(aux){
			if(aux->nota>=10){
				count++;
			}
			aux=aux->prox;
		}
	}
return count;
}



