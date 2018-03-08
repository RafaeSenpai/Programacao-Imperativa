#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ficha1.h" /*API de todas as funções da ficha 1 */
#include "reRoutingEntreMenus.h" /*API da função de reencaminhamento entre o menu principal e o meu apenas da ficha ficha em questão*/
#include "bigMain.h" /*quando se quer incluir uma API propria usa-se as aspas ao contrario <API's padrao>*/
#include "m_Ficha1.h" 


//menu da Ficha 1 que lista ao utilizador os respetivos exercicios da mesma
void menu_Ficha1(){
int opt=-1;
int x;

	printf("Qual o exercicio da FICHA 1 que pretende executar?\n");
	scanf("%d",&opt);
		
	switch(opt){
		case(1):
		system("clear");
		printf("Este exercicio não é aplicavel no terminal!\n");
		getchar();
		getchar();
		system("clear");
		menu_Ficha1();


		case(2):
		system("clear");

		printf("Insira o tamanho da matriz quadrada a preencher:\n");
		scanf("%d",&x);
		exercicio2_F1(x);
		routingQuestion(1);


		case(3):
		system("clear");

		printf("Insira o tamanho do tabuleiro de xadrez:\n");
		scanf("%d",&x);
		exercicio3_F1(x);
		routingQuestion(1);



		case(4):
		system("clear");

		printf("Triangulo Horizontal\nInsira a altura do triangulo:");
		scanf("%d",&x);
		printf("\n");
		trianguloHorizontal(x);
		routingQuestion(1);



		/*NÃO FOI FEITO O EXERCICIO DO TRIANGULO VERTICAL*/
		
		default:
			printf("Input invalido!\n");
			getchar(); // apenas para fazer uma espera e o utilizador ler a mensagem ate repetir o menu
			getchar(); //-----PROCURAR ALTERNATIVA AO USO DE 2 GETCHAR SEGUIDOS
			system("clear");
			menu_Ficha1();
	
	}
}