#include <stdio.h>
#include <stdlib.h>//dá jeito por causa do exit()
#include <string.h>
#include "bigMain.h"
#include "m_Ficha1.h"//onde se encontra a função menu_Ficha1()
#include "m_Ficha2.h"
//#include "m_Ficha3.h"
//#include "m_Ficha4.h"
//#include "m_Ficha5.h"
//#include "m_Ficha6.h"
#include "m_50Primeiras.h"


void menu_BigMain(){
int opt=-1;

	system("clear");
	printf("Escolha ma das opções:\n\n");
	printf("1 - Ficha 1\n2 - Ficha 2\n3 - Ficha 3\n4 - Ficha 4\n5 - Ficha 5\n6 - 1º(as) 50 Perguntas\n7 - 2ª(as) 50 perguntas\n8 - Sair!\nOPCAO:");
	scanf("%d",&opt);

	switch(opt){
		case(1):
		system("clear");
		menu_Ficha1();
		break;//confirmar se este break faz alguma coisa aqui!
		
		case(2):
		system("clear");
		menu_Ficha2();
		break;
/*
		case(3):
		system("clear");
		menu_Ficha3();
		break;

		case(4):
		system("clear");
		menu_Ficha4();
		break;
		
		case(5):
		system("clear");
		menu_Ficha5();
		break;
*/		
		case(6):
		system("clear");
		menu_50Primeiras();
		break;
/*
		case(7):
		system("clear");
		menu_50segundas();
		break;
*/	
		

		case(8):
		system("clear");
		exit(0); /* ??????????? perceber o significado do valor passado ao exit???????*/

		default:
			printf("Input invalido!\n");
			getchar(); //-----PROCURAR ALTERNATIVA AO USO DE 2 GETCHAR SEGUIDOS
			getchar();
			system("clear");
			menu_BigMain();

	}
}


int main(){
	menu_BigMain();
	return 0;
}