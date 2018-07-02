/*Parte A*/

/*Questão 1*/
char *mystrcat (char s1[], char s2[]){
int i,j;

	for(i=0;s1[i]!='\0';i++);

	for(j=0;s2[j]!='\0';j++,i++){
		s1[i]=s2[j];
	}
	s1[i++]='\0';

return s1;
}

/*QUESTAO 2*/
int remRep(char x[]){
char str[strlen (x)];
int j=0;
int i=0;
str[j]=x[i];

	for(i=0;x[i]!='\0';i++){
		if(x[i]!=str[j]){
			j++;
			str[j]=x[i];
		}
	}
	j++;
	str[j]='\0';

	for(i=0; str[i]!='\0';i++){
		x[i]=str[i];
	}
	i++;
	str[i]!='\0';

	return i;
}

/*EXERCICIO 3*/
int nivelVAux (ABin a, int n, int v[],int indice) {

    if(a!=NULL){
        
        if(n==0){
            v[indice]=a->valor;
            indice++;;
        }
        
        nivelVAux(a->esq,n-1,v,indice);
        nivelVAux(a->dir,n-1,v,indice);
    }
   
return indice;
}


int nivelV (ABin a, int n, int v[]) {

return nivelVAux(a,n,v,0);

}




/*EXERCICIO 4*/
int addOrd(ABin *a,int x){
int flag = 0;

	while(*a && flag==0){
		if(x < (*a)->valor){
			a = &((*a)->esq);
		}else if(x > (*a)->valor){
			a = &((*a)->dir);
		}else{
			if(x == (*a)->valor){
				flag = 1;
			}
		}
	}

	if(flag!=1){
		ABin new = malloc(sizeof(struct nodo));
		new->valor = x;
		new->esq = NULL;
		new->dir = NULL;
		*a = new;
	}
return flag;
}


/*PARTE B*/
typedef struct listaC {
	int coluna;
	float valor;
	struct listaC *prox;
} *Colunas;

typedef struct listaL {
	int linha;
	Colunas lcol;
	struct listaL *prox;
} *Mat;


/*QUESTÃO 1*/
float getEntry(Mat m,int linha, int coluna){
int flag = 1;
float valor = 0;;	
	if(m){
		while(m->linha<=linha && flag==1){
			if(m->linha==linha){
				flag=0;
			}
			m = m->prox;
		}

		if(flag==0){
			flag=1;

			Colunas cln = malloc(sizeof(struct listaC));
			cln = m->lcol;
			while(cln->coluna<=coluna && cln->prox && flag==1){
				if(cln->coluna == coluna){
					flag=0;
					valor = cln->valor;
				}
				cln = cln->prox;
			}
		}
	}
	return val;
}


/*QUESTÃO 2*/
void setEntry (Mat *m, int linha, int coluna, float valor){
int flag = 1;

	if(*m){
		while((*m)->linha<=linha && flag==1){
			if((*m)->linha==linha){//quando é encontrada a respetiva linha em que se quer inserir o valor
				flag=0;
			}
			if(flag==0){
				flag=1;
				if((*m)->lcol){
					Colunas *cln;
					cln = &((*m)->lcol); //isto porque lcol é um apontador para uma estrutura tipo coluna(CONFIRMAR!!!???)
					while((*cln)->coluna<=coluna && (*cln)->prox && flag==1){
						if((*cln)->coluna==coluna){//quando se encontra a coluna em que se quer inserir o valor
							(*cln)->valor=valor; //altura em que é substiruido o valor já ecistente na matriz
							flag=0;
						}
						cln=&((*cln)->prox);
					}

					if(flag==1){//quando o valor nao é encontrado nas colunas e então é criada uma nova coluna com o valor mantendo a ordem das mesmas
						Coluna newColum = malloc(sizeof(struct listaC));
						if(newColum){
							newColum->valor = valor;
							newColum->prox = (*cln)->prox;
							(*cln) = newColum;
							flag=0;
						}
					}
				}
			}
			m = &((*m)->prox);
		}

		if(flag==1 && (*m)){ //não encontrou nem a linha nem a coluna no inteiror da matriz mas também nao chegou a percorrer toda a matriz(quando parou numa linha de "numero" maior)
			Mat newLinha = malloc(sizeof(struct listaL));
			if(newLinha){
				newLinha->linha = linha;
				Colunas newColum = malloc(sizeof(struct listaC));
				if(newColum){
					newColum->coluna = coluna;
					newColum->valor = valor;
					newColum->prox = (*m)->prox;
					newLinha->lcol = newColum; 
				}
				(*m)=newLinha;
			}
		}
	}else{//quando é pedido para inserir o valor numa matriz a NULL
		Mat newLinha = malloc(sizeof(struct listaL));
		if(newLinha){
			newLinha->linha = linha;
			Colunas newColum = malloc(sizeof(struct listaC));
			if(newColum){
				newColum->coluna = coluna;
				newColum->valor = valor;
				newColum->prox = NULL;
				newLinha->lcol = newColum;
			}
		}		
	}
}


