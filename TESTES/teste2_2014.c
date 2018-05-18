#include<stdio.h>
#include<stdlib.h>


typedef struct slist {
	int valor;
	struct slist *prox;
} *LInt;



LInt fromArray(int v[], int N){
LInt lista;
LInt inicio = lista;

	for(int i=0; i<=N; i++){
		lista = (LInt) malloc(sizeof(struct slist));
		lista->valor = v[i];
		lista = lista->prox;
	}
	lista->prox = NULL;

return inicio;
}


int main(){
 int array[5] = {1,2,3,4,5}; 	
	fromArray(array,5);


	return 0;
}