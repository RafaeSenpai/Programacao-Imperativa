typedef struct nodo {
	int valor;
	struct nodo *esq, *dir;
} *ABin;

/*Exercicio 28*/ //-------------------------FUNCIONAL 10/10
#define max(a,b) ((a) > (b) ? (a) : (b))

int altura (ABin a){
int alt = -1;
    if(a != NULL){
        alt = 1 + max(altura(a->esq),altura(a->dir));
    }
	return alt;
}
//ou
int altura (ABin a){
ABin *p = &a;
int alt = -1;
    if(*p != NULL){
        alt = 1 + max(altura((*p)->esq),altura((*p)->dir));
    }
	return alt;
}



/*Exercicio 29*/ //-----------------------FUNCIONAL 10/10
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

/*Exercicio 30*/ //-----------------------FUNCIONAL 10/10
void mirror (ABin *a) {
ABin *p = a;
ABin aux = malloc (sizeof(struct nodo));

    if(!(*p)){
        (*p) = NULL;
    }else{
        aux = (*p)->esq;
        (*p)->esq = (*p)->dir;
        (*p)->dir = aux;
        mirror(&((*p)->esq));
        mirror(&((*p)->dir));
    }

}


/*Exercicio 31*/ //-------------------------FUNCIONAL 10/10
LInt insertLInt(int x, LInt l){ //adiciona valor no final da lista
LInt *p = &l;
LInt new = malloc(sizeof(struct lligada));


    if(new!=NULL){
        new->valor = x;
        new->prox = NULL;
        if(l==NULL){
            (*p)=new;
        }else{
            while((*p)->prox!=NULL){
                p=&((*p)->prox);
            }
            (*p)->prox = new;
        }
    }
    return l;
}


LInt *inorder (ABin a, LInt *l) {
ABin *p = &a;
LInt lst = malloc(sizeof(struct lligada));

    if(*p){
        inorder(((*p)->esq),l);
        (*l) = insertLInt((*p)->valor,(*l));
        inorder(((*p)->dir),l);
    }
    
    return l;
}


/*Exercicio 32*/
LInt insertLInt(int x, LInt l){ //adiciona valor no final da lista
LInt *p = &l;
LInt new = malloc(sizeof(struct lligada));


    if(new!=NULL){
        new->valor = x;
        new->prox = NULL;
        if(l==NULL){
            (*p)=new;
        }else{
            while((*p)->prox!=NULL){
                p=&((*p)->prox);
            }
            (*p)->prox = new;
        }
    }
    return l;
}


void preorder(ABin a, LInt *l){
ABin *p = &a;

    if(*p){
    	(*l) = insertLInt((*p)->valor,(*l));
        preorder(((*p)->esq),l);
        preorder(((*p)->dir),l);
    }
}


/*Exercicio 33*/
void insertLInt(int x, LInt l){ //adiciona valor no final da lista
LInt *p = &l;
LInt new = malloc(sizeof(struct lligada));


    if(new!=NULL){
        new->valor = x;
        new->prox = NULL;
        if(l==NULL){
            (*p)=new;
        }else{
            while((*p)->prox!=NULL){
                p=&((*p)->prox);
            }
            (*p)->prox = new;
        }
    }

}


void posorder(ABin a, LInt *l){
ABin *p = &a;
LInt lst = malloc(sizeof(struct lligada));

    if(*p){
        posorder(((*p)->esq),l);
        posorder(((*p)->dir),l);
    	(*l) = insertLInt((*p)->valor,(*l));
    }

}


/*Exercicio 34*/  //-----------------------FUNCIONAL 10/10
#define min(a,b) ((a) < (b) ? (a) : (b))

int depth (ABin a, int x) {
int nivel_E, nivel_D;
int nivel = -1;
    
    if(a){
        if(a->valor == x){
            nivel = 1;
        }else{
            nivel_E = depth(a->esq,x);
            nivel_D = depth(a->dir,x);
            
            if(nivel_E>0 && nivel_D>0){
                nivel = 1 + min(nivel_E,nivel_D);
            }else if(nivel_E<0 && nivel_D>0){//se nivel_E fôr menor que 0 então é porque não encontrou o valor iteração corrente e devolve o valor -1 a nivel_E
                nivel = nivel_D + 1; 
            }else if(nivel_E>0 && nivel_D<0){
                nivel = nivel_E + 1;
            }
        }
    }
 return nivel;   
}
