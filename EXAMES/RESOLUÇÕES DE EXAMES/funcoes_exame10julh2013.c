#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcoes_exame10julh2013.h"
/*Exercicio 1*/
int e_repetido(int x, int v[], int tam){ //verifica se existe algum elemento igual até ao elemento que se está a verificar, desta forma 
int i;								 //garantee-se que não se elimina a primeira ocorrencia de um elemento repetido, mas sim as ocorrencias
									 //repetidas para a frente do elemento procurado
	for(i=0; i<tam; i++){
		if(v[i] == x){
			return 1;
		}
	}
	return 0;
}

int elimRep(int v[], int n){
int i,j;
int *lst = malloc(n*sizeof(int));
i=0;
j=0;
lst[j]=v[i];
j++;
	for(i=0;i<n;i++){
		if(e_repetido(v[i],lst,j)==0){
			lst[j]=v[i];
			j++;
		}
	}
	

	for(i=0;i<j;i++){
		v[i]=lst[i];
	}
return j;
}


//Exercicio 2
int maximo(LLint l){
int max = l->valor;

	while(l){
		if(l->valor>max){
			max = l->valor;
		}
		l = l->prox;
	}
	return max;
}



//Exercicio 3
int iguais(ABint a, ABint b){
	return ((a->valor == b->valor) && (iguais((a->esq),(b->esq))) && (iguais((a->dir),(b->dir))));	
}

/*
//Exercicio 4
int cp(char *origem, char *destino){


}
*/

//Exercicio 5 - foi modificado de 'void' para 'char'
/*Recorreu-se ao uso de uma função, toupper() da bilioteca ctype, conforme se pde verificar no inicio do codigo*/
char *capitaliza(char s[]){

	for(int i=0; s[i]!='\0';i++){
		if(s[i]=='.'){
			while(s[i]==' ' && s[i]!='\0'){
				i++;
			}
		}
		if(s[i]!='\0'){
			s[i] = toupper(s[i]);
		}
	}
	return s;
}

/*Exercicio 6*/
//Não percebi bem o que deve ser feito



//Exercicio 7
LLint addLLint(int x,LLint a){
LLint new = malloc(sizeof(struct llint));
LLint *p;
p = &a;

	if(new){
		new->valor = x;
		new->prox = (*p);
	}
	return new;
}


LLint nivel(ABint a, int n){
LLint lst = malloc(sizeof(struct llint));
lst = NULL;

	if(a){
		if(n==1){
			lst = addLLint(a->valor,lst);			
			nivel(a->esq,n-1);
			nivel(a->dir,n-1);
		}
	}

return lst;
}



//Exercicio 8
int verifPrimo(int x){
int count = 0;
int r = 0;

	for(int i=1; i<=x; i++){
		((x%i)==0)?(count++):(count);
	}

	if(count==2){
		r=1;
	}
	return r;
}

int gPrimeDiv(int n){ //deve estar mal o raciocinio usado,mt provavel!
int maior = 0;

	if((n>=2) && (verifPrimo(n)==1)){ //verifica se n é primo

		for(int i=2;i<n;i++){
			if(n%i == 0 && maior<n/i){
				maior = i;
			}
		}
	}
	return maior;
}

