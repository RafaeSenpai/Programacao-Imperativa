#include <stdio.h>



typedef struct lligada {
	int valor;
	struct lligada *prox;
} *LInt;



/*Exercicio 1*/
//https://codeboard.io/projects/16161
/*Usando um LInt auxiliar para se deslocar pela lista sem perder a mesma*/

int lengthL (LInt l){
int count =0;
LInt aux = l;
	
	while(aux){
		count++;
		aux=aux->prox;
	}
	return count;

}

/*Usando um apontador para LInt para se deslocar pela lista sem perder a mesma*/
int lengthL (LInt l){
int count =0;
LInt *aux = &l;
	
	while(*aux){
		count++;
		aux=&((*aux)->prox);
	}
	return count;
}




/*Exercicio 2*/ //---------------------------------------------------------------------------------------CONFIRMAR SE ESTÁ CORRETO
void freeL(LInt l){
LInt *aux = &l;
LInt *ant;

	while(*aux){
		*ant = *aux;
		free(*aux);
		aux = &((*ant)->prox);
	}
}




/*Exercicio 3*/
void imprimeL(LInt l){
LInt *aux = &l;

	while(*aux){
		printf("%d\n",(*aux)->valor);
		aux = &((*aux)->prox);
	} 
}


/*Exercicio 4*/ //----------------FUNCIONAL 10/10
int lengthL (LInt l){
int count =0;
LInt *aux = &l;
	
	while(*aux){
		count++;
		aux=&((*aux)->prox);
	}
	return count;
}

int getValor_and_Swap(LInt l, int i, int x){
LInt *aux = &l;
int tmp;
	
	while(i>0){
		aux=&((*aux)->prox);
		i--;
	}
	
	tmp=(*aux)->valor;
	(*aux)->valor = x;
	
	return tmp;
}



LInt reverseL (LInt l){
LInt *aux = &l;
int ind,tam;
tam = lengthL(l);


	for(ind=1; ind<=(lengthL(l)/2);ind++){
		(*aux)->valor = getValor_and_Swap(l,tam-ind,(*aux)->valor);//getValor_and_Swap(lista,indice do valor a ser devolvido pela função, valor a colocar no indice)
		aux = &((*aux)->prox);
	}
	return l;
}


/*Exercicio 4*/ //-------------------------FUNCIONAL 10/10 (Solução mais indicada)
LInt reverseL2(LInt l){
LInt anterior = NULL;
LInt atual = l;
LInt seguinte;

	while(atual){
		seguinte = atual->prox;
		atual->prox = anterior;
		anterior = atual;
		atual = seguinte; 
	}
	l = anterior;

return l;
}

/*Exercicio 5*/ //----------------------------------------------------------------------------ACERTA APENAS EM UM TESTE!
void insertOrd (LInt *l, int x){
LInt *aux = l;
LInt ant = NULL;
LInt new = malloc(sizeof(struct lligada));

    new->valor = x;

	if((*aux) == NULL){ //caso a lista seja vazia o elemento a inserir será a cabeça
		new->prox = NULL;
		(*aux) = new;
	}else{
		while((*aux)->valor<x && (*aux)->prox!=NULL){ //enquanto nao encontrar posição na lista vai avançando e para quando chegar ao ultimo elemento da lista
			ant = (*aux);
			aux = &((*aux)->prox);
		}
        if(ant==NULL){//caso seja inserido na cabeça de uma lista não vazia
            new->prox = (*aux);
        }
		if((*aux)->prox != NULL){//caso a posição seja encontrada a meio da lista
			new->prox = (*aux);
			ant->prox = new;
		}else{//caso seja a ultima psição da lista, i é, o elemento será inserido no final da lista!
			new->prox = NULL;
		}
	}
}

void insertOrd (LInt *l, int x){//_-----------------------FUNCIONA 10/10
LInt *aux = l;
LInt new = malloc(sizeof(struct lligada));

    while((*aux) && (*aux)->valor<x){
    	aux = &((aux)->prox);
    }

    new->valor = x;
    new->prox = *aux;
    *aux = new;
} 



/*Exercicio 6*/
int removeOneOrd(LInt *l,int x){ //-----------------------------------------------------------SÓ PASSA EM APENAS 3 TESTES
LInt *p = l;
LInt ant = NULL;
int r=1;

	if(!(*p)){
		r = 1;
	}else{
		while((*p)->valor!=x && (*p)){ //enquanto não encontrar um valor igual e não for final da lista
			ant = (*p);
			p=&((*p)->prox);
		}
		if(ant==NULL && (*p)->prox!=NULL){//caso o elemento a remover seja encontrado logo no inicio da lista
			ant = (*p);
			p=&((*p)->prox);
			free(*p);
			r=0;
		}else if(ant==NULL && (*p)->prox==NULL){//caso seja encontrado no inicio da lista e a lista em questão só tenha 1 elemento
		    free(*p);
		    (*p)=NULL;
		    r=0;
		}
		if(*p){//se (*p) não é nulo é porque encontrou o valor igual no interior da lista
			ant->prox = (*p)->prox;
			free(*p);
			r=0;
		}
	}
	return r;
}


