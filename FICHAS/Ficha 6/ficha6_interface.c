#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "estruturas.h"
#include "ficha7_funcoes.h"

int menu(){
int opt = -1;
int x;
STACK *s = malloc(sizeof(STACK));
QUEUE *q = malloc(sizeof(QUEUE));

	if(!s || !q){
		printf("Memória indisponivel!\n");
		getchar();
	}else{
		system("clear");
		printf("Escolha ma das opções:\n\n");
		printf("---STACK---\n1 - Exercicio 1a)\n2 - Exercicio 1b)\n3 - Exercicio 1c)\n4 - Exercicio 1d)\n5 - Exercicio 1e)\n6 - Imprimir stack pointer\n7 - Imprimir stack atual\n\n");
		printf("---QUEUE---\n8 - Exercicio 2a)\n9 - Exercicio 2b)\n10 - Exercicio 2c)\n11 - Exercicio 2d)\n12 - Exercicio 2e)\n13 - Imprimir QUEUE\n14 - Sair\nOPCAO:\n\n");
		scanf("%d",&opt);

		switch(opt){
			case(1):
			system("clear");
			system("clear");
			printf("Inicializar a stack-Prima OK!\n");
			getchar();
			getchar();
			initStack(s);
			printf("Stack inicializada!\n");
			getchar();
			menu();
			break;


			
			case(2):
			getchar();
			system("clear");
			if(isEmptyS(s)==0){
				printf("A stack encontra-se vazia!\n");
				getchar();
			}else{
				printf("A stack não se encontra vazia!\n");
				getchar();
			}
			system("clear");
			menu();
			break;



			case(3):
			system("clear");
		
			printf("Insira o valor que quer colocar na stack!\n");
			scanf("%d",&x);
			if(mypush(s,x)==0){
				printf("Valor inserido com exito na stack!\n");
				getchar();
				getchar();
			}else{
				printf("O valor não foi inserido na stack!\n");
				getchar();
				getchar();
			}
			system("clear");
			menu();
			break;



			case(4):
			system("clear");
			printf("Valor logico recebido: %d\n",mypop(s,&x));
			printf("O valor resultante do pop para a variavel x é: %d",x);
			getchar();
			getchar();
			menu();
			break;


			case(5):
			system("clear");
			printf("Valor logico recebido: %d\n",mytop(s,&x));
			printf("O valor que se encontra no topo da stack é: %d",x);
			getchar();
			getchar();
			menu();
			break;



			case(6):
			system("clear");
			printf("O valor do stack pointer é: %d", s->sp);
			getchar();
			getchar();
			menu();
			break;



			case(7):
			system("clear");
			imprimeSTACK(s);
			getchar();
			getchar();
			menu();
			break;

			case(8):
			system("clear");
			printf("Inicializar queue!\n");
			getchar();
			printf("Inicializando...");
			initQueue(q);
			printf("Queue inicializada!\n");
			getchar();
			menu();
			break;

			case(9):
			system("clear");
			printf("Verificar se a queue se encontra vazia!\n");
			if(isEmptyQ(q)==0){
				printf("A QUEUE encontra-se vazia!\n");
				getchar();
				getchar();
				menu();
			}else{
				printf("A QUEUE contém elementos!\n");
				getchar();
				getchar();
				menu();
			}
			break;

			case(10):
			system("clear");
			printf("Adicionar elemento á QUEUE!\n");
			printf("Valor a inserir na QUEUE: ");
			scanf("%d",&x);
			if(enqueue(q,x)==0){
				printf("Valor inserido com sucesso!\n");
				getchar();
				menu();
			}else{
				printf("Ocorreu um erro na inserção do valor na QUEUE!\n");
				getchar();
				menu();
			}
			break;


			case(11):
			system("clear");
			printf("Remover um  elemento do topo da QUEUE!\n");
			if(dequeue(q,&x)==0){
				printf("Valor removido com sucesso!\n");
				printf("O valor removido foi: %d\n",x);
				getchar();
				getchar();
				menu();
			}else{
				printf("A QUEUE encontra-se vazia!\n");
				getchar();
				getchar();
				menu();
			}
			break;


			case(12):
			system("clear");
			if(frontQ(q,&x)==0){
				printf("O valor que se encontra no topo da QUEUE é: %d",x);
				getchar();
				getchar();
				menu();
			}else{
				printf("A QUEUE não contém valores!\n");
				getchar();
				getchar();
				menu();
			}
			break;


			case(13):
			system("clear");
			printf("Conteudo da QUEUE:\n");
			imprimeQUEUE(q);
			getchar();
			getchar();
			menu();
			break;

			case(14):
			system("clear");
			getchar();
			exit(0);
			break;




			default:
				printf("Input invalido!\n");
				getchar(); 
				system("clear");
				menu();
			}
		}
		
	return 0;

}
