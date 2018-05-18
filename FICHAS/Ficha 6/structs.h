#define MAX 100

typedef struct stack{
	int sp;
	int valores[MAX];
}STACK;


typedef struct queue{
	int inicio,tamanho;
	int valores[MAX];
}QUEUE;