int removeONeOrd(LInt *l,int x){ //-------------FUNCIONA 10/10
int r=1;
LInt *aux = l;
LInt tmp;

	while((*aux) && (*aux)->valor!=x){
		aux = &((*aux)->prox);
	}

	if((*aux)){			//a condição tem que ser esta pois se fosse feito (*aux)->valor<x, iria existir a probabilidade de a procura chegar ao 
		tmp = (*aux);	//fim da lista e o (*aux)->valor nao pode ser verificado, pois (*aux) seria NULL e ao fazer a verificação de ((*aux)->valor<x)
		free(*aux);		//ia dar segmentation fault
		(*aux) = tmp;
		r = 0;
	}
	return r;
}

/*Exercicio 7*/ //-----------------------------FUNCIONA 10/10
void merge (LInt *r, LInt a, LInt b){
    
    while(a||b){
        if(!a&&b){
            while(b){
                *r = b;
                r= &((*r)->prox);
                b = b->prox;
            }
        }else if(a && !b){
            while(a){
                *r = a;
                r = &((*r)->prox);
                a = a->prox;
            }
        }else if(a->valor < b->valor){
            *r=a;
            r=&((*r)->prox);
            a = a->prox;
        }else{
            *r = b;
            r = &((*r)->prox);
            b = b->prox;
        }
    }
}



/*Exercicio 8*/ //-----------------------------FUNCIONA 10/10
void splitQS (LInt aux, int x, LInt *mx, LInt *Mx){
 LInt l = aux; 
   while(l){
       if(l->valor<x){
           *mx=l;
           mx=&((*mx)->prox);
       }
       else{
            *Mx=l;
            Mx=&((*Mx)->prox);
       }
       l=l->prox;
   }
   *mx=NULL;
   *Mx=NULL;
}

/*Exercicio 9*/ //----------------------------------------NAO TEM COMO TESTAR
LInt parteAmeio (LLig *l){
LInt *aux = l;
LInt y;
int tam = lengthL(*aux);

	for(i=0; i<=(lengthL(*aux)/2);i++){
		y = newLInt((*aux)->valor,y);
		aux=&((*aux)->valor);
	}

return y;
}

/*Exercicio 10*/ //-----------------FUNCIONAL 10/10
int removeAll (LInt *l, int x){
LInt *aux = l;
LInt nodoSeguinte;
int count = 0;

    while(*aux){
        if((*aux)->valor == x){
            nodoSeguinte = (*aux)->prox;
            free(*aux);
            (*aux) = nodoSeguinte;
            count++;
        }else{
            aux = &((*aux)->prox);
        }
    }
    return count;
}



/*Exercicio 12*/ //-------------------FUNCIONAL 10/10

int maiorL(LInt *l){
LInt *aux = l;
int max = (*aux)->valor;

	while(*aux){
		((*aux)->valor>max)?(max = (*aux)->valor):(max);
		aux = &((*aux)->prox);
	}
	return max;
}


int removeMaiorL(LInt *l){
LInt *aux = l;
LInt nodoSeguinte = NULL;
int max = maiorL(aux);
int flag=0;

	while(flag!=1){
		if((*aux)->valor==max){
			nodoSeguinte = (*aux)->prox;
			free(*aux);
			(*aux) = nodoSeguinte;
		    flag=1;
		}
		aux = &((*aux)->prox);
	}
return max;
}


/*Exercicio 13*/
void init (LInt  *l){
LInt *aux = l;

	while((*aux)->prox){
		aux = &((*aux)->prox);
	}
	free(*aux);
}


/*Exercico 14*/ //----------------------FUNCIONAL 10/10

void appendL (LInt *l, int x){
LInt *aux =l;
LInt new = malloc(sizeof(struct lligada));

    new->valor = x;
    new->prox = NULL;
    
    if(!(*aux)){
        (*aux)=new;
    }else{
        while((*aux)->prox){
            aux = &((*aux)->prox);
        }
        (*aux)->prox = new;
    }
}



/*Exercicio 15*/
void concatL (LInt *a, LInt b){
   while(*a){
       a=&((*a)->prox);
   }
   *a=b;
}

/*Exercicio 17*/ //------------------NÃOT TEM COMO VERIFICAR -- MAS O PROCESSO DE REVERSE ESTÁ CORRETO
LInt cloneRev(LInt l){
LInt clone = cloneL(l);
LInt atual = clone;
LInt seguinte;
LInt anterior = NULL;

	while(atual){
		seguinte = atual->prox;
		atual->prox = anterior;
		anterior = atual;
		atual = seguinte; 
	}
	l = anterior;
	return l;
}



