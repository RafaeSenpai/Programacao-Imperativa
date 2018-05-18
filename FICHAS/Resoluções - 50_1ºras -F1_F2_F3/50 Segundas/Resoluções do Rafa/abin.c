#include "abin.h"
#include <stdio.h>
#include <stdlib.h>

// 28

int max (int x, int y){
    if(x>y){
        return x;
    }
    else{
        return y;
    }
}

int altura (ABin a){
   int res=0,e,d;
   if(a){
       e = altura(a->esq);
       d = altura(a->dir);
       res += 1 + max(e,d);
   }
   return res;
}

// 29

ABin cloneAB (ABin a) {
    ABin c;
    if(!a){
        c=NULL;
    }
    else{
        c = (ABin) malloc (sizeof(struct nodo));
        c->valor = a->valor;
        c->esq = cloneAB(a->esq);
        c->dir = cloneAB(a->dir);
    }
    return c;
}

// 30

void mirror (ABin *a) {
    ABin aux;
    if(*a){
        aux = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = aux;
        
        mirror(&((*a)->esq));
        mirror((&(*a)->dir));
    }
}

// 31

LInt inorderAux(ABin a, LInt r){
    if(a!=NULL){   
        r = inorderAux(a->dir,r);
        r = newL(a->valor,r);
        r = inorderAux(a->esq,r);
    }
    return r;
}
void inorder(ABin a, LInt *l){
    *l = inorderAux (a,NULL);
}

// 32 

LInt preorderAux(ABin a, LInt r){
    if(a!=NULL){   
        r = preorderAux(a->dir,r);
        r = preorderAux(a->esq,r);
        r = newL(a->valor,r);
    }
    return r;
}
void preorder (ABin a, LInt * l){
    *l = preorderAux(a,NULL);
}

// 33  

LInt newL(int x, LInt l){
    LInt new = (LInt) malloc (sizeof(struct lligada));
    if(new!=NULL){
        new->valor = x;
        new->prox = l;
    }
    return new;
}

LInt posorderAux(ABin a, LInt l){
    if(a){
        l = newL(a->valor,l);
        l = posorderAux(a->dir,l);
        l = posorderAux(a->esq,l);
    }
    return l;
    
}
 void posorder (ABin a, LInt *l) {
    *l =  posorderAux(a,NULL);    
}
// 34

int min (int x, int y){
    if(x>y){
        return y;
    }
    else{
        return x;
    }
}

int depth (ABin a, int x) {
    int dep=-1,e,d;
    
    if(a){
        if((a->valor)==x){
            dep=1;
        }
        else{
            e=depth(a->esq,x);
            d=depth(a->dir,x);
            if(e>0 && d>0){
                dep=1+min(e,d);
            }
            else{ 
                if(e<0 && d>0){
                    dep=d+1;   
                }
                if(e>0  && d<0){
                    dep=e+1;
                }
            }
        }
    }
    return dep;
}

// 35

int freeAB (ABin a) {
    int n=0;
    if(a){
        n+=freeAB(a->dir);
        n+=freeAB(a->esq);
        free(a);
        n++;
    }
    return n;
}

// 36

 int pruneAB (ABin *a, int l) {
    int n=0;
    
    if(*a){
        n+=pruneAB(&((*a)->esq),l-1);
        n+=pruneAB(&((*a)->dir),l-1);
        if(l<=0){
            free(*a);
            *a=0;
            n++;
        }
        
    }
    return n;
 }

 // 37

 int iguaisAB (ABin a, ABin b) {
   int r=0;
   
   if(a && b){
      r = ((a->valor)==(b->valor) && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir));
   }
   if(!a && !b){
       r=1;
   }
   return r;
}

// 38???

// 39???

// 40 ??

int dumpAbin (ABin a, int v[], int N) {
    int i=0;
    if(a && i<N){
        i+=dumpABin(a->esq,v,N);
        if(i<N){
            v[i]=a->valor;
            i++;
        }
        i+=dumpAbin(a->dir,v+i,N-i);
    }
    return i;
}

// 41

