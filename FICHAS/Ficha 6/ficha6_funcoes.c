#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "ficha6_funcoes.h"



/*Exercicio 1 a)*/
void initStack(STACK *s){
	s->sp=-1;
}

/*Exercico 1 b)*/
int isEmptyS(STACK *s){

	if(s->sp==-1){
		return 0;
	}else{
		return 1;
	}
}

/*Exercicio 1 c)*/
int mypush(STACK *s, int x){
	if(s->sp <= MAX){
		s->sp++;
		s->valores[s->sp] = x;
		return 0;
	}
	return 1;
}

/*Exercicio 1 d)*/
int mypop(STACK *s, int *x){
	if(s->sp>-1){
		(*x) = s->valores[s->sp];
		s->sp--;
		return 0;
	}
	return 1;
}

/*Exercicio 1 e)*/
int mytop(STACK *s,int *x){
	if(s->sp>-1){
		(*x) = s->valores[s->sp];
		return 0;
	}
	return 1;
}


/*EXTRA - Imprime stack*/
void imprimeSTACK(STACK *s){
	printf("CONTEUDO DA STACK:\n");
	for(int i=0; i<= s->sp; i++){
		printf("%d\n",s->valores[i]);
	}
}




/*Exercicio2 a)*/
void initQueue(QUEUE *q){
	
	(*q).inicio = 0;
	(*q).tamanho = 0;
}

/*Exercicio2 b)*/
int isEmptyQ(QUEUE *q){
QUEUE aux = (*q);
	if(aux.tamanho==0){
		return 0;
	}
return 1;
}

/*Exercicio2 c) -- FIFO*/
int enqueue (QUEUE *q, int x){
QUEUE aux = (*q);

	if(aux.tamanho<MAX){
		aux.valores[aux.tamanho] = x;
		aux.tamanho++;
		return 0;
	}else{
		return 1;
	}
}

/*Exercicio2 d) -- FIFO*/
int dequeue(QUEUE *q, int  *x){
QUEUE aux = (*q);

	if(aux.tamanho==0){
		return 1;
	}else{
		(*x) = aux.valores[aux.inicio];
		aux.inicio++;
		aux.tamanho--;
		return 0;
	}
}

/*Exercicio2 e)*/
int frontQ(QUEUE *q, int *x){
QUEUE aux = (*q);

	if(aux.tamanho==0){
		return 1;
	}else{
		(*x)=aux.valores[aux.inicio];
		return 0;
	}
}

/*EXTRA - Impressão da QUEUE*/
void imprimeQUEUE(QUEUE *q){
QUEUE aux = (*q);
	
	if(aux.tamanho==0){
		printf("QUEUE vazia!\n");
	}else{
		printf("Conteudo da QUEUE:\n");
		for(int i=0;i<aux.tamanho;i++){
			printf("|%d\t|\n",aux.valores[i]);
		}
	}
}
