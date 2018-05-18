#include <stdlib.h>
#include <stdio.h>
#include <string.h>/*para usar a função strcpy() que é invocada no exercicio 2 b)*/
#include "estruturas.h"
#include "ficha7_funcoes.h"



/*Funções extra*/
void printLINTS(LInt l){
LInt *aux = l;
	if(!(*aux)){
		printf("Lista vazia!\n");
		getchar();
		exit(1);
	}else{
		while((*aux)->prox!=NULL){
			printf("%d ->",(*aux)->valor);
			aux = &((*aux)->prox);
		}
	}
}


int lengthLINT(LInt l){
LInt *aux = l;
int count = 0;

	while(!aux){ //aux !=Null ----CONFIRMAR SE AUX É QUE APONTA PARA NULL OU SE É *AUX
		count++;
		aux = &((*aux)->prox);
	}
return count;
}




/*Exercicio 1*/
//a)
LInt myCons(LInt l,int x){
LInt new = malloc(sizeof(struct slist));

	if(!new){
		printf("Erro de alocação de memoria!\n");
		getchar();
		exit(1);
	}

	new->valor=x;
	new->prox=l;
return new;
}

//b)
LInt myTail(LInt l){
LInt *aux = l;

	if((*aux)->prox==NULL){
		free(l);
	}else{
		l=l->prox;
		free((*aux));
	}

	return l;
}

//c)
LInt myInit(LInt l){
LInt *aux=l;

	if((*aux)->prox==NULL){
		free((*aux));
	}else{
		while((*aux)->prox!=NULL){
			aux=&((*aux)->prox);
		}
		free(*aux);
	}
	return l;
}



//d)
LInt mySnoc(LInt l,int x){
LInt *aux = l;

LInt new = malloc(sizeof(struct slist));
new->valor = x;
new->prox=NULL;

	while((*aux)->prox!=NULL){
		aux = &((*aux)->prox);
	}
	(*aux)->prox=new;

return l;
}



//e)
LInt myConcat(LInt a,LInt b){
LInt *pB;
*pB = b;

	while((*pB)->prox!=NULL){
		a = mySnoc(a,(*pB)->valor);
		pB = &((*pB)->prox);
	}
	return a;
}