int intcabeca (ABin a){
    if (a == NULL) return 0;
    else return a->valor;
}

 
ABin somasAcA (ABin a){
    ABin aux=NULL;
    if(a){
        aux = (ABin) malloc (sizeof(struct nodo));
        aux->esq = somasAcA(a->esq);
        aux->dir = somasAcA(a->dir);
        aux->valor = a->valor + intcabeca(aux->esq) + intcabeca(aux->dir);
        a=aux;
    }
    return a;
}

// 42

int contaFolhas (ABin a){
    int res=0;
    if(!a) res+=0;
    else{
        if(!a->dir && !a->esq) res+=1;
        else{
            res+=contaFolhas(a->esq);
            res+=contaFolhas(a->dir);
        }
    }
    return res;
}

// 43

ABin newA (int r, ABin esq, ABin dir){
	ABin new = (ABin) malloc (sizeof (struct nodo));

	if (new!=NULL){
		new->valor = r;
		new->esq   = esq;
		new->dir   = dir;
	}
	return new;
}

ABin cloneMirror (ABin a){
    ABin b=NULL;
    if(a){
        b=newA(a->valor,cloneMirror(a->dir),cloneMirror(a->esq));
    }
    return b;
}

// 44

ABin newA(int x, ABin esq, ABin dir){
    ABin new = (ABin) malloc (sizeof(struct nodo));
    
    if(new){
        new->valor = x;
        new->esq = esq;
        new->dir = dir;
    }
    return new;
}

int addOrd (ABin *a, int x) {
    int r=0;
    while(*a){
        if((*a)->valor==x) return 1;
        else{
            if(x > (*a)->valor){
                a=&((*a)->dir);
            }
            else{
                a=&((*a)->esq);
            }
        }
    }
    *a=newA(x,NULL,NULL);
    return r;
}

// 45

int lookupAB (ABin a, int x) {
    int r=0;
    
    if(a){
        if((a->valor)==x){
            r=1;
        }
        else{
            if((a->valor) > x){
                r=lookupAB(a->esq,x);
            }
            else{
                r=lookupAB(a->dir,x);
            }
        }
    }
    return r;
}

// 46

int depthOrd (ABin a, int x) {
    int r=0;
    
    if(a){
        if((a->valor)==x){
            r+=1;    
        }
        else{
            if((a->valor)>x){
                r += 1+depthOrd(a->esq,x);
            }
            else{
                r += 1+depthOrd(a->dir,x);
            }
        }
    }
    if(r==0) return -1;
    
    return r;
}

// 47


int maiorAB (ABin a) {
    int r = 0;
    if(a){
        while(a->dir){
            a=a->dir;
        }
        r=a->valor;
    }
    return r;
}

// 48

void removeMaiorA (ABin *a) {
    
    if(!*a) return;
    
    while((*a)->dir){
        a=&((*a)->dir);
    }
    free(*a);
    (*a) = (*a)->esq;
}

// 49

int quantosMaiores (ABin a, int x) {
    int r=0;
    if(a){
        if((a->valor)>x){
            r+=1;
        }
        r += quantosMaiores(a->esq,x);
        r += quantosMaiores(a->dir,x);
    }
    return r;
}

// 50

ABin newAB (int x, ABin esq, ABin dir){
    ABin new = (ABin) malloc(sizeof(struct nodo));
    if(new){
        new->valor = x;
        new->esq = esq;
        new->dir = dir;
    }
    return new;
}

void listToBTree (LInt l, ABin *a) {
    *a=NULL;
    
    if(!l){
        *a=NULL;
    }
    else{
        while(l){
            *a = newAB(l->valor,NULL,NULL);
            a=&((*a)->dir);
            l=l->prox;
        }
    }
}

// 51

int maior(ABin a , int x){
    int r=0;
    if(!a){
        r=1;
    }
    else{
        if((a->valor)>x && maior(a->dir,x) && maior(a->esq,x)){
            r=1;
        }
    }
    return r;
}

int menor(ABin a, int x){
    int r=0;
    if(!a){
        r=1;
    }
    else{
        if((a->valor)<x && menor(a->dir,x) && menor(a->esq,x)){
            r=1;
        }
    }
    return r;
}

int deProcura (ABin a) {    
    int r=0;
    if(!a){
        r=1;   
    }
    else{
        r = menor(a->esq,a->valor) && maior(a->dir,a->valor) && deProcura(a->esq) && deProcura(a->dir);
    }
    return r;
}


















