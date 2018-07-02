/*40 segundas questões para o 2 teste ou parte do exame 2018 de PI*/

/*Listas Ligadas*/
typedef struct lligada {
	int valor;
	struct lligada *prox;
} *LInt;

/*Questão 1*/
int lengthL(LInt l){
int count = 0;

	if(l){
		while(l){
			count++;
			l=l->prox;
		}
	}
	return count;
}



/*Questão 2*/
void freeL(LInt l){
LInt ant=NULL;

	if(l){
		while(l){
			ant = l;
			free(l);
			l=ant->prox;
		}
	}
}




/*Questão 3*/
void imprimeL(LInt l){

	if(l){
		while(l){
			printf("%d\n",l->valor);
			l = l->prox;
		}
	}
}




/*Questão 4*/ //------------------------------------------REVER!!!
LInt reverseL(LInt l){
LInt anterior = NULL;
LInt seguinte;
LInt atual = l;

    while(atual){
        seguinte = atual->prox;
        atual->prox =anterior;
        anterior = atual;
        atual = seguinte;
    }
    
    l =anterior;
    return l;
}


/*Questão 5*/
void insertOrd (LInt *l, int x){

	while((*l) && (*l)->valor<=x){ /*Deve-se ter atenção á ordem destas condições, pois 1º tem que se garantir que (*l) n é nulo. Caso as condições estivessem em ordem inversa dará seg fault porque se for null não irá ser encontrado a (*l)->valor*/
		l=&((*l)->prox);
	}
	LInt new = malloc(sizeof(struct lligada));
	if(new){
		new->valor=x;
		new->prox = (*l); /*aponta para a restante da lista*/
		(*l)=new;
	}
}


/*Questão 6*/ //-----------------------FUNCIONAL 10/10!!!
// https://codeboard.io/projects/16245
int removeOneOrd(LInt *l, int x){
LInt *aux = l;
LInt *seguinte;
int flag = 1;

    if(*aux){
        seguinte = &((*aux)->prox);
        while(*aux && (*aux)->valor!=x){
            aux = &((*aux)->prox);
            seguinte = &((*aux)->prox);
        }
        
        if(*aux){
            free(*aux);//<---é indiferente ter ou nao o free
            (*aux)=(*seguinte);
            flag=0;
        }
    }
    return flag;
}



/*QUESTÃO 7*/ //-----------------------------FUNCIONAL 10/10
// https://codeboard.io/projects/16246
void merge (LInt *r, LInt l1, LInt l2){
    
    while(l1 || l2){
        if(l1 && !l2){
            *r = l1;
            r = &((*r)->prox);
            l1 = l1->prox;
        }else if(!l1 && l2){
            *r = l2;
            r = &((*r)->prox);
            l2 = l2->prox;
        }else if(l1->valor<l2->valor){
            *r = l1;
            r=&((*r)->prox);
            l1=l1->prox;
        }else if(l1->valor>l2->valor){
            *r=l2;
            r=&((*r)->prox);
            l2 = l2->prox;
        }else{
            if(l1->valor == l2->valor){
                *r=l1;
                r=&((*r)->prox);
                l1 = l1->prox;
                *r=l2;
                r=&((*r)->prox);
                l2 = l2->prox;
            }
        }
    }
}


/*Questão 8*///--------------------------------FUNCIONAL 10/10
//https://codeboard.io/projects/16247
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){

	while(l){
		if(l->valor<x){
			*mx=l;
			mx=&((*mx)->prox);
		}else{
			*Mx=l;
			Mx=&((*Mx)->prox);
		}
		l=l->prox;
	}
	*mx = 0;
	*Mx = 0;
}


/*Questão 9*/ //------------------------------------------REVER!!!
//https://codeboard.io/projects/17392
LInt parteAmeio (LInt *l){
    LInt *tmp, 
    tmp = l;
    LInt r = *l;
    int c = length(*l)/2;
    
    while (c){//enquanto nao chegar ao meio da lista
        tmp = &((*tmp)->prox); //avança na lista equivalente ao &x
        *l = (*l)->prox;//avança na lista original
        c--;
    }
	if (r == *l){//acontece se a lista contiver apenas 1 elemento
	    r = NULL;//a suposta lista a devolver a 'y' será vazia e a lista 'x'(representada por *tmp) irá conter os restantes elementos  
	}else{
	    *tmp = NULL;//finalizar a lista com os restantes elementos com o NULL;
	}
	return r;
}

/*Questão 10*/ //--------------------------FUNCIONAL 10/10
int removeAll(LInt *l,int x){
LInt *tmp;
int count=0;

	while(*l){
		if((*l)->valor==x){
			tmp=&((*l)->prox);
			free(*l);
			(*l)=(*tmp);
			count++;
		}else{
	    	l=&((*l)->prox);
	    }
	}
return count;
}



/*Questão 11*/
// https://codeboard.io/projects/16250
int removeDups (LInt *l){
int count;
	while(*l){
		count+=removeAll(&((*l)->prox),(*l)->valor);
		l = &((*l)->prox);
	}
	return count;
}



/*Questão 12*/
// https://codeboard.io/projects/16251
int removeMaiorL (LInt *l){
int max = maior(*l);
int flag=1;
LInt *seg=NULL;

    while(flag==1){
        if((*l)->valor == max){
            seg=&((*l)->prox);
            
            (*l)=(*seg);
            flag=0;
        }else{
            l=&((*l)->prox);
        }        
    }
    return max;
}



/*Questão 13*/
// https://codeboard.io/projects/16252
void init (LInt *l){
	while((*l)->prox){
		l=&((*l)->prox);
	}
	free(*l);
	(*l)=NULL;
}



/*Questão 14*/
// https://codeboard.io/projects/16253
void appendL (LInt *l, int x){
    if(*l){
        while(*l){
            l=&((*l)->prox);
        }
        LInt new = malloc(sizeof(struct lligada));
        if(new){
            new->valor=x;
            new->prox=NULL;
            (*l)=new;
        }
    }else{
        LInt new = malloc(sizeof(struct lligada));
        if(new){
            new->valor=x;
            new->prox=NULL;
            (*l)=new;
        }
    }
}