#include <stdio.h>

typedef struct entrada{
	char *palavra;
	int ocorr;
	struct entrada *prox;
} *Palavras;


int main (int argc, char *argv[]){
FILE *input;
int r=0, count=0;
char word[100];
	
	if (argc==1){
		input=stdin;
	}else{
		input=fopen(argv[1],"r");
	}


	if (input==NULL){
		r=1;
	}else{
		while ((fscanf(input,"%s",word)==1)){
			count ++;
		}
	fclose (input);
	printf ("%d palavras\n", count);
	}

return r;
}