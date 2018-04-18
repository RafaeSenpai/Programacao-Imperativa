#include <stdio.h>
#include <stdlib.h>
#include "bigMain.h"
#include "50segundas.h"
#include "m_50Segundas.h"
/*#include "myStructs.h"*/ /*não ha necessidade de fazer este include aqui, 50perguntas.c, pois a API (50perguntas.h) 
							das funções que estão a usar estruturas de dados expecificas já contém esse 
							include. Mas atenção que estando a fazer o include do ficheiro das estruturas de dados,myStructs.h,
							na API, torna essas mesmas estruturas publicas, reduzindo assim o nivel de segurança do programa!
							Neste caso, mesmo sabendo que tornamos publicas as estruturas de dados, é feito o include das 
							estruturas na API, 50segundas.h, pois, como esse mesmo ficheiro das estruturas contem estruturas 
							usadas em programas feitos noutros ficheiros .c que não este, 50segundas.c somos obrigados a
							incluir entao myStructs.h na API 50segundas.h.
							
							É boa politica que para cada ficheiro .c este tenha a sua respetiva API contendo apenas os headers das
							funções usadas, mas por forma a manter o nivel de segurança, as estruturas de dados usadas nesses mesmos
							programas deve ser feito num .h á parte e o mesmo ser incluido APENAS no .c que contem o codigo das
							funções que usam essas mesmas estruturas de dados.*/
							


/*Iniciar uma lista ligada*/
void iniciarListaL(LInt x){
	x->prox=NULL;
}




/*cria um (*nodo)*/
LInt criaNodo(){
LInt novo = malloc(sizeof(struct lligada));

	if(!novo){
		printf("Memória insuficiente!\n");
	}else{
		novo->prox=NULL;
	}
}



/*Cria uma lista ligada automaticamente*/
LInt criarLInt(){
LInt tmp = malloc(sizeof(struct lligada));
LInt novaLInt = tmp;

	for(int i=1;i<=3;i++){
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





/*Exercicio1 - Recurso a apontadores apenas*/  // -------------------REVER  APONTADORES
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


/*exercicio2*/ //100% correto 
LInt freeL(LInt x){
LInt *aux = &x;
LInt *anterior;

	while((*aux)!=NULL){
		anterior = (*aux);
		free(anterior);	
		(*aux)=(*aux)->prox;
	}
return x;
}

/*Exercicio3*/
void imprimeL (LInt l){
LInt temp = l;
LInt ant;
ant = temp;
		while(temp->prox!=NULL){
						
				printf(" _______________________________\n|End. anterior: %d\t|\n|End. atual: %d\t\t|\n|VALOR: %d\t\t\t|\n|End. proximo: %d\t|\n|_______________________________|======##\n                                       ||\n                                       ||\n                ##=====================##\n                ||\n                \\/",ant,temp,temp->valor,temp->prox);
				printf("\n");
				ant=temp;
				temp = temp->prox;
				

		}
		printf("\n\tImpressão concluida!\n\n");	

}

/*exercicio4*/ //-----------------------------------APESAR DO OUTPUT EM LOCALHOST DÁR ERRADO(DEVE TER A VER COM A INTERFACE) PASSA EM TODOS OS TESTES ONLINE

int swapLInt(int val,int pos,LInt l){/*leva um valor(val) para ser clocado numa posição(pos) e devolve o valor(aux->val) que se encontrava nessa mesma posição */
LInt aux = l;
int x=0;
int i;

	for(i=1;i<=pos;i++){
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




/*exercicio5*/
void insertOrd (LInt *l, int x){
LInt aux = *l;
LInt anterior=NULL; //futuramente se anterior!=NULL então quer dizer que está ou no inicio da lista ou a lista onde seria para inserir o valor encontra-se vazia
	
	while(aux!=NULL && aux->valor<=x){ //enquanto nao for final da lista e o valor for maior que o valor em lista avança na mesma
		anterior = aux;
		aux = aux->prox;
	}

	LInt new = malloc(sizeof(struct lligada));
	new->valor = x;
    new->prox = aux;

	if(anterior==NULL){ //caso a lista seja vazia ou seja logo menr que o 1º elemento da lsita
		(*l)=new;
	}else{
		anterior->prox = new;
	}
}


/*exercicio6*/
int removeOneOrd (LInt *l, int x){
LInt *aux = l; //cria-se um apontador auxiliar, *aux, que vai ficar com o endereço onde está o conteudo de (*l), mas como (*aux) é um apontador, este vai ficar com o endereço e não com o conteudo existente no endereço, assim tem-se que (*aux)=l, pois 'l' é o endereço.

//printf("%d",aux)<-----mostra o endereço de memoria para onde o apontador (*aux) está a apontar
//printf("%d",*aux);<---mostra o conteudo existente no endereço de memoria guardado em (*aux)    

    while((*aux) && (*aux)->valor<x){
        aux=&((*aux)->prox); //'aux' é um apontador que detém o endereço para onde aponta (*aux)->prox, mas (*aux)->prox é conteudo e não um endereço de memoria, entao coloca-se &((*aux)->prox)
    }
    
    if((*aux) && (*aux)->valor==x){
        free(*aux); //limpa o conteudo existente (*aux) na posição de memoria indicada pelo apontador 'aux'        
        *aux=(*aux)->prox; //atribui o conteudo existente em (*aux)->prox a (*aux),que representa informação 

        return 0;
    }else{
        return 1;
    }
}

/*exercicio7*/
LInt insereNodo(int x,LInt l){
LInt anterior = NULL;
LInt aux = l;
LInt nodo=malloc(sizeof(struct lligada));

	while(aux!=NULL){
		anterior = aux;
		aux=aux->prox;
	}

	nodo->valor=x;
	nodo->prox=NULL;
	anterior->prox=nodo;

return l;	
}

void myMerge (LInt *r, LInt a, LInt b){
LInt aux1 = a;
LInt aux2 = b;

	while(!aux1){
		(*r) = insereNodo(aux1->valor,(*r));
		aux1=aux1->prox;
	}

	while(!aux2){
		(*r) = insereNodo(aux2->valor,(*r));
		aux2=aux2->prox;
	}
	
}






void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
LInt aux = l;

    while(aux){
        if(aux->valor<x){
            (*mx)=newLInt(aux->valor,(*mx));
            mx=&((*mx)->prox);         
        }else{
            (*Mx)=newLInt(aux->valor,(*Mx));
            Mx=&((*Mx)->prox);             
        }
        aux=aux->prox;
    }
}