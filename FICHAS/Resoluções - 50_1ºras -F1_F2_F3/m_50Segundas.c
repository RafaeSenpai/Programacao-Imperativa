/*MENU DAS SEGUNDOS 50 EXERCICIOS*/
#include <stdio.h>
#include <stdlib.h> /*necessário por causa dos warnnings do system("clear")*/
#include "reRoutingEntreMenus.h" /*API da função de reencaminhamento entre o menu principal e o meu apenas da ficha ficha em questão*/
#include "bigMain.h" /*quando se quer incluir uma API propria usa-se as aspas ao contrario <API's padrao>*/
#include "m_50Segundas.h" 
#include "50segundas.h" /*ao fazer este include além de se criar a api das funções aqui chamadas também se carrega ás estruturas de dados usadas nas funções*/
/*OBS: não é necessário fazer aqui o include das estruturas de dados, myStrucs.h, pois o include dessa mesma "biblioteca" está feito na API dos 50 exercicios, 50segundas.h.*/

void menu_50Segundas(){
int opt=-1;
int x;
LInt lintPredefinida = criarLInt();

	printf("Qual a função dos 50 segundos exercicios que pretende executar?\n");
	scanf("%d",&opt);
		
	switch(opt){
		case(1):
		system("clear");
		printLInt(lintPredefinida);
		printf("Comprimento da seguinte lista ligada é %d\n",myLength(lintPredefinida));
		routingQuestion(7); /*7 é o numero atribuido ás 50 segundas questoes*/


		case(2):
		system("clear");
		printf("Lista ligada usada:\n");
		printLInt(lintPredefinida);
		printf("Libertando a memoria ocupada pela lista ligada!\n");
		printf("Comprimento da lista ligada é %d\n",myLength(freeL(lintPredefinida)));
		routingQuestion(7); /*7 é o numero atribuido ás 50 segundas questoes*/

		case(3):
		system("clear");
		printf("Impressão da lista:\n");
		imprimeL(lintPredefinida);
		routingQuestion(7); /*7 é o numero atribuido ás 50 segundas questoes*/

		case(4):
		system("clear");
		printf("Lista antes da inversão:\n");
		imprimeL(lintPredefinida);
		printf("Lista apos a inversão:\n");
		imprimeL(reverseL(lintPredefinida));
		routingQuestion(7); 


		case(5):
		system("clear");
		printf("Lista\n");
		imprimeL(lintPredefinida);
		scanf("%d",&x);
		
		routingQuestion(7); /*7 é o numero atribuido ás 50 segundas questoes*/




		case(6):
		system("clear");
		printf("Valor a remover: ");
		scanf("%d",&x);
		printf("Lista antes da remoção:\n");
		imprimeL(lintPredefinida);
		printf("Confirmação de remoção(0-Foi removido; 1-Valor não existia na lista): %d\n",removeOneOrd(lintPredefinida,x));
//		printf("Lista apos a remoção:\n");
//		imprimeL(lintPredefinida);
		routingQuestion(7); 
	default:
		printf("Input invalido!\n");
		getchar(); // apenas para fazer uma espera e o utilizador ler a mensagem ate repetir o menu
		getchar(); //-----PROCURAR ALTERNATIVA AO USO DE 2 GETCHAR SEGUIDOS
		system("clear");
		menu_50Segundas();

	}
}
		
