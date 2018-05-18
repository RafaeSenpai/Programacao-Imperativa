#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

// 1 Comprimento de uma lista ligada

int length (LInt l){
    int count = 0;
    
    if(l==NULL){
        return 0;
    }
    
    while(l!=NULL){
        count++;
        l = l->prox;
    }
    return count;
}

// 2 liberta uma lista

void freeL (LInt l){
	LInt *l1;

	while(l!=NULL){
		l1=&(l->prox);
		free(l);
		l=*l1;
	}
}

// 3 Imprime uma lista ligada

void imprimeL(LInt l){
	int i=0;

	while(l!=NULL){
		printf("Linha %d -> Valor %d ",i,l->valor);
		i++;
		l=l->prox;
	}
}

// 4 reverse uma lista ligada

LInt reverseL (LInt l){
	LInt l2,l1=NULL;
	while(l){
		l2=l->prox;
		l->prox=l1;
		l1=l;
		l=l2;
	}
	return l1;
}

// 5 insere uma elemento ordenado

void insertOrd (LInt *l, int x){
    LInt new;
    while(*l!=NULL && (*l)->valor < x){
        l=&((*l)->prox);
    }
    new = (LInt) malloc (sizeof (struct lligada));
    new->valor = x;
    new->prox = *l;
    *l = new;
}

// 6 remover ordenamente um elemnto

int removeOneOrd (LInt *l, int x){
    LInt p;
    int t=1;
    
    while(*l!=NULL && (*l)->valor!=x){
        l=&((*l)->prox);
    }
    if(*l!=NULL){
        p=(*l)->prox;
        free(*l);
        *l=p;
        t=0;
    }
    return t;
}

// 7 

void merge (LInt *r, LInt l1, LInt l2){
   while(l1 || l2){
       if((!l1)||(l2 && l1->valor>l2->valor))
       {
          *r=l2;
          r=&(l2->prox);
          l2=l2->prox;
          
       }else{
          *r=l1;
          r=&(l1->prox);
          l1=l1->prox;
       }
   }
}

// 8

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
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
   *mx=0;
   *Mx=0;
}

// 9

LInt parteAmeio (LInt *l){
    int j=length(*l)/2, i;
    LInt *p = l;
    r = *l;

    for(i=0;i<j;i++){
        p=&((*p)->prox);
        
    }
    *l=*p;
    *p=NULL;
    if (i==0) {
    	*l=r;
    	return NULL;
    }
    else return r;
 }

// 10

 int removeAll (LInt *l, int x){
    int i;
    LInt aux;
    while(*l){
        if((*l)->valor==x){
            aux = (*l)->prox;
            free(*l);
            *l=aux;
            i++;
        }
        else{
            l=&((*l)->prox);
        }
    }
    return i;
}


// 11

int removeDups (LInt *l){
   int i=0;
   while(*l){
       i+=removeAll(&((*l)->prox),(*l)->valor);
       l=&((*l)->prox);
   }
   return i;
}

// 12

int maior(LInt *l){ 
    int maior=(*l)->valor;
    while(*l){
        if(((*l)->valor)>maior){
            maior=(*l)->valor;
        }
        l=&((*l)->prox);
    }
    return maior;
}

void removeUm(LInt *l, int x){
    LInt aux;
    int flag=1;
    while(*l && flag){
        if((*l)->valor==x){
            aux=(*l)->prox;
            free(*l);
            flag=0;
        }
        else{
            l=&((*l)->prox);
        }
    }
    *l=aux;
}

int removeMaiorL (LInt *l){
    int m = maior(l);
    removeUm(l,m);
    return m;
}

// 13

void init (LInt *l){
   while((*l)->prox){
       l=&((*l)->prox);
   }
   if(*l){
       free(*l);
       *l=NULL;
   }
}

// 14

void appendL (LInt *l, int x){
    if(*l){
        LInt aux = *l;
         while(aux->prox){
            aux=aux->prox;    
        }
        aux->prox = (LInt) malloc (sizeof (struct lligada));
        aux->prox->valor = x;
        (aux->prox)->prox = NULL;
        
    }
    else{
        *l = (LInt) malloc (sizeof (struct lligada));
        (*l)->valor = x;
        (*l)->prox = NULL;
    }
}

// 15

void concatL (LInt *a, LInt b){
   while(*a){
       a=&((*a)->prox);
   }
   *a=b;
}

// 16

LInt cloneL (LInt l){
	LInt r, *e=&r;
	while(l){
		*e = malloc(sizeof(struct lligada));
		(*e)->valor = l->valor;
		l=l->prox;
		e=&((*e)->prox);
	}
	*e=NULL;
	return r;
}

// 17

LInt cloneRev (LInt l){
    LInt r=0,v=0;
    while(l){
        r=(LInt) malloc (sizeof (struct lligada));
        r->valor=l->valor;
        r->prox=v;
        v=r;
        l=l->prox;
    }
    return r;
}

// 18

int maximo(LInt l){ 
    int maior=l->valor;
    while(l){
        if((l->valor)>maior){
            maior=l->valor;
        }
        l=l->prox;
    }
    return maior;
}

//19

int take (int n, LInt *l){
    LInt aux;
    int i = 0;
    while(*l && i<n){
        l=&((*l)->prox);
        i++;
    }
    while(*l){
        aux = (*l)->prox;
        free(*l);
        *l=aux;
    }
    return i;
}

// 20

int drop (int n, LInt *l){
    LInt aux;
    int i=0;
    while(*l && i<n){
        aux = (*l)->prox;
        free(*l);
        *l=aux;
        i++;
    }
    return i;
}

// 21

LInt NForward (LInt l, int N){
    while(N>0){
        l=l->prox;
        N--;
    }
    return l;
}

// 22

int listToArray (LInt l, int v[], int N){   
    int i=0;
    while(l && i<N){
        v[i] = l->valor;
        l=l->prox;
        i++;
    }
    return i;    
}


// 23

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

LInt arrayToList (int v[], int N){
   LInt res=0;
   while(N>0){
       res = newLInt(v[N-1],res);
       N--;
   }
   return res;
}

// 24

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

// 25

void remreps (LInt l){
    LInt p,j;
    while(l){
        p=l->prox;
        
        while(p && l->valor==p->valor){
            j=p->prox;
            free(p);
            p=j;
        }

        l->prox=p;
        l=l->prox;
    }
}

// 26

LInt rotateL (LInt l){
    LInt *p=&l,m=0;
    while(*p)
        p=&((*p)->prox);
        
    *p=l;
    
    if(l){
        m=l->prox;
        l->prox=0;
    }
    return m;
}

// 27


LInt parte (LInt l){
    LInt res=NULL, *n, *e;
    n = &res;
    e = &l;
    int pos=0;
    while(*e != NULL){
        if (pos%2!=0){
            *n = *e;
            n = &((*n)->prox);
            *e = (*e)->prox;
        }
        else{
            e = &((*e)->prox);
        }
        pos++;
    }
    *n = NULL;
    return res;
}




