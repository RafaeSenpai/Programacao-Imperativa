#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bigMain.h"/*quando se quer incluir uma API propria usa-se as aspas ao contrario <API's padrao>*/
#include "ficha1.h"
#include "m_Ficha1.h"



/*Exercicio 2*/
void exercicio2_F1(int x){
int i,j;

	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			putchar('x');
		}
		printf("\n");
	}
}



/*Exercicio 3*/
void controiLinha(int x,int y){

	while(y>=0){
		if(x%2==0){
			putchar('#');
			x++;
		}else{
			putchar('_');
			x++;
		}
		y--;
	}

	printf("\n");
}

void exercicio3_F1(int x){
int numElemLinha = x;
int numElem=0;

	for(int numLinha = 0; numLinha <= x; numLinha++){
		controiLinha(numElem,numElemLinha);
		numElem++;
	}
}



/*Exercicio 4 - Apenas 1 dos triangulos*/
void trianguloHorizontal(int x){
int altura;
int numElem;
	/*Primeira metado do triangulo*/
	for(altura = 0; altura < x; altura++){
		for(numElem=0; numElem <= altura; numElem++){
			putchar('#');
		}
		printf("\n");
		numElem = 0;
	}
	/*para o triangulo não ter o ponto mais alto definido por duas colunas do mesmo tamanho mas sim por apenas 1 coluna*/
	altura = altura-2;

	/*segunda metade do triangulo*/
	for(; altura >= 0; altura--){
		for(numElem=altura; numElem>=0; numElem--){
			putchar('#');
		}
		printf("\n");
	}
}