/*Exercicio 18*/
int maximo(LInt l){
LInt aux = l;
int max = aux->valor;

	while(aux){
		(aux->valor>max)?(max = aux->valor):(max);
		aux = aux->prox;
	}
	return max;
}



/*Exercicio 19*/ //-------------------------FUNCIONAL 10/10

int take (int n, LInt *l){
LInt *aux = l;
LInt *seguinte;
int tam = 0;

    while(n>0 && (*aux)){
        aux = &((*aux)->prox);
        n--;
        tam++;
    }
    
    if(n==0){
        while(*aux){
            *seguinte = (*aux)->prox;
            free(*aux);
            (*aux) = (*seguinte);
        }
        return tam;
    }else{
        return lengthL(*l);
    }
}

/*Exercicio 20*/

int drop(int n,LInt *l){
LInt *aux = l;
LInt *next;
int nRem = 0;

	while((*aux) && n>0){
		next = &((*aux)->prox);
		free(*aux);
		(*aux) = (*next);
		n--;
		nRem++;
	} 
	return nRem;
}



/*Exercicio 21*/ //----------------FUNCIONAL 10/10
LInt NForward (LInt l, int N){
LInt aux = l;

	while(N>0){
		aux = aux->prox;
		N--;
	}
	
	return aux;
}


/*Exercicio 22*/ //------------------------FUNCIONAL 10/10
int listToArray (LInt l, int v[], int N){
LInt aux = l;
int i = 0;

    while(aux && i<N){
        v[i] = aux->valor;
        aux = aux->prox;
        i++;
    }
    return i;
}

/*Exercicio 23*/
LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

LInt arrayToList (int v[], int N){
LInt lst=NULL;
int i;

	while(N>0){
        lst = newLInt(v[N-1],lst);
        N--;
	}

	return lst;
}


/*Exercicio 24*/ //--------------------FUNCIONAL 10/10
LInt adicionaL(int x,LInt l){
LInt head = l;
LInt new = malloc(sizeof(struct lligada));

	if(l){
		while(l->prox){
			l = l->prox;
		}
		new->valor = x;
		new->prox = NULL;
		l->prox = new;
	}else{
		new->valor = x;
		new->prox = NULL;
		head = new;
	}
	return head;
}

LInt somaAcL(Lint l){
LInt aux = l;
LInt lst = NULL;
int v = 0;

	while(aux){
		v += aux->valor;
		lst = adicionaL(v,lst);
		aux = aux->prox;
	}
	return lst;
}

/*2º versão - mais aconcelhada*/ //----------------FUNCIONAL 10/10
LInt somasAcL (LInt l) {
    LInt res, *aux=&res;
    int soma=0;
    while(l){
        soma+=l->valor;
        *aux = malloc (sizeof( struct lligada ));
        (*aux)->valor = soma;
        aux=&((*aux)->prox);
        l=l->prox;
    }
    *aux = NULL;

    return res;
}

/*Exercicio 25*/ //----------------------------------FUNCIONAL 10/10

void remreps (LInt l){
LInt *aux = &l;
LInt *seguinte;
int val;

    while(*aux){
        val = (*aux)->valor;
        aux = &((*aux)->prox);
        while((*aux) && (*aux)->valor==val){
            seguinte = &((*aux)->prox);
            free(*aux);
            (*aux) = (*seguinte);
        }
    }
}



/*Exercicio 26*/ //-----------------------------FUNCIONAL 10/10
LLInt rotateL(LInt l){
LInt *list = &l;
LInt *seg;
int tmp;

    while(*list && (*list)->prox!=NULL){
        seg = &((*list)->prox);
        tmp = (*list)->valor;
        (*list)->valor = (*seg)->valor;
        (*seg)->valor = tmp;
        list = &((*list)->prox);
    }
    return l;
}


/*Exercicio 27*/ //----------------------------FUNCIONAL** 2/10
LInt insere(int x,LInt l){
LInt *aux = &l;
LInt new = malloc(sizeof(struct lligada));

	if(*aux==NULL && new){
		new->valor = x;
		new->prox = NULL;
		(*aux) = new;
	}else{
		while((*aux)->prox!=NULL){
			aux = &((*aux)->prox);
		}

		new->valor = x;
		new->prox = NULL;
		(*aux)->prox = new;
	}
	return l;
}

LInt parte (LInt l){
LInt *lst = &l;
LInt impares = NULL;
LInt pares = NULL;

	while(*lst){
		impares = insere((*lst)->valor,impares);
		lst = &((*lst)->prox);
		if(*lst!=NULL){
			pares = insere((*lst)->valor,pares);
			lst = &((*lst)->prox);	
		}
	}
	free(*lst);
	lst=&impares;
	return pares;
}