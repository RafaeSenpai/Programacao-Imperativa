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



/*Exercicio 35*/ //-------------------------FUNCIONAL 10/10
int freeAB (ABin a) {
ABin ant = a;
int count = 0;

    if(a){
        ant = a;
        free(a);
        count += freeAB(ant->esq);
        count += freeAB(ant->dir);
        count++;
    }
    
    return count;
}

/*Exercicio 36*/
 
int pruneAB (ABin *a, int l) {
int n=0;
    
    if(*a){
        n+=pruneAB(&((*a)->esq),l-1);
        n+=pruneAB(&((*a)->dir),l-1);
        if(l<=0){
            free(*a);
            *a=NULL; //----nao percebo porque tenho que igualr a null. o free nao iguala a null automaticamente?
            n++;
        }
        
    }
    return n;
}


/*EXERCICIO 37*/ //-------------------FUNCIONAL 10/10 ----->>>REVER!
int iguaisAB (ABin a, ABin b) {
int r = 0;
    if (!a && !b){
        r = 1;
    }
    
    if(a && b){
       r = ((a->valor == b->valor) && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir));
       // return ((a->valor == b->valor) && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir));
    }
    
    return r;
}



/*Exercicio 38*/ //--------------------------FUNCIONAL 10/10-- >>>REVER!
LInt newLInts (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

LInt juntaLInts(LInt *a,LInt b){
LInt *p = a;

	while(*p){
		p = &((*p)->prox);
	}
	(*p) = b;
	
return (*a);
}



LInt nivelL(ABin a, int n){
LInt l;
l=NULL;
	

	if(a){
		if(n==1){ /*guarda na lista quando chega ao nivel pretendido*/
	        l = newLInts(a->valor,l);	        
		}else{
			l = nivelL(a->esq,n-1);/*vai descendo na arvore até ao nivel pretendido(n==1)*/
			l = juntaLInts(&l,nivelL(a->dir,n-1)); /*junta a lista que já contem os valores da esquerda da arvore no nivel pretendido com a lista dos valores existentes na arvore direita no nivel pretendido*/
		}
	}
	return l;
}


/*Exercicio 39*/ //---------INOMPLETO & NÃO ESTÁ FUNCIONAL
int addToArray (int val, in v[],int ind){
int x = 0;

	v[ind] = val;

	return v;
}

int juntaArray(int v1[], int x, int v2[],int y){
int novoArray[x+y];
int ind,i;

	for(ind=0; ind<=x; ind++){
		novoArray[ind] = v[ind];
	}
	for(i=0; i<=y; i++; ind++){
		novoArray[ind] = v2[i];
	}

	return novoArray;

}


int nivelVaux (ABin a, int n, int v[],int indArray){

	if(a){
		if(n==1){
			v = addToArray(a->valor,v,indArray++);
		}else{
			v = nivelVaux(a->esq, n-1, v,indArray1);
			v = juntaArray(v,indArray1,nivelVaux(a->dir,n-1,v,indArray2));	
		}
		return indArray;
	}
}

int nivelV(ABin a,int n, int v[]){

	return (nivelVaux(a,n,v,0,0));
}




/*Exercicio 40*/ //--------------------------FUNCIONAL 10/10 ---->>>REVER
int numElemABin(ABin a){ /*cALCULA O NUMERO DE ELEMENTOS DE UMA ARVORE BINARIA --- NÃO É USADA NESTE EXERCICIO MAS FUNCIONA*/
int total = 0;

	if(!a){
		total = 1 + numElemABin(a->esq) + numElemABin(a->dir);
	}

	return total;
}



int dumpAbin(ABin a, int v[],int N){
int ind = 0;

	if(a && ind<N){
    	ind+=dumpAbin(a->esq,v,N);
        if(ind<N){
    		v[ind] = a->valor;
    		ind++;
        }
        
        ind+=dumpAbin(a->dir,v+ind,N-ind);
	

	}

	return ind;
}

/*EXERCICIO 41*/
somaNodos(ABin a){

	if(a){
		return (a->valor + somaNodos(a->esq) +somaNodos(a->dir));
	}
}

ABin somasAcA (ABin a) {
ABin *p = &a;
ABin aux = NULL;

    if(*p){
        aux = malloc(sizeof(struct nodo));
        aux->valor = somaNodos(*p);
        aux->esq = somasAcA((*p)->esq);
        aux->dir = somasAcA((*p)->dir);
    }
    a = aux;
    return a;
}




/*RESOLUÇÃO DO RAFA - FUNCIONA - MAS TIRAR A DUVIDA ABAIXO COMENTADA! */
int intcabeca (ABin a){
    if (a == NULL) return 0;
    else return a->valor;
}

 
ABin somasAcA (ABin a){ //NÃO COMPREEENDO COMO É QUE NO FINAL AO IGUALAR O 'a=aux' funciona! Supostamente não perdemos a cabeça da lista 'a' quando começamos a descer na arvore??
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


/*EXERCICIO 42*/

int contaFolhas(ABin a){
int count = 0;

    if(a){
        if((a->esq == NULL) && (a->dir == NULL)){
            count = 1;
        }
        count += contaFolhas(a->esq) + contaFolhas(a->dir);
    }
    return count;
}


/*EXERCICIO 43*/ //devolve a arvore como é pedida mas nao passa em nenhum teste

ABin cloneMirrorAux (ABin a){
ABin tmp = malloc(sizeof(struct nodo));
ABin mirror;  

    if(a){
        mirror = malloc(sizeof(struct nodo));
        mirror->valor = a->valor;
        
        tmp = a->esq;
        a->esq = a->dir;
        a->dir = tmp;
        
        cloneMirrorAux(a->esq);
        cloneMirrorAux(a->dir);
    }
    
	return (*p);
}


ABin cloneMirror(ABin a){
ABin mirror = NULL; 
	mirror = cloneMirrorAux(a);
	return mirror;
}


/*EXERCICIO 44*/ //---------------------------------FUNCIONAL 10/10
ABin newNode(int x, ABin esq, ABin dir){
ABin new = malloc(sizeof(struct nodo));

	if(new){
		new->valor = x;
		new->esq = esq;
		new->dir = dir;
	}
	return new;
}

int addOrd (ABin *a, int x){
int r = 0;

			while((*a)){
				if(x == ((*a)->valor)) {
					return 1; // <==> r = 1;
			
				}else if(x<((*a)->valor)){
					a = &((*a)->esq);
			
				}else{
					a = &((*a)->dir);
				}
			}

		if(!(*a)){
			(*a) = newNode(x,NULL,NULL);
		}

	return r
}

/*EXERCICIO 45*/ //-----------------------FUNCIONAL 10/10
int lookupAB (ABin a, int x) {

        while(a){
            if(x == a->valor){
                return 1;                 
            }else if (x<a->valor){
                a = a->esq;
            }else{
                a = a->dir;
            }
        }
    return 0;
}


/*EXERCICIO 46*/ //-----------------------------FUNCIONAL 10/10
int depthOrd (ABin a, int x){
int level = 0;

	while(a){
		if(a->valor == x){
			level++;
			return level;
		}else if(x < a->valor){
			level++;
			a = a->esq;
		}else{
		    level++;
			a = a->dir;
		}
	}
    if(!a){
        level = -1;
    }
	return level;
}


/*EXERCICIO 47*/ //-----------------------------FUNCIONAL 10/10
int maiorAB (ABin a) {
    while(a->dir != NULL){
        a = a->dir;
    }
    
    return a->valor;
}


/*EXERCICIO 48*/ //---------------------------FUNCIONAL 10/10 ----->>TIRAR DUVIDA
void removeMaiorA (ABin *a) {

    if(!(*a)){
        return NULL;
    }

    while((*a)->dir){
        a = &((*a)->dir);
    }

    free(*a); /*NÃO PERCEBO COMO É QUE FAZENDO FREE A SEGUIR CONSIGO IR BUSCAR O (*A)->ESQ, SUPOSTAMENTE NÃO SERIA PERDIDA TODA A INFORMAÇÃO APÓS O FREE???!!!*/
    (*a) = (*a)->esq;
}


/*EXERCICIO 49*/ //----------------------FUNCIONAL 10/10 ------>>>REVER TODOS OS EXES COM ACUMULADORES COMO ESTE
int quantosMaiores (ABin a, int x) {
int count = 0;

    if(a){
        if((a->valor)>x){
            count++;
        }
        count += quantosMaiores(a->esq,x);
        count += quantosMaiores(a->dir,x);
    }
    return count;
}

/*EXERCICIO 50*/ //---------------------------FUNCIONAL 10/10 --->>REVER AS DESLOCAÇÕES EM ARVORES E LISTAS COM RECURSO A APONTADORES (P = &(*P)->PROX);
ABin newNode(int x, ABin esq, ABin dir){
ABin new = malloc(sizeof(struct nodo));

    if(new){
        new->valor = x;
        new->esq = esq;
        new->dir = dir;
    }
    return new;
}



void listToBTree(LInt l, ABin *a){
ABin *p = a;
    
    if(!l){
        return NULL;
    }else{
        while(l){
            (*p) = newNode(l->valor,NULL,NULL);
            p=&((*p)->dir);
            l = l->prox;
        }
    }
}



/*EXERCICIO 51*/ //--------------------------REFAZER -----ERRADA
int deProcura (ABin a) {
ABin pEsq, pDir;
int r=0;

    if(a){
        if(a->esq && a->dir){
            pEsq = a->esq;
            pDir = a->dir;
            if(((pEsq->valor) < (a->valor)) && ((pDir->valor) > (a->valor))){
                r = 1;
            }
            
        }else if (!(a->esq) && !(a->dir)){
                r = 1;
            
        }else if((!(a->esq)) && (a->dir)){
            pDir = a->dir;
            if(pDir->valor > a->valor){
                r = 1;
            }
        }else if((a->esq) && (!(a->dir))){
            pEsq = a->esq;
            if(pEsq->valor < a->valor){
                r = 1;
            }
        }else{
            r = 0;
        }
        
        
        if(r==0){
            return r;
        }else{
            return (r && deProcura(a->esq) && deProcura(a->dir));
        }
    }
}