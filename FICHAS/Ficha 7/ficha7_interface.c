#include <stdio.h>
#include "estruturas.h"
#include "ficha7_interface.h"
#include "ficha7_funcoes.h"
#include "myInputs.h"


int menu(){
int opt,x;

	system("clear");
	printf("Escolha ma das opções:\n\n");
	printf("1 - Exercicio 1a)\n2 - Exercicio 1b)\n3 - Exercicio 1c)\n4 - Exercicio 1d)\n5 - Exercicio 1e)\n6 - Imprimir lista ligada atual\n7 - Sair\nOPÇÃO: ");
	//printf("7 - Exercicio 2b) - Inserir um aluno na turma\n8 - Exercicio 2c) - Procurar um aluno com um dado o numero de aluno\n9 - Imprimir lista ligada de teste\n10 - Exercicio 2d) - Numero de aprovados na turma\n11 - EXTRA - Sobre apontadores\n12 - Sair!\nOPCAO:");
	scanf("%d",&opt);

	switch(opt){
		case(1):
		system("clear");
		while(x!=0){
			printf("Insira o valor que quer colocar no inicio da lista ligada: (0 - para terminar inserções)");
			scanf("%d",&x);
			lista = myCons(lista,x);
			system("clear");
		}
		printLINTS(lista);
		getchar();
		getchar();
		menu();
		break;



		case(2):
		system("clear");
		printf("Lista passada por parametro:\n");
		printLINTS(l1);
		printf("Apoś aplicar a função tail:\n");
		printLINTS(myTail(l1));
		getchar();
		getchar();
		menu();
		break;



		case(3):
		system("clear");
		printf("Lista passada por parametro:\n");
		printLINTS(l1);
		printf("Lista com  ultimo elemento da lista removido:\n");
		printLINTS(myInit(l1));
		getchar();
		getchar();
		menu();
		break;



		case(4):
		system("clear");
		while(x!=0){
			printf("Insira valores que serão colocados no final da lista ligada: (0 - para terminar inserções)");
			scanf("%d",&x);
			lista = mySnoc(lista,x);
		}
		system("clear");
		printLINTS(lista);
		getchar();
		getchar();
		menu();
		break;



		case(5):
		system("clear");
		printf("Listas passadas por parametro:\n");
		printf("1º Lista ligada: ");
		printLINTS(l1);
		printf("\n2º Lista ligada: ");
		printLINTS(l2);
		printf("\nResultado da aplicação da função 'concat'(adicionando os elementos da lista 'b' á lista 'a'): \n");
		printLINTS(myConcat(l1,l2));
		menu();
		break;



		case(6):
		system("clear");
		printLINTS(l1);
		getchar();
		getchar();
		menu();
		break;

		case(7):
		system("clear");
		exit(0); 

		default:
			printf("Input invalido!\n");
			getchar(); 
			getchar();
			system("clear");
			menu();
		}

	return 0;

}
