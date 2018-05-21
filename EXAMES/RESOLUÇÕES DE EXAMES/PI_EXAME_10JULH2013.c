/*PROGRAMAÇÃO IMPERATIVA - EXAME DE RECURSO - 10 JULHO 2013*/
/*Interface*/
#include <stdio.h>
#include <stdlib.h>
#include "funcoes_exame10julh2013.h"


/*Estruturas usadas no exame*/
/*
typedef struct llint{
	int valor;
	struct llint *prox;
}NodoL, *LLint;

typedef struct abint {
	int valor;
	struct abint *esq, *dir;
} NodoA, *ABint;
*/




/*imprimir arrays - util para o exercicio 1 do exame*/
void printArray(int v[], int i){

	for(int j=0;j<i;j++){
		if(j==(i-2)){
			printf("%d",v[j]);
		}else{
			printf("%d - ",v[j]);
		}
	}
	printf("\n\n");
}





/*imprimir listas ligadas - util para o exercicio 2 do exame*/
void printLLigada(LLint a){

	if(a){
		while(a){
			if((a->prox)){
				printf("%d-->",a->valor);
			}else{
				printf("%d --> NULL\n",a->valor);
			}
			a = a->prox;
		}

		printf("\n\n");
	}else{
		printf("Lista ligada encontra-se vazia!\n");
		getchar();
	}
}






/*Adiciona um valor a uma lista ligada (previamente a lista ligada que é passada por parametro já se encontra inicializada na main)*/
LLint addLLint(int x, LLint a){
LLint new = malloc(sizeof(struct llint));

	if(new){
		new->valor = x;
		new->prox = a;
	}

return new;
}






/*preenche a lista ligada com os valores existentes no array*/
LLint preencheLLint(LLint l,int v[], int tam){

	for(int i = 0; i<tam; i++){
		l = addLLint(v[i],l);
	}
	return l;
}






/*criação de um nodo de uma arvore binaria*/
ABint newNodeABin(int x, ABint esq, ABint dir){
ABint new = malloc(sizeof(struct abint));

	if(new){
		new->valor = x;
		new->esq = esq;
		new->dir = dir;
	}
	return new;
}







/*Adiciona um nodo numa arvore binaria (Será uma ABP)*/
ABint addNodeABin(ABint a, int x){
ABint *p = NULL;
p = &a; /*  *p = &a <--ERRADO*/
	
	while((*p)){
		if(x < ((*p)->valor)){
			p = &((*p)->esq);
		}else if(x > (*p)->valor){
			p = &((*p)->dir);
		}else{
			if(x == (*p)->valor){
				return a;
			}
		}
	}
	(*p) = newNodeABin(x,NULL,NULL);

	return a;
}







/*preenche uma arvore binaria*/
ABint preencheABin(ABint a, int array[],int tam){

	for(int i = 0; i<tam; i++){
		a = addNodeABin(a,array[i]);
	}

return a;
}





/*Altura da arvore*/
#define max(a,b) (((a)<(b))?(a):(b))

int altura(ABint a){
int alt = -1;

	if(a){
		return alt = 1 + max(altura(a->esq), altura(a->dir));
	}

	return alt;
}

/*Imprimir arvore binaria por inorder*/
void printABins(ABint a){

	if(a){
		printf("Impressão INORDER de arvore binária:\n");
		while(a){
			printABins(a->esq);
			printf("%d =>",a->valor);
			printABins(a->dir);
		}
	}else{
		printf("Arvore encontra-se vazia!\n");
		getchar();
	}
}

/*Menu apresentado ao utilizador*/
int menu(){
int opt = -1;
		
	printf("1 - Exercicio 1\n");
	printf("2 - Exercicio 2\n");
	printf("3 - Exercicio 3\n");
	printf("4 - Exercicio 4\n");
	printf("5 - Exercicio 5\n");
	printf("6 - Exercicio 6\n");
	printf("7 - Exercicio 7\n");
	printf("8 - Exercicio 8\n");
	printf("9 - Sair\n\n");
	printf("SELECIONE O EXERCICIO DO EXAME A EXECUTAR: ");
	scanf("%d",&opt);

	if(opt >0 && opt<10){
		printf("Opção invalida!\n");
		getchar();
		menu();
	}

return opt;
}






