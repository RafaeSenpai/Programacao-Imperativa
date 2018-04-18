#include <stdlib.h>
#include <stdio.h>
#include <string.h>/*para usar a função strcpy() que é invocada no exercicio 2 b)*/
/*EStrutura de dados usada para o exercico 1*/
typedef struct slist *LInt;

typedef struct slist {
	int valor;
	LInt prox;
} Nodo;



/*Estrutura usada para o exercio 2*/
/*Exercicio2 a)*/
typedef struct aluno *Turma;

typedef struct aluno {
	char nome[60];
	int numero;
	float nota;
	Turma prox;
} Aluno;




Turma t = NULL;
		
/*função auxiliar - impressão da lista ligada!*/
void printLInt(LInt x){
LInt temp = x;
	
		while(temp!=NULL){
			if(temp->prox!=NULL){
				printf("%d -> ", temp->valor);
				temp = temp->prox;
			}else{
				printf("%d\n",temp->valor);
				temp=temp->prox;
			}
		}
}



/*Exercicio1 a)*/
LInt cons(LInt l, int x){
LInt new = malloc(sizeof(struct slist));

	if(!new){
		printf("Erro de alocação de memória!\n");
		return 0;
	}

	new->valor=x;
	new->prox=l;

	return new;
}



/*Exercicio1 b)*/
LInt mytail(LInt l){
LInt cabeca;

	cabeca = l->prox;
	free(l);
	l=cabeca;
	return l;
}

/*Exercicio1 c)*/
LInt myinit(LInt l){
LInt tmp=l;

	while(tmp->prox!=NULL){
		tmp=tmp->prox;
	}
	free(tmp);

return l;
}

/*Exercicio1 d)*/
LInt mysnoc(LInt l, int x){
LInt anterior=NULL;
LInt aux=NULL;
aux = l;
LInt new = malloc(sizeof(struct slist));
	
	if(!new){
		printf("Erro de alocação de memória!\n");
		return 0;
	}

	new->valor = x;
	new->prox = NULL;

	if(aux==NULL){
		l=new;
		return l;
	}else{
		while(aux!=NULL){
			anterior=aux;
			aux=aux->prox;
		}
		anterior->prox = new;
	}
return l;
}

/*exercicio1 e)*/
LInt myconcat(LInt a, LInt b){
LInt aux = a;

	while(aux->prox!=NULL){
		aux = aux->prox;
	}
	aux->prox = b;

	return a;
}

//----------------função auxiliar para a 2º versão do myconcat-----------------
LInt newLInt(LInt l, int x){
LInt aux = l;
LInt new = malloc(sizeof(struct slist));

	if(!new){
		printf("Erro de alocação de memoria!\n");
	}else{
		new->valor = x;
	}

	if(aux==NULL){
		new->prox=NULL;
		l=new;
		return l;
	}else{
		while(aux->prox!=NULL){
			aux=aux->prox;
		}
		aux->prox=new;
		new->prox=NULL;
		return l;
	}
}

LInt myconcat2(LInt a, LInt b){
LInt auxA = a;
LInt auxB = b;

	while(auxA->prox!=NULL){
		auxA=auxA->prox;
	}
	auxA->prox=auxB;
	if(auxB!=NULL){
		while(!auxB){
			auxA=newLInt(auxA,auxB->valor);
			auxB=auxB->prox;
		}
		auxA->prox=NULL;
	}
	return a;
}

/*Função auxiliar de impressão de uma turma*/
void printTurma(Turma t){
Turma aux2 = t;
	if(aux2==NULL){
		printf("Turma vazia!\n\n\n");
	}
	while(aux2){
		printf("Nome: %s\n",aux2->nome);
		printf("Numero: %d\n",aux2->numero);
		printf("Nota: %f\n",aux2->nota);
		printf("------------------------------\n");
		aux2=aux2->prox;
	}
}
/*Exercicio 2b)*/
int acrescentaAluno(Turma *t, Aluno a){
Turma *aux = t;

	if(!(aux)){
		(aux)=&a;
		return 0;
	}else{
		while((aux)->prox){
			(aux)=(aux)->prox;
		}
		(aux)->prox = &a;
		return 0;
	}
	return 1;
}



/*Exercicio 2c)*/
Aluno *procura(Turma t, int num){
Turma aux=t;

	if(aux==NULL){
		return NULL;
	}else{
		while(aux){
			if(aux->numero==num){
				return aux;
			}else{
				aux=aux->prox;
			}
		}
	}
	return NULL;	
}


/*Função auxiliar de impressão de ficha de um aluno*/
void printFichaAluno(Aluno a){ //as setas usam-se para apontadores que apontam para structs, os pontos usam-se para structs
	printf("Nome: %s\n",a.nome);
	printf("Numero: %d\n",a.numero);
	printf("Nota: %f\n",a.nota);
}

/*Exercicio 2d)*/
int numAprovados(Turma t){
Turma aux = t;
int count=0;

	if(!aux){
		return 0;
	}else{
		while(aux){
			if(aux->nota>=10){
				count++;
			}
			aux=aux->prox;
		}
	}
return count;
}

