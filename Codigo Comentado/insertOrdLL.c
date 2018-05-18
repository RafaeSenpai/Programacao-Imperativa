#include <stdio.h>
#include <stdlib.h>



typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;


LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

/*
void insertOrd(LInt *l, int x){
	
	while((*l)){
		if(&(*l) <= x){
			(*l) = (*l) -> prox;
		}else{
			newLInt(x,(*l));
		}
	}
}
*/
void insertOrd(LInt *l, int x){
	LInt *aux = l;

	while((*l)!=NULL){
		if(x<=((*l)->valor)){
			(*l)=(*l)->prox;
		}else{
			LInt novo = (LInt) malloc (sizeof (LInt));
			(*l) -> prox = novo;
			novo->valor=x;
			novo->prox = (*l);
		}
	}
}



void imprimeLista(LInt l){
	if(l==NULL){
		printf("A lista encontra-se vazia!\n");
	}else{
		while(l){
			printf("%d",l->valor);
			l = l->prox;
		}
	}
}



int main(){
	int x, val;
	LInt l={12,newLInt(14,newLInt(1),NULL)};
	printf("1- Inserir um valor na lista ordenada;\n2-Imprimir a lista ligada ordenada;");
	scanf("%d",&x);
	switch(x){
		case 1:
			printf("Inisra o valor a colocar na lista ordenada:\n");
			scanf("%d",val);
			insertOrd(l, val);
		default:
			printf("Lista:\n");
			imprimeLista(l);
	}
}
