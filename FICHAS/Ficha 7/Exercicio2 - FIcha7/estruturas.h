/*Estrutura usada para o exercio 2*/

typedef struct aluno *Turma;

typedef struct aluno {
	char nome[60];
	int numero;
	float nota;
	Turma prox;
} Aluno;