int main(){
char name[60];
int num;
float class;
int x=1;
int opt = -1;
LInt l1 = malloc(4*sizeof(struct slist));
l1 = cons(cons(cons(cons(NULL,1000),999),998),997);
LInt l2 = malloc(5*sizeof(struct slist));
l2 = cons(cons(cons(cons(cons(NULL,2996),2997),2998),2999),3000);
LInt lista = malloc(sizeof(struct slist));
lista = NULL;

	system("clear");
	printf("Escolha ma das opções:\n\n");
	printf("1 - Exercicio 1a)\n2 - Exercicio 1b)\n3 - Exercicio 1c)\n4 - Exercicio 1d)\n5 - Exercicio 1e)\n6 - Imprimir turma atual\n7 - Exercicio 2b) - Inserir um aluno na turma\n8 - Exercicio 2c) - Procurar um aluno com um dado o numero de aluno\n9 - Imprimir lista ligada de teste\n10 - Exercicio 2d) - Numero de aprovados na turma\n11 - Sair!\nOPCAO:");
	scanf("%d",&opt);

	switch(opt){
		case(1):
		system("clear");
		while(x!=0){
			printf("Insira o valor que quer colocar na lista ligada: (0 - para terminar inserções)");
			scanf("%d",&x);
			lista = cons(lista,x);
			system("clear");
		}
		printLInt(lista);
		getchar();
		getchar();
		main();
		break;



		case(2):
		system("clear");
		printf("Lista passada por parametro:\n");
		printLInt(l1);
		printf("Apoś aplicar a função tail:\n");
		printLInt(mytail(l1));
		getchar();
		getchar();
		main();
		break;



		case(3):
		system("clear");
		printf("Lista passada por parametro:\n");
		printLInt(l1);
		printf("Lista com  ultimo elemento da lista removido:\n");
		printLInt(myinit(l1));
		getchar();
		getchar();
		main();
		break;



		case(4):
		system("clear");
		while(x!=0){
			printf("Insira o valor que quer colocar na lista ligada: (0 - para terminar inserções)");
			scanf("%d",&x);
			lista = mysnoc(lista,x);
			system("clear");
			
		}
		printLInt(lista);
		getchar();
		getchar();
		main();
		break;



		case(5):
		system("clear");
		printf("Listas passadas por parametro:\n");
		printf("1º Lista ligada: ");
		printLInt(l1);
		printf("\n2º Lista ligada: ");
		printLInt(l2);
		printf("\n\nResultado da aplicação da função 'concat'(ligando a lista 'b' á 'a'): \n");
		printLInt(myconcat(l1,l2));
		printf("\nResultado da aplicação da função 'concat'(adicionando os elementos da lista 'b' á lista 'a'): \n");
		printLInt(myconcat2(l1,l2));
		main();
		break;



		case(6):
		system("clear");
		printTurma(t);
		getchar();
		getchar();
		main();
		break;



		case(7):
		system("clear");
		printf("Turma antes da inserção do novo aluno:\n");
		printTurma(t);
		printf("Inserir novo aluno na turma(atribuir numero zero a aluno para terminar a inserção):\n");

			getchar();
			printf("\nNome: ");
			scanf("%s",name);
			printf("\nNumero: ");
			scanf("%d",&num);
			printf("\nNota: ");
			scanf("%f",&class);
			system("clear");


			Aluno novo;
			strcpy(novo.nome,name);
			novo.numero=num; /*Aluno é um acesso direto a uma estrutura de dados, Aluno. Daí o recurso ao (.) ponto para referenciar o parametro da estrutura a aceder*/
			novo.nota=class;
			novo.prox=NULL;
		
			printf("Confirmação da adição do aluno na turma (0 - Operação executada com sucesso): %d\n",acrescentaAluno(&t,novo));
			getchar();
	



		printf("Turma após a inserção do aluno:\n\n");
		printTurma(t);
		getchar();
		main();
		break;



		case(8):
		system("clear");
		printf("Turma a efetuar procura:\n");
		printTurma(t);
		printf("Insira o numero de aluno que quer procurar na turma: ");
		scanf("%d",&num);
		printf("A informação do aluno encontra-se no endereço %d\n\n",*procura(t,num));
 		getchar();
		printf("A informação que se encontra no endereço de memoria %d é:\n",*procura(t,num));
		printFichaAluno(*procura(t,num));
		getchar();
		getchar();
		main();
		break;



		case(9):
		system("clear");
		printLInt(l1);
		getchar();
		getchar();
		main();
		break;



		case(10):
		system("clear");
		printf("O numero de alunos aprovados é de %d alunos\n",numAprovados(t));
		getchar();
		break;


		case(11):
		system("clear");
		exit(0); 

		default:
			printf("Input invalido!\n");
			getchar(); 
			getchar();
			system("clear");
			main();
		}

	return 0;

}


