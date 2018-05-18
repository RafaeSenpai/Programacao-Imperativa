#include <stdio.h>
#include <stdlib.h>

#define BSize 100
typedef struct larray{
	int valores[BSize];
	struct larray *prox;
} *LArrays;

typedef struct stack{
int sp;
LArrays s;
} Stack;


//-______________________________________


typedef struct slist {
	int valor;
	struct slist *prox;
} *LInt;

//_______________________________________
typedef struct spares {
	int x, y;
	struct spares *prox;
} Par, *LPares;

typedef struct slist {
	int valor;
	struct slist *prox;
} Nodo, *LInt;


//_______________________________________



LInt fromArray(int v[], int N){
	LInt lista,inicio;
	lista = (LInt) malloc(sizeof (struct slist));
	inicio = lista;

	for(int x =0; x<N; x++){
		lista->valor = v[x];
		lista->prox = (LInt) malloc(sizeof(struct slist));
		lista = lista->prox;
	}

	return inicio;
}


void mypush (Stack *st, int x){

	if(st == NULL){
		Stack *pilha = (Stack *) malloc(sizeof(struct stack));
		pilha->sp = 0;
		pilha->s = (LArrays) malloc (sizeof(struct larray));
		pilha->s->valores[pilha->sp] = x;
		pilha->sp++;
		st = pilha;
	}else{
		if(st->sp<100){
			LArrays val = st->s;
			while(val->prox != NULL){
				val = val->prox;
			}
			val->valores[st->sp] = x;
			st->sp++;
		}else{
			LArrays val = st->s;
			while(val->prox!=NULL){
				val=val->prox;
			}

			LArrays newNodo = (LArrays) malloc(sizeof(struct larray));
			st->sp = 0;
			newNodo->valores[st->sp] = x;
			st->sp++;
			val->prox = newNodo;
		}
	}
}








int main(){
	int v[5] = {1,2,3,4,5};
	LInt estrutura = (LInt) malloc(sizeof(struct larray));	

	Stack* pilha;


	estrutura = fromArray(v,5);

	while(estrutura->prox!=NULL){
		printf("%d - ",estrutura->valor);
		estrutura = estrutura->prox;
	}

	mypush(pilha,999);



}