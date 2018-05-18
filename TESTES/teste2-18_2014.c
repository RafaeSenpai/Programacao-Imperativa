#include <stdio.h>
#include <stdlib.h>

typedef struct slist{
	int valor;
	struct slist *prox;
}*LInt;



#define BSize 100
typedef struct larray{
	int valores[BSize];
	struct larray *prox;
} *LArrays;

typedef struct stack{
int sp;
LArrays s;
} Stack;




void imprimeLista(LInt *lst){
	LInt *l = lst;

	if(!*l){
		printf("Lista Vazia!\n");
	}else{
		printf("\n\n");
		while(*l){
			printf("%d--| ", (*l)->valor);
			l= &((*l)->prox);
		}
		printf("\n\n");
	}
}



LInt criaNodo(int valor, LInt seg){
LInt novo = (LInt) malloc (sizeof(struct slist));
	
	if(novo==NULL){
		return NULL;
	}

	novo->valor = valor;
	novo->prox = seg;
	return novo;
}



void adicionaNodo(LInt *l, int valor){
LInt *aux = l;

	while((*aux)!=NULL && (*aux)->valor <valor){ //procura o local onde inserir, mas se for imediatamente nulo salta logo fora
		aux = &((*aux)->prox);
	}

	if((*aux)==NULL){ //no caso de ser imediatamente nulo ou a colocação for feita no final da lista
		(*aux) = criaNodo(valor,(*aux));

	}else{//no caso de ser um elemento a meio da lista
		LInt seguinte = (*aux); //1º guarda o nodo em seguinte pois verificou-se que o nodo tem um valor maior do que se quer inserir
		(*aux) = criaNodo(valor,seguinte);//2º cria-se um novo nodo com o valor a inserir e liga-se ao seguinte anterirormente guardado em "seguinte"

	}

}

/**Exercicio 1*/
LInt fromArray(int v[], int N){
LInt lst = NULL;

	for(int i=0; i<N; i++){
		adicionaNodo(&lst,v[i]);
	}

	imprimeLista (&lst);
return lst;
}


/**Exercicio 2*/
void insereValor(LArrays l,int x, int val){
	LArrays aux = l;
	if(x<BSize){
		while((l)){
			l = l->prox;
		}
		l->valores[x] = val;
	}else{
		x = 0;
		LArrays novo = (LArrays) malloc (sizeof(struct larray));
		novo->valores[x] = val;
		novo->prox = NULL;
		aux->prox = novo;
	}

}


void mypush(Stack *st, int x){

Stack aux = *st;

	if(aux==NULL){
		Stack pilha = (Stack) malloc (sizeof(struct stack));
		LArrays lstArrays = (LArrays) malloc (sizeof(struct larray));
		
		pilha->sp = 0;
		pilha->s = lstValores;
		lstArrays->valores[pilha->sp] = x;
		pilha->sp++;
		aux = pilha;
	}

	if(aux->sp < BSize){
		inserValor(pilha->s, pilha->sp, x);
		pilha->sp++;
	}else{
		inserValor(pilha->s, pilha->sp, x);
		pilha->sp = 0;
	}
}









int main(){

	int array[5] = {6,5,4,3,2};
	
	fromArray(array,5);


Stack* pilha;


	for(int t = 0; t<5; t++){
		mypush(pilha,t+2);
	}

}