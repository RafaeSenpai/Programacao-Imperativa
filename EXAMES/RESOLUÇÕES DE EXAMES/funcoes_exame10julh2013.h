/*EStruturas de dados usadas no exame*/
typedef struct llint{
	int valor;
	struct llint *prox;
}NodoL, *LLint;

typedef struct abint {
	int valor;
	struct abint *esq, *dir;
} NodoA, *ABint;

int elimRep();
int maximo();
int iguais();
//int cp();
char *capitaliza();
/*função extra (função abaixo) usada como auxiliar na interface e ẽm 'funcoes_exame10julh2013.c no exercicio 7*/
LLint addLLint(); 
LLint nivel();
int gPrimeDiv();