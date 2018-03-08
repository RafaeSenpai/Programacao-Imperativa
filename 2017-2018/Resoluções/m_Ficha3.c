#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ficha3.h" /*API de todas as funções da ficha 1 */
#include "reRoutingEntreMenus.h" /*API da função de reencaminhamento entre o menu principal e o meu apenas da ficha 1*/
#include "bigMain.h" /*quando se quer incluir uma API propria usa-se as aspas ao contrario <API's padrao>*/
#include "m_Ficha3.h" 


void menu_Ficha3(){
int opt=-1;

	printf("Qual o exercicio da FICHA 3 que pretende executar?\n");
	scanf("%d",&opt);
		
	switch(opt){
		case(1):
		system("clear");
		/* pedir o input ao utilizador */
		/* dar o resultado ao utlizador invocando a função*/
		routingQuestion(3);/*é passado, 3, como numero da ficha, para que consoante o que o utlizador escolher seja ou não redirecionado para o menu da ficha 3*/


		




		default:
			printf("Input invalido!\n");
			getchar(); // apenas para fazer uma espera e o utilizador ler a mensagem ate repetir o menu
			getchar(); //-----PROCURAR ALTERNATIVA AO USO DE 2 GETCHAR SEGUIDOS
			system("clear");
			menu_Ficha3();
	
	}
}
