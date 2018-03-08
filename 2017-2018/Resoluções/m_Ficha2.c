#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ficha2.h" 
#include "reRoutingEntreMenus.h" /*API da função de reencaminhamento entre o menu principal e o meu apenas da ficha ficha em questão*/
#include "bigMain.h" /*quando se quer incluir uma API propria usa-se as aspas ao contrario <API's padrao>*/
#include "m_Ficha2.h" 


void menu_Ficha2(){
int opt=-1;
int x,y;

	printf("Qual o exercicio da FICHA 2 que pretende executar?\n");
	scanf("%d",&opt);
		
	switch(opt){
		case(1):
		system("clear");
		printf("Insira o valor a ser somado 'n' vezes:\n");
		scanf("%d",&x);
		printf("Insira o numero de vezes a ser somado o valor inserido anteriormente:\n");
		scanf("%d",&y);
		printf("O valor das somas consecutivas (multiplicação) é : %f \n",multInt(y,x));
		routingQuestion(2);/*2 -> Ficha2*/


		/*...restantes exercicios...*/
		




		default:
			printf("Input invalido!\n");
			getchar(); // apenas para fazer uma espera e o utilizador ler a mensagem ate repetir o menu
			getchar(); //-----PROCURAR ALTERNATIVA AO USO DE 2 GETCHAR SEGUIDOS
			system("clear");
			menu_Ficha2();
	
	}
}