/*A Main é responsavel pelo comportamento do programa após a escolha feita pelo utilizador com base na opção escolhida na função menu*/
int main(){
int opt = -1;
int array[10] = {1,2,2,3,4,5,3,3,6,7}; /*usado no exercicio 1*/
int vLLint[10] = {1,6,5,4,9,7,6,4,2,0}; /*valores deste array são usados para preencher a lista ligada usada no exercicio 2*/
int vABin1[11] = {10,15,12,4,43,24,13,121,25,11,3};/*Os vABin's usados no exercicio 3*/
int vABin2[11] = {10,15,12,4,43,24,13,121,25,11,3};/*vABin2 e vABin1 são iguais*/
int vABin3[15] = {10,15,12,4,43,99,13,121,25,11,3,7,45,87,2};/*este array é diferente dos dois anteriores!*/
char origem[10] = "origem.txt"; /*usado no exercicio 4*/
char destino[11] = "destino.txt";/*usado no exercicio 4*/
char frase[38] = "ola. passei a programacao. imperativa";/*Esta string é usada no exercicio 5*/
int xVal = -1; /*Variavel usada no exercicio 7*/


LLint l = malloc(sizeof(struct llint)); //inicia-se aqui a lista ara que nao seja necessária a sua verificação na função para onde a lista for passada
l = NULL;
l = preencheLLint(l,vLLint,10); //preencher a lista ligada previamente antes de qualquer operação com a mesma

ABint a = malloc(sizeof(struct abint));
a = NULL;
a = preencheABin(a,vABin1,11);

ABint b = malloc(sizeof(struct abint));
b = NULL;
b = preencheABin(b,vABin2,11);

ABint c = malloc(sizeof(struct abint));
c = NULL;
c = preencheABin(c,vABin3,15);


	while(opt!=9){
		system("clear");
		opt = menu();
		switch(opt){
			case(1):
			printf("Array original:\n");
			printArray(array,10);
			printf("NUmero de elementos no array após eliminar repetidos: %d",elimRep(array,10));
			getchar();
			main();

			case(2):
			printf("Lista ligada avaliada:\n");
			printLLigada(l);
			printf("O maior valor armazenado na lista ligada é: %d", maximo(l));
			getchar();
			main();

			case(3):
			printf("Arvores a comparar:\n");
			printf("Arvore A:\n");
			printABins(a);
			printf("Arvore B:\n");
			printABins(b);
			printf("Confirmação de se as das arvores A e B são ou não iguais: %d\n",iguais(a,b));
			printf("OBS: 1 - As arvores comparadas são iguais;\n0 - As arvores são diferentes.\n");
			getchar();
			printf("Confirmação de se as das arvores A e C são ou não iguais: %d\n",iguais(a,c));
			printf("OBS: 1 - As arvores comparadas são iguais;\n0 - As arvores são diferentes.\n");
			main();


			case(4):
			if(cp(origem,destino) == 0){
				printf("A copia do conteudo do ficheiro de origem foi copiada com sucesso para o ficheiro destino!\n");
				getchar();
			}else{
				printf("A copia do conteudo do ficheiro NÃO foi bem sucedida!\n");
				getchar();
			}
			main();	

			case(5):
			printf("A frase a ser tratada é:\n %s",frase);
			printf("Apos a aplicação da função 'capitaliza' a frase fica: %s\n",capitaliza(frase));
			/*a função capitalizada será modificada de 'void' para 'char*', para que devolva a string e esta seja apresentada no segundo print*/
			getchar();
			main();

			case(6):
			printf("Não percebi muito bem este exercicio!\n");
			getchar();
			main();

			case(7):
			printf("A arvore onde serao capturados os valores é a seguinte:\n");
			printABins(c);
			printf("Insira o nivel da arvore a que quer fazer a captura dos valores:\n");
			printf("OBS: Assume-se que a raiz da arvore está ao nivel 1\n");
			scanf("%d",&xVal);
			printf("Os valores encontrados no nivel %d da arvore 'C' são: ",xVal);
			printLLigada(nivel(vABin3,xVal));
			getchar();
			main();

			case(8):
			printf("Insira um valor inteiro maior u igual a 2: ");
			scanf("%d",&xVal);
			printf("O maior numero primo que é divisor por %d é: %d",xVal,gPrimeDiv(xVal));
			getchar();
			main();


			default:
			printf("Opção não é válida!\n");
			getchar();
			system("clear");
			main();

		}
	}
}