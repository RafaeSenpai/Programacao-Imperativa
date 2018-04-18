#include <stdio.h>
#include <stdlib.h>

/*Structs a baixo dizem respeito ás 50 segundas questões*/
typedef struct lligada{
	int valor;
	struct lligada *prox;
}*LInt;


/*cria um nodo*/
LInt criaNodo(){
LInt novo = malloc(sizeof(struct lligada));

	if(!novo){
		printf("Memória insuficiente!\n");
	}else{
		novo->prox=NULL;
	}

	return novo;
}


/*Cria uma lista ligada automaticamente*/
LInt criarLInt(){
LInt tmp = malloc(sizeof(struct lligada));
LInt novaLInt = tmp;

	for(int i=1;i<=6;i++){
		tmp->valor=i;
		tmp->prox = criaNodo();
		tmp=tmp->prox;
	}

	return novaLInt;

}




/*Imprime uma lista ligada (LInt)*/
void printLInt(LInt x){
LInt temp = x;
	
		while(temp->prox!=NULL){
				printf("%d -> ", temp->valor);
				temp = temp->prox;

		}
		printf("\nImpressão concluida!\n\n");	
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*Exercicio1 - Recurso a apontadores apenas --------------------------------------------REVER OS APONTADORES NESTA FUNÇÃO!*/
int myLength(LInt *l){
int count = 0;
LInt *aux;
aux = l;
	
	if((*aux)==NULL){
		return 0;
	}
	
	while((*aux)->prox!=NULL){
		count++;
		aux = &((*aux)->prox);
	}
	return count;

}

int swapLInt(int val,int pos,LInt l){/*leva um valor(val) para ser clocado numa posição(pos) e devolve o valor(aux->val) que se encontrava nessa mesma posição */
LInt aux = l;
int x=0;
int i;

	for(i=1;i<pos;i++){
		aux=aux->prox;
	}

	x=aux->valor;
	aux->valor=val;

	return x;
}


LInt reverseL(LInt l){
LInt aux=l;
int i,tam;
int val;
tam=myLength(&l);

	for(i=tam; i>(tam/2); i--){
		val = aux->valor;
		aux->valor = swapLInt(val,i,l); //o swap devolve o valor que foi substituido
		aux=aux->prox;
	}
	return l;
}



















int main(){
LInt lintPredefinida = criarLInt();

	printf("lISTA RECEBIDA:\n");
	printLInt(lintPredefinida);
	printf("Tamanho da lista: %d\n\n", myLength(&lintPredefinida));
	printf("REVERSE DA LISTA ANTERIOR:\n\n");
	printLInt(reverseL(lintPredefinida));	
	printf("SWAP da posição 3 pelo valor 9. Devolve o valor: %d\n\n\n",swapLInt(9,3,lintPredefinida));
	printLInt(lintPredefinida);

	return 0;
}