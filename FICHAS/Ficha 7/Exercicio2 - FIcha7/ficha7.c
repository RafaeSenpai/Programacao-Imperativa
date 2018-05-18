/*Main/interface do Exercicio 2 da ficha 7*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "estruturas.h"
#include "ficha7_funcoes.h"
#include "ficha7.h"

int menu(){
int opt=-1;
int num;
float nota;
char nome[60];
Aluno person;
Turma trm= NULL;
		
	while(opt!=0){
		system("clear");
		printf("Escolha ma das opções:\n\n");
		printf("1 - Exercicio 2b)\n2 - Exercicio 2c)\n3 - Exercicio 2d)\n6 - Imprimir turma\n7 - Imprimir turma(passando por apontador)\n8 - sair\n\n");
		scanf("%d",&opt);

		switch(opt){
			case(1):
			system("clear");
			system("clear");
			
			printf("Inserir um aluno na turma: \n");
			getchar();
			getchar();
			printf("Nome: ");
			scanf("%s",nome);
			printf("Numero de aluno: ");
			scanf("%d",&num);
			printf("Nota: ");
			scanf("%f",&nota);
			
			strcpy(person.nome,nome);
			person.numero = num;
			person.nota = nota;

			printf("1 - Não foi inserido; 0 - Foi inserido; -- Valor logico: %d\n",acrescentaAluno(&trm,person));
			printf("Ficha do aluno que foi inserido:\n");
			getFichaAluno(person);
			getchar();
			getchar();
			printf("Turma atual:\n");
			printTurma2(trm);
			getchar();
			menu();
			break;


			case(6):
			getchar();
			system("clear");
			printf("Imressão da turma corrente:\n");//recebendo apontador
			printTurma1(&trm);
			getchar();
			menu();
			break;



			
			case(7):
			getchar();
			system("clear");
			printf("Imressão da turma corrente:\n");
			printTurma2(trm);//TRM é um endereço de um apontador
			getchar();
			menu();
			break;



			case(8):
			system("clear");
			getchar();
			exit(1);
		
	
			default:
			printf("Input invalido!\n");
			getchar(); 
			getchar();
			system("clear");
			menu();
		}
	}
}

int main(){
	menu();
return 0;
}
