#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
	char nome[50];
	int numero;
	int nota;
	struct nodo *esq, *dir;
}*Alunos;

typedef struct strlist{
	char *string;
	struct strlist *prox;
} *StrList;





void imprimirTurma(Alunos turma){
Alunos l = turma;
		while(l!=NULL){
			printf("Numero:\n%d\n",l->numero);
			printf("Nome:\n%s\n",l->nome);
			printf("Nota:\n%d\n",l->nota);
			printf("__________________\n");
			imprimirTurma(l->esq);
			imprimirTurma(l->dir);
		}
		printf("Impressão concluida!\n");
}


Alunos inserirAluno(Alunos l, char nome[50], int numero, int nota){ /*A inserção é feita por ordem de numeração do aluno*/
Alunos turma = l;
Alunos novo = (Alunos) malloc(sizeof(struct nodo));
	
	if(turma==NULL){
		strcpy(novo->nome, nome);
		novo->numero = numero;
		novo->nota = nota;
		turma = novo;
	}else{
		if(numero < turma->numero){
			inserirAluno(turma->esq,nome,numero,nota);
		}else{
			inserirAluno(turma->dir,nome,numero,nota);	
		}
	}
	return l;
}

void addNome(char nome[50], StrList listagem){
	StrList lista = listagem;
	int tamanho = 0;
	for(tamanho=0; nome[tamanho]!='\0'; tamanho++);

	if(lista == NULL){
		lista = (StrList) malloc(sizeof(struct nodo));
		lista->string = (char*) malloc (sizeof(char)*(tamanho+1));

		strcpy(lista->string, nome);
		lista = lista->prox;
	}else{
		while(lista!=NULL){
			lista = lista->prox;
		}
		lista = (StrList) malloc(sizeof(struct nodo));
		lista->string = (char*) malloc (sizeof(char)*(tamanho+1));
		
		strcpy(lista->string, nome);
		lista = lista->prox;
	}
}

StrList alunosComNota(Alunos turma, int nota, StrList *listagem){
	Alunos a = turma;

	while(a!=NULL){
		if(a->nota ==nota){
			addNome(a->nome,*listagem);
		}else{
			alunosComNota(a->esq,nota,listagem);
			alunosComNota(a->dir,nota,listagem);
		}
	}
	return *listagem;
}


void listaAlunosComNota(StrList lista){
	StrList listagem = lista;

	if(listagem == NULL){
		printf("Lista vazia!\n");
	}else{
		printf("Lista de alunos com determinada nota:\n");
		while(listagem != NULL){
			printf("%s\n",listagem->string);
		}
		printf("Fim da listagem!\n");
	}
}


int tamanho (StrList listagem){
StrList lista = listagem;
int count = 0;
	
	if(lista == 0){
		return 0;
	}else{
		while (lista != NULL){
			count++;
			lista = lista->prox;
		}
	}
	return count;
}



int comNota(Alunos a, int nota, StrList *l){ /*este header tem que se manter pois e o que me é pedido no enunciado*/
Alunos turma = a;

	if(turma == NULL){
		return 0;
	}else{
		return tamanho(alunosComNota(a, nota,l));
	}
}


int main(){

Alunos turma = (Alunos) malloc(sizeof(struct nodo));
//char nome[50];
//int numero,nota,num;
char *lista = NULL;/*usado para listar os nomes dos alunos com determinadas notas*/ /*------------POSSIVELMENTE TERÁ QUE SER PASSADO COM APONTADOR NO ARGUMETO DAS FUNÇÕES ONDE É UTILIZADA*/


	turma = inserirAluno(turma,"Rafael",3,14);
	turma = inserirAluno(turma,"Luis",1,13);
	turma = inserirAluno(turma,"Marta",2,15);
	turma = inserirAluno(turma,"Hugo",5,16);
	turma = inserirAluno(turma,"Ricardo",4,14);
	turma = inserirAluno(turma,"Padrão",6,16);





/*

	printf("Quantos alunos a inserir?!\n");
	scanf("%d",&num);
	while(num>0){
		printf("Nome: ");
		scanf("%s\n",nome);
		getchar();
		printf("Numero: ");
		scanf("%d\n",&numero);
		getchar();
		printf("Nota: ");
		scanf("%d\n",&nota);
		getchar();
		inserirAluno(turma,nome,numero,nota);
		num--;
	}
*/
	printf("Elementos da turma\n");
	imprimirTurma(turma);

	printf("NUmero de alunos com nota 10\n");
	comNota(turma,10,*lista);


	printf("Lista de nomes dos alunos com nota 10\n");
	listaAlunosComNota(*lista);

}