#include <stdlib.h>

typedef struct slist{
	int valor;
	struct slist *prox;
}*LInt;

/*Questão 1*/
LInt addLInt(int x,LInt l){
LInt new = malloc(sizeof(struct slist));

	if(new){
		new->valor = x;
		new->prox = l;
	}
	return new;
}


LInt fromArray(int v[],int N){
LInt l = NULL;
int i;

	for(i=N; i>=0;i--){
		l = addLInt(v[i],l);
	}

	return l;
}


/*Questão 2*/
#define BSize 100;

typedef struct larray{
	int valores[BSize];
	struct larray *prox;
}*LArrays;

typedef struct stack{
	int sp;
	LArrays s;
}Stack;

void push(Stack *st,int x){

	if(*st){
		if((*st)->sp<BSize){
			(*st)->s->valores[(*st)->sp] = x;
			(*st)->sp++;
		}else{
			LArrays new = malloc(sizeof(struct larray));
			if(new){
				new->prox = (*st)->s;
				(*st)->sp = 0;
				new->valores = malloc((BSize-1) * sizeof((int)));
				new->valores[(*st)->sp] = x;
				(*st)->s = new;
			}
		}
	}
}


int pop(Stack *st,int *t){
int r = 1;

	if(*st){
		(*t) = (*st)->s->valores[(*st)->sp];
		(*st)->sp--;

		if((*st)->sp == 0){
			LArrays seguinte = NULL;
			free((*st)->s);
//			(*st)->s = NULL;
			(*st)->s = seguinte;
			(*st)->sp = BSize-1;
		}
		r = 0;
	}
	return r;
}


/*Questão 3*/
typedef struct spares{
	int x, y;
	struct spares *prox;
}Par, *LPares;

typedef struct slist{
	int valor;
	struct slist *prox;
}Nodo,*LInt;

LPares zip(LInt a, LInt b,int *c){
int count = 0;
LPares l;
LPares *p;
p = &l;

	while(a && b){
		l = malloc(sizeof(struct spares));
		l->x = a->valor;
		l->y = b->valor;
		l = l->prox;
		a = a->prox;
		b = b->prox;
		count++;
	}
	(*c) = count;

	return (*p);
}



/*Questão 4*/
#define N 3

typedef struct bloco{
	int quantos;
	int valores[N];
	struct bloco *prox;
}Bloco, *LBloco;


/*Alinea a)*/
int verifica(int v[], int val, int quantos){
int i,r;
r=0;
	for(i=0; i>quantos;i++){
		if(v[i]==val){
			r=1;
		}
	}
	return r;
}

int pretence(LBloco l,int x){
int r=0;
int i;

	if(l){
		while(l && r==0){
			r = verifica(l->valores,x,l->quantos);
			l=l->prox;
		}
	}
	return r;
}


/*Alinea b)*/
//------------(1)-----(2)----(3)-----(4)----------(5)
int *takeEXT(int x, int v[],int N,int valExt, int *dest){//acho que falta uma variavel que define o tamanho do array de destino
int i,j;
j=0;
(*dest) = malloc((x+1)*sizeof(int));
	
	if(dest){
		for(i=N-1,x>0,i--,x--,j++){
			dest[j] = v[i];
			free(v[i]);
			v[i] = NULL;
		}
		j++;
		dest[j]=valExt;
	}

return dest;
}

int acrescenta(LBloco *l, int n){
LBloco *aux = l;
LBloco *ant = NULL;
int *arrayAux;
int r = 1;

	if(*aux){
		while(*aux && (*aux)->quantos = N){
			*ant = aux;
			aux = &((*aux)->prox);
		}

		if(!(*aux)){
			LBloco new = malloc(sizeof(struct bloco));
			if(new){
				new->quantos = (n/2)+1;
				new->valores = takeEXT((n/2),(*ant)->valores,(*ant)->quantos,n,new->valores);
				new->prox = NULL;
				(*ant)->quantos = (n/2);
				(*aux) = new;
				r=0;
			}
		}else{
			if((*aux)->quantos<N){
				(*aux)->valores[(*aux)->quantos] = n;
				(*aux)->quantos++;
				r=0;
			}
		}
		return r;
	}
}