#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reRoutingEntreMenus.h"/*API da função de reencaminhamento entre o menu principal e o meu apenas da ficha ficha em questão*/
#include "bigMain.h"
#include "m_Ficha1.h"
#include "m_Ficha2.h"
#include "m_Ficha3.h"
//#include "m_Ficha4.h"
//#include "m_Ficha5.h"
//#include "m_Ficha6.h"
//#include "m_Ficha7.h"
#include "m_50Primeiras.h"
#include "m_50Segundas.h"


/*
Concede ao utilizador a hipotse de ir para o menu principal OU ir para o menu da respetiva folha de exercicios em que está no momento!


ESTE FICHEIRO FOI CRIADO PARA NÃO TER QUE SE REPETIR ESTA FUNÇÃO EM TODAS AS FICHAS
*/

void menu_Ficha(int numFicha){
	
		switch(numFicha){
			case(1):
			system("clear");
			menu_Ficha1();
			break;//confirmar se este break faz alguma coisa aqui!
			
			case(2):
			system("clear");
			menu_Ficha2();
			break;

			case(3):
			system("clear");
			menu_Ficha3();
			break;
/*
			case(4):
			system("clear");
			menu_Ficha4();
			break;
			
			case(5):
			system("clear");
			menu_Ficha5();
			break;
*/


			/* ... */

	
			case(6):
			system("clear");
			menu_50Primeiras();
			break;

			case(7):
			system("clear");
			menu_50Segundas();
			break;

			/* Não precisa do default no swith porque õs valores passados para a escolha do case já sao verificados nos passos anteriores, dai não haver necessidade de usa-lo!*/
		}
	}


/*para o caso de o utilizador quiser ir para o menu principal ou manter-se na ficha atual (ficha1)*/
void encaminharPara(int x, int numFicha){/* encaminharPara(bigMain ou menuFicha(y),y = numero da ficha)*/

	if(x==1){
		menu_BigMain();//encaminha o utilizador para o ficheiro que detem a listagem das fichas e 50 exercicios
	}else{
		menu_Ficha(numFicha);/*assume-se que as fichas das 50questões(1º e 2ºas questões) são fichas 6 e 7 respetivamente*/
	}
}

/*QUESTAO IMPOSTA AO UTILIZADOR DEPOIS DE IMPRESSO O RESULTADO DO INPUT INSERIDO PARA QUALQUER QUESTÃO*/
void routingQuestion(int numFicha){
int x;	
		printf("\n\nDeseja voltar para o menu principal?\nSim - 1\nNao - 0\nOPCAO: "); 
		scanf("%d",&x);	

		if(x==1 || x==0){
			encaminharPara(x,numFicha); /*encaminharPara(menu principal -caso x=1 ou menu da ficha em que o numero da ficha que se quer ver o menu é o numFicha)*/
		}else{
			/*Para quando o utilizador insere uma opção invalida, i é, uma opção que não corresponda entre ir para o menu principal ou para o menu da ficha em que se encontra*/
			printf("Opção inválida!\n");
			getchar();
			getchar();
			system("clear");
			routingQuestion(numFicha);
		}	

}