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
int cp();
char *capitaliza();
LLint nivel();
int gPrimeDiv();