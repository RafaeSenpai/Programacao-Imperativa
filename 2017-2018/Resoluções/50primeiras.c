#include <stdio.h>
#include <stdlib.h>/*apesar de funcionar sem este include,com ele incluido, evita-se os warnings por causa das alocações de memoria(mallocs)*/
#include <string.h>/*apesar de funcionar sem este include,com ele incluido, evita-se os warnings por causa do uso da função "strlen"*/
#include <math.h> /*para usar as funções sqrt e pow no exercicio 49*/
#include "bigMain.h"/*quando se quer incluir uma API propria usa-se as aspas ao contrario <API's padrao>*/
#include "50primeiras.h"/*contem os headers de todas as primeiras 50 funções*/
#include "m_50Primeiras.h"/*header da função que contem praticamente toda a interface necessária para as primeiras 50 questoes*/
#include "myStructs.h"/*para incluir as estruturas de dados criadas para os exercicios 47,48,49,50*/

/*exercicio1*/
int maiorELemSequecia(){
int x = -1;
int t=0;	

	while(x!=0){
		scanf("%d",&x);
		(x>=t)?(t=x):(t);
	}

return t;
}

/*exercicio2*/
double mediaValoresSequencia(){
int x = -1;
double total = 0;
double count = 0;

	while(x!=0){
		count++;
		scanf("%d",&x);
		total += x;
	}

return (total/(count-1));
}


/*exercicio3*/
int segMaior(){
int x=-1;
int maior = 0;
int segMaior = 0;

	while(x!=0){
		scanf("%d",&x);
		if(x>=maior){
			segMaior = maior;
			maior = x;
		}else if (x<maior && x>segMaior){
			segMaior = x;
		}
	}

	return segMaior;
}


/*exercicio4*/
int bitsUm(unsigned int n){
int numBits = 0;

	while(n>=1){
		if(n%2==1){
			numBits++;
			n=n/2;
		}else{
			n=n/2;
		}
	}
	return numBits;
}


/*exercicio5*/ //NOTA: O que nos é pedido é o numero de bits a zero(menos significativos) a partir do bit a 1 mais significativo
int trailingZ (unsigned int n){
int count=0;

    while(n>=2 && n%2==0){
        count++;
        n=n/2;
    }
    return count;
}

/*exercicio6*/
int qDig (unsigned int n){
int nDigitos = 0;

	while(n>=1){
		nDigitos++;
		n = n/10;
	}
	return nDigitos;
}

/*exercicio7*/ //--------------------------------------------------------------------------------------------diz que não retorna output no teste online
char *mystrcat (char s1[], char s2[]){
int i,j;

	for (i=0; s1[i]!='\0';i++);
	for (j=0;s2[j]!='\0';j++){
		s1[i]=s2[j];
		i++;
	}
	
	return s1;
}

/*exercicio8*/ //--------------------------------------------------------------------------------------------dá errado nos testes online
char *mystrcpy (char *dest, char source[]){
int tam, i;
	
	for(tam = 0; source[tam]!='\0';tam++);
	
	dest = malloc (tam * sizeof(char));	
	
	for(i = 0; source[i]!='\0'; i++){
		dest[i]=source[i];
	}
	
/*	i++;
	dest[i]='\0';
*/
	return dest;
}


/*exercicio9*/
int mystrcmp (char s1[], char s2[]){
int i,x,y;
	
	for(x=0; s1[x]!='\0';x++){};
	for(y=0; s2[y]!='\0';y++){};

		for(i=0; s1[i]!='\0';i++){
			if(s1[i]<s2[i]){
				return (-1);
			}else if(s1[i]>s2[i]){
				return 1;
			}
		}

	 if (x<y){
	 	return -1;
	 }else if (x>y){
	 	return 1;
	 }

	 return 0;
}	


/*exercicio10*/ //---------------------------------------------------------------------------------------------Falha em apenas 1 dos testes online
int pretence(char s1[],char s2[]){
int i;

	for(i=0;s2[i]!='\0';i++){
		if(s2[i]!=s1[i]){
			return 0;
		}
	}
	return 1;
}

char *mystrstr (char s1[], char s2[]){
int j = 0;

    if( ((strlen (s1)) == 0) && ((strlen (s2)) ==0)){ /*para o caso de o input ser duas strings vazias*/
        return &s1[j];
        
    }
    
	for(j=0; s1[j]!='\0';j++){
		if(s1[j] == s2[0]){
			if ((pretence(&s1[j],s2))==1){
		        return &s1[j];
		        
			}
		}
	}
return NULL;
}

/*exercicio11*/
void mystrrev (char s[]){
char aux;
int i,j,last;

	for(i=0;s[i]!='\0';i++);
	last = i-1;
	
	for(j=0;j<=last;j++){
		aux=s[j];
		s[j]=s[last];
		s[last]=aux;
		last--;
	}
	printf("A string invertida fica: %s\n",s);//este print deve ser retirado para que funcione no teste online
}



/*exercicio12*/
int eVogal(char x){
char vogais[10]={'a','e','i','o','u','A','E','I','O','U'};
int i;
	for(i=0;vogais[i];i++){
		if(x==vogais[i]){
			return 1;
		}
	}
	return 0;
}

void myStrnoV (char s[]){
char *aux;
int i;
int j=0;

	for(i=0;s[i]!='\0';i++);
	aux = (char*) malloc(i*sizeof(char));

	for(i=0; s[i]!='\0';i++){
		if((eVogal (s[i]))==0){
			aux[j] = s[i];
			j++;			
		}
	}
	aux[j]='\0';

	for(j=0;aux[j]!='\0';j++){
		s[j] = aux[j];
	}
	s[j]='\0';
	printf("A string sem vogais fica: %s",s);//este print deve ser retirado para que funcione no teste online
}



/*exercicio13*/ //_---------------------------------------------------------------------------------------NÃO FUNCIONA-----------------------------------

/*
void truncW (char t[], int n){
int x=0;
int i,count;
char *aux;
	for(i=0;t[i]!='\0';i++);
	aux = (char*) malloc(i*sizeof(char));

	for(i=0;t[i]!='\0';i++){
		while(t[i]==' '){
			i++;
		}
		count=n;
		while(count>0 && t[i]!=' '){
			aux[x] = t[i];
			x++;
			i++;
			count--;
		}
		//count = n;
		aux[x] = ' ';
		x++;
		
		while(t[i]!=' '){ //talvez aqui ele salte uma posição á frente
			i++;
		}

	}
	aux[x] = '\0';

	for(i=0;aux[i]!='\0';i++){
		t[i]=aux[i];
	}
	t[i]='\0';
	printf("A string inserida usando corte de %d carateres fica: %s",n,t);//este print deve ser retirado para que funcione no teste online
}
*/




/*exercicio 14*/
int numOcorrencias(char x, char s[]){
int i, count;
count=0;

	for(i=0;s[i]!='\0';i++){
		(s[i]==x)?(count++):(count);
	}
	return count;
}
char charMaisfreq (char s[]){
char x;
int i;
int n=0;

	for(i=0;s[i]!='\0';i++){
		if(n<numOcorrencias(s[i],s)){
			n = numOcorrencias(s[i],s); 
			x = s[i];
		}
	}
	return x;
}


/*exercicio15*/
int numConsecutivos(char x,char s[]){
int i = 0;
int count = 0;
	while(x==s[i] && s[i]!='\0'){
		count++;
		i++;
	}
	return count;
}
int iguaisConsecutivos (char s[]){
int max = 0;
int i;

	for(i=0;s[i]!='\0';i++){
		if(max<=numConsecutivos(s[i],&s[i])){
			max=numConsecutivos(s[i],&s[i]);
		}
	}
	return max;
}


/*exercicio16*/ //---------------------------------------------------------------------------------------------SÓ ACERTA EM 1 TESTE (PROVAVELMENTE OS TESTES ESTÃO ERRADOS)
int countDifConsecutivos (char s[]){
int count = 1;
int i=0;

    while(s[i]!=s[i+1] && s[i]!='\0'){
		count++;
        i++;
	}
	
	return count;
}


int difConsecutivos(char s[]){
int i;
int max=0;
    for(i=0;s[i]!='\0';i++){
        if(max<countDifConsecutivos(&s[i])){
            max = countDifConsecutivos(&s[i]);
        }
    }
    return max;
}



/*exercicio17*/
int maiorPrefixo(char s1[], char s2[]){
int i=0;
int count=0;

	while(s1[i]==s2[i]){
		count++;
		i++;
	}

return count;
}

/*exercicio18*/
int maiorSufixo (char s1 [], char s2 []){
int i,j;
int count = 0;

	for(i=0;s1[i]!='\0';i++);
	for(j=0;s2[j]!='\0';j++);
	i--;j--; /*<---devido á forma como no menu é passado o input para esta função, esta linha de codigo tem de ser excluida nos testes online para passar nos testes*/
	while(s1[i-1]==s2[j-1]){
		count++;
		i--;
		j--;
	}
return count;
}

/*exercicio19*/ //-------------------------------------------------------------------------------------------NÃO ESTÁ A FUNCIONAR
int confirmaPrefixo(char s1[], char s2[]){
int i;
	printf("s1 = %s\n",s1);
	printf("s2 = %s\n",s2);

	for(i=0;s1[i]!='\0'; i++){ //verifica se a string s1 recebida é o sufixo de s2, tal só acontece se toda a string s1 for igual a s2
		if(s1[i]!=s2[i]){
				printf("Verificação - o caractere %c é DIFERENTE de %c\n",s1[i],s2[i]); 
			return 0;
		}
	
	}
	printf("Verificação - É PREFIXO\n"); 
	for(i=0;s1[i]!='\0';i++); //calcula o tamanho da string s1 recebida, sendo que a fração da string s1 recebida de input na função trata-se do sufixo 
	printf("tamanho do prefixo é %d\n",i);
	return i;
}

int sufPref (char s1[], char s2[]){
int j,i,tamPrefixo;
i=j=tamPrefixo=0;

	for(i=0;s1[i]!='\0';i++){
		while(s1[i]!=s2[j] && s1[i]!='\0'){
			i++;
		}

		if((confirmaPrefixo(&s1[i],s2))>0){
			printf("CENAS\n");
			return confirmaPrefixo(&s1[i],s2);
			
		}
	}

	return tamPrefixo;
}



/*exercicio20*/
int contaPal (char s[]){
int count=0;
int i=0;
int x;
    for(x=0;s[x]!='\0';x++){};
    
	
	do{
		if(s[i]!=' ' && s[i]!='\n' && s[i]!='\0'){
			
			count++;
			printf("contou a letra %c como sendo a %d letra da string\n",s[i],count);
			while(s[i]!=' '){
				i++;
			}

		}else{
			while(s[i]== ' ' || s[i]=='\n'){
				i++;
			}
		}

	}while(i<x); 

	
	return count;
}



/*exercicio21*/
int e_vogal(char c){
char vogais[10] = "aeiouAEIOU";
int i;

	for(i=0;vogais[i]!='\0';i++){
		if(c==vogais[i]){
			return 1;
		}
	}
	return 0;
}
int contaVogais (char s[]){
int i;
int count = 0;

	for(i=0; s[i]!='\0';i++){
		if(e_vogal(s[i])==1){
			count++;
		}
	}
	return count;
}


/*exercicio22*/
int existe(char c, char s[]){
int i;

	for (i=0; s[i]!='\0'; i++){
		if(s[i]==c){
			return 1;
		}
	}
	return 0;
}

int contida(char a[],char b[]){
int i;
	
	for(i=0; a[i]!='\0';i++){
		if(existe(a[i], b)==0){
			return 0;
		}
	}
	return 1;//1-existe || 0-não existe
}


/*exercicio23*/
int palindroma (char s[]){
int i, x;
	for(i=0; s[i]!='\0';i++){};
	i--;

	for(x=0; x<=i;x++){
		if(s[x]!=s[i]){
			return 0;
		}
		i--;
	}
	return 1;
}


/*exercicio 24*///------------------------------------------------------------------------DEVOLVE RESULTADOS CORRETOS MAS NOS TESTES ONLINE DÁ TUDO ERRADO ERRADO
int remRep(char x[]){ 
    
char aux[strlen(x)];
int i;
int ind = 0;

    for(i=0;x[i]!='\0';i++){
        aux[ind]=x[i];
        while(x[i]==aux[ind] && x[i]!='\0'){
            i++;
        }
        ind++;
    }
    aux[ind]='\0';
    x=aux;

    for(i=0;aux[i]!='\0';i++){ //copia todo o conteudo do array auxiliar para o array passado como parametro
    	x[i]=aux[i];
    }
    x[i+1]='\0';


return strlen(x);
}



/*exercicio25*/
int limpaEspacos (char t[]){
int i, ind;
ind = 0;
	for(i=0;t[i]!='\0';i++){

		if(t[i]==' '){
			t[ind]=t[i];
			ind++;
			while(t[i]==' ' && t[i]!='\0'){
				i++;
			}
		}
    
    	t[ind]=t[i];
    	ind++;
	    
	}
	t[ind]='\0';
	return strlen(t);
}



/*exercicio26*/
void insere (int v[], int N, int x){
int i = N-1;
int count = N;
//obs: Corer o array do final para o inicio
	while(v[i]>=x && i>=0){
		v[N]=v[i];
		N--;
		i--;
	}
	v[N]=x;

	for(int i=0;i<=count;i++){
		printf("%d ",v[i]);
	}
}
 /*-----------------USANDO FOR (ESTÁ FUNCIONAL)-----------------*/
/*
void insere (int s[], int N, int x){
    int i;                                        
    int j;
                                
    for(i=N; s[i-1]>=x && i>0 ; i--) 
        s[i]=s[i-1]; 
    s[i]=x;

	for(int i=0;i<=count;i++){
		printf("%d ",v[i]);
	}
}
*/


/*exercicio27*/ 
void myMerge (int r[], int a[], int b[], int na, int nb){/*OBS: Esta função precorre os arrays a e b ao mesmo tempo e vai inserindo por ordem crescente os valores no array R*/
int x,y,i;
x=0;
y=0;
	for(i=0;i<(na+nb);i++){
	    if(x==na){/*caso já se tenha chegado ao final do array 'a' mas ainda existam elementos no array 'b' para serem inseridos no array 'R'*/
	        for(;i<(na+nb);i++){
	            r[i]=b[y];
	            y++;
	        }
	    }else if(y==nb){/*caso já se tenha chegado ao final do array 'b' mas ainda existam elementos no array 'a' para serem inseridos no array 'R'*/
	        for(;i<(na+nb);i++){
	            r[i]=a[x];
	            x++;
	        }
	    }
	    
		if(a[x]>b[y]){//<---------Caso o valor atual no array 'a' seja maior, entao insere no array R o valor atual do array 'b' pois é menor e incrementa o 
			r[i]=b[y];//	     indice do array 'b' para que ñ seja tido em conta novamente na proxima iteração		
			y++;
		}else if(a[x]<b[y]){//<---Caso o valor atual no array 'a' seja menor, entao insere o valor no array R pois é o menor valor atual dos dois 
			r[i]=a[x];//          arrays ('a' e 'b') e incrementa o indice do array 'a' para que ñ seja tido em conta novamente na proxima iteração
			x++;
		}else{//<-----------------Caso os valores existentes em ambos os arrays('a' e'b') sejam o mesmo e tendo em conta que o array R subentende-se que pode ter 
			r[i]=a[x];//          repetidos, entao adiciona-se ao array R o valor atual do array 'a' e incrementa-se imediatamente o indice do array R pois logo 
			i++;//                a seguir vai receber o mesmo valor mas agora do array 'b'. Também se incrementa os indices dos arrays 'a' e 'b' para que na 
			x++;//                proxima iteração não se esteja a fazer a comparação das mesmas posições dos arrays 'a' e 'b'.
			r[i]=b[y];
			y++;
		}
	}

	
	for(i=0;i<=(na+nb)-1;i++){//<-----Comentar este ciclo 'for' para não visualizar o resultado final quando for a testar a função no CODEboard.IO
    	printf("%d ",r[i]);
    }

}


/*exercicio28*/
int crescente (int a[], int i, int j){

	for(;i<j;i++){
		if(a[i]>a[i+1]){
			return 0;
		}
	}
	return 1;
}



/*exercicio29*/
int retiraNeg (int v[], int N){
int i,j;
int *aux = malloc(N*sizeof(int));

j=0;
	for(i=0; i<N;i++){
		if(v[i]>=0){
		    aux[j]=v[i];
		    j++;
		}
	}

	for(i=0;i<j;i++){
		v[i]=aux[i];
	}
	return i;
}



/*exercicio30*/
int frequencia1(int x, int v[], int N){
int i;
int freq = 0;

	for(i=0;i<N;i++){
		if(v[i]==x){
			freq++;
		}
	}
	return freq;
}

int menosFreq (int v[], int N){
int val,valFreq,i;
	
	valFreq = frequencia1(v[0],v,N);
	val=v[0];

	for(i=0;i<N;i++){
		if(frequencia1(v[i],v,N)<valFreq){
			valFreq=frequencia1(v[i],v,N);
			val = v[i];
		}
	}
	return val;
}




/*exercicio31*/
int frequencia2(int x, int v[], int N){ //exatamente igual á funcção frequencia do exercicio anterior, só muda o nome!
int i;
int freq = 0;

	for(i=0;i<N;i++){
		if(v[i]==x){
			freq++;
		}
	}
	return freq;
}

int maisFreq (int v[], int N){
int val,valFreq,i;
	
	valFreq = frequencia2(v[0],v,N);
	val=v[0];

	for(i=0;i<N;i++){
		if(frequencia2(v[i],v,N)>valFreq){
			valFreq=frequencia2(v[i],v,N);
			val = v[i];
		}
	}
	return val;
}




/*exercicio32*/
int tamSequencia(int v[],int N){
int i,count,flag;
flag=0;
count = 1;
	
	for(i=0;i<N && flag==0;i++){
		if(v[i]<=v[i+1]){
			count++;
		}else{
			flag = 1;
		}
	}
	return count;
}

int maxCresc (int v[], int N){
int i, tamSeq;
tamSeq = 0;
	
	for(i=0;i<N;i++){
		if(v[i]<=v[i+1] && (i+1)<=N){
			if(tamSequencia(&v[i],N)>tamSeq){
				tamSeq=tamSequencia(&v[i],N);
			}
		}
	}
	return tamSeq;
}



/*exercicio33*/
int e_Repetido1(int x,int aux[],int n){
int i;

	for(i=0;i<n;i++){
		if(aux[i]==x){
			return 1;
		}
	}
	return 0;
}

int elimRep (int v[], int n){
int *aux;
int i=0;	
int j=0;
	
	aux=malloc(n*sizeof(int));

	aux[j]=v[i];
    j++;//<---------É importante este incremento para que seja corretamente tida em conta o 1º elemento do array 'v', seja ele qual for, 
        //          como sendo a 1º ocorrencia no array e assim imediatamente passado para o array 'aux' 
    
	for(i=0;i<n;i++){
		if(e_Repetido1(v[i],aux,n)==0){
			aux[j]=v[i];
			j++;
		}
	}

	for(i=0;i<j;i++){
		v[i]=aux[i];
	}

/*
	for(i=0;i<j;i++){//<-----Comentar este ciclo 'for' para não visualizar o resultado final quando for a testar a função no CODEboard.IO
    	printf("%d ",v[i]);
    }
*/
	return j;

}



/*exercicio34*/
int e_Repetido2(int x,int aux[],int n){//<-----------------OBS: EXATAMENTE IGUAL Á FUNÇÃO AUXILIAR DO EXERCICO ANTERIOR APENAS MUDA O NOME DA FUNÇÃO
int i;

	for(i=0;i<n;i++){
		if(aux[i]==x){
			return 1;
		}
	}
	return 0;
}

int elimRepOrd (int v[], int n){//<-----------------OBS: EXATAMENTE IGUAL AO EXERCICO ANTERIOR APENAS MUDA O NOME DA FUNÇÃO
int *aux;
int i=0;	
int j=0;
	
	aux=malloc(n*sizeof(int));

	aux[j]=v[i];
    j++;//<---------É importante este incremento para que seja corretamente tida em conta o 1º elemento do array 'v', seja ele qual for, 
        //          como sendo a 1º ocorrencia no array e assim imediatamente passado para o array 'aux' 
    
	for(i=0;i<n;i++){
		if(e_Repetido2(v[i],aux,n)==0){
			aux[j]=v[i];
			j++;
		}
	}

	for(i=0;i<j;i++){
		v[i]=aux[i];
	}

/*
	for(i=0;i<j;i++){//<-----Comentar este ciclo 'for' para não visualizar o resultado final quando for a testar a função no CODEboard.IO
    	printf("%d ",v[i]);
    }
*/
	return j;

}


/*exercicio35*/
int existe2(int x,int v[], int tam){ //<------------------------------------------------COMPLETAMENTE FUNCIONAL E PASSA NOS TESTES TODOS -- VER A LOGICA COM + ATENÇAO
int i;

	for(i=0;i<tam;i++){
		if(v[i]==x){
			return 1;
		}
	}
	return 0;
}


int comunsOrd (int a[], int na, int b[], int nb){
int count1 = 0;
int count2 = 0;
int i;

	if(na>nb){
		for(i=0;i<na;i++){
			if(existe2(a[i],b,nb)==1){
				count1++;
			}
		}
	}else if(na<nb){
		for(i=0;i<na;i++){
			if(existe2(a[i],b,nb)==1){
				count1++;
			}
		}
	}else{
		for(i=0;i<na;i++){
			if(existe2(a[i],b,nb)==1){
				count1++;
			}
		}
		for(i=0;i<nb;i++){
			if(existe2(b[i],a,na)==1){
				count2++;
			}
		}
		
		if(count1<=count2){
			return count1;
		}else{
			return count2;
		}	
	}

	return count1;
}

/*exercicio36*/ //<-----------------OBS: EXATAMENTE IGUAL Á FUNÇÃO AUXILIAR DO EXERCICO ANTERIOR APENAS MUDA O NOME DA FUNÇÃO
int existe3(int x,int v[], int tam){
int i;

	for(i=0;i<tam;i++){
		if(v[i]==x){
			return 1;
		}
	}
	return 0;
}

int comuns (int a[], int na, int b[], int nb){
int count1 = 0;
int count2 = 0;
int i;

	if(na>nb){
		for(i=0;i<na;i++){
			if(existe3(a[i],b,nb)==1){
				count1++;
			}
		}
	}else if(na<nb){
		for(i=0;i<na;i++){
			if(existe3(a[i],b,nb)>0){
				count1=count1+existe3(a[i],b,nb);
			}
		}
	}else{
		for(i=0;i<na;i++){
			if(existe3(a[i],b,nb)>0){
				count1=count1+existe3(a[i],b,nb);
			}
		}
		for(i=0;i<nb;i++){
			if(existe3(b[i],a,na)>0){
				count2=count1+existe3(a[i],b,nb);
			}
		}
		
		if(count1<=count2){
			return count1;
		}else{
			return count2;
		}	
	}

	return count1;
}


/*exercicio37*/
int minInd (int v[], int n){
int i;
int val = v[0];
int ind = 0;

	for(i=0;i<n;i++){
		if(val>v[i]){
			val=v[i];
			ind=i;
		}
	}
	return ind;
}



/*exercicio38*/
void somasAc (int v[], int Ac [], int N){
int i;
Ac[0]=v[0];

	for(i=1;i<N;i++){
		Ac[i]=Ac[i-1]+v[i];
	}

	printf("]\nARRAY: [");//<--------Comentar todo o codigo deste ponto para baixo para que nos teste online nao seja impressa informação a mais.
	for(i=0;i<N;i++){//              Esta parte do codigo existe apenas para ser apresentado o array resultado localhost.
		printf("%d ",Ac[i]);
	}
	printf("]\n");
}



/*exercicio39*/
int triSup (int N, float m [N][N]){ //-------------------------------------------------------NÃO ESTÁ COMPLETAMENTE FUNCIONAL, APENAS PASSA EM METADE DOS TESTES
int i,j;

	for(i=0;i<N;i++){
		for(j=0;j<=i;j++){
			if((m [i][j])!=0){
        	return 1; //caso não seja triangular
			}
		}
	}
	return 0;
}

/*exercicio40*/
void transposta (int N, float m [N][N]){
float aux [N][N];
int i,j;
    
    printf("\n\nINPUT:\n");
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				printf("%d ",m[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			aux[i][j]=m[j][i];
		}
	}
    printf("TRANSPOSTA:\n");
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				printf("%d ",aux[i][j]);
		}
		printf("\n");
	}
}


/*exercicio41*/
void addTo (int N, int M, int a [N][M], int b[N][M]){
int i,j;

		printf("MATRIZ - 1\n");
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
		printf("MATRIZ - 2\n");
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				printf("%d ",b[i][j]);
			}
			printf("\n");
		}

	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			a[i][j] += b[i][j];
		}
	}
	
		printf("\nMATRIZ RESULTADO\n");
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
}


/*exercicio42*/ //---------------------------------------100% CORRETA MAS PERCEBER MELHOR O PROBLEMA PROPOSTO!
int unionSet (int N, int v1[N], int v2[N], int r[N]){
int i,j;

	for(i=j=0;i<N;i++,j++){
		if(v1[i]==0 && v2[i]==0){
			r[j]=0;
		}else if(v1[i]==1){
			r[j]=1;
		}else if(v2[i]==1){
			r[j]=1;
		}
	}
	return 0;
}






/*exercicio43*/
int intersectSet (int N, int v1[N], int v2[N], int r[N]){
int i,j;

	for(i=j=0;i<N;i++,j++){
		if(v1[i]==1 && v2[i]==1){
			r[j]=1;
        }else{
			r[j]=0;
		}
	}
	return 0;
}

/*exercicio44*/
/*
int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
int i;
	for(i=0;i<N;i++){
		if(v1[i]==1 && v2[i]==0){
			r[i]=v1[i];
		}else if(v1[i]==0 && v2[i]==1){
			r[i]=v2[i];
		}else if(v1[i]==1 && v2[i]==1){
			r[i]=v1[i]+v2[i];
		}else{
			r[i]=v1[i];
		}
	}
	return 0;
}
*/

/*
int intersect(int N,int x,int v[N]){
int i;
    for(i=0;i<N;i++){
        if(v[i]==x){
            printf("\n v[i]:%d == x:%d\n",v[i],x);
            return 1;
        }
    }
    return 0;
}

int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
int i,j;
j=0;
	for(i=0;i<N;i++){
		if((intersect(N,v2[i],v1))==1){
			r[j]=v1[i];
            j++;
	    }
	}
	return 0;
}
*/

/*exercicio45*/
int quantos(int x,)
int unionMSet (int N, int v1[N], int v2[N], int r[N]){

}

/*exercicio46*/
int cardinalMSet (int N, int v[N]){
int numElems=0;
int i;

	for(i=0;i<N;i++){
		if(v[i]!=0){
			numElems+=v[i];
		}
	}
	return numElems;
}


/*exercicio47*/
Posicao posFinal (Posicao inicial, Movimento mov[], int N){
int i;
	for(i=0;i<N;i++){
		if(mov[i]==Norte){
			inicial.y+=1;
		}else if(mov[i]==Sul){
			inicial.y-=1;
		}else if(mov[i]==Este){
			inicial.x+=1;
		}else{
			inicial.x-=1;
		}
	}
	return inicial;
}

/*exercicio48*/  
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
int tam=0;
int i;


/*
	//---EXTRAS--->Para uma breve introdução sobre manipulação de estruturas
	//Para aceder a campos dentro de uma estrutura usa-se o '.'
	printf("Valor de x: %d\n",inicial.x);
	printf("Valor de y: %d\n",inicial.y);
	printf("Posição na struct enum onde se encontra 'Sul': %d\n\n\n",n);//está a imprimir a numero da posição na struct do parametro "Sul",daí o "%d". 
	
	enum movimento n,s,e,o;
	n=Norte;
	o=Oeste;
	s=Sul;
	e=Este;

	//Nota que a numeração dos parametro começa em zero.
	printf("Posição na struct enum onde se encontra 'Norte': %d\n",n);
	printf("Posição na struct enum onde se encontra 'Oeste': %d\n",o);
	printf("Posição na struct enum onde se encontra 'Sul': %d\n",s);
	printf("Posição na struct enum onde se encontra 'Este': %d\n",e);

	printf("Coordenada inicial: (%d,%d)\n",inicial.x,inicial.y);
	printf("Coordenada final: (%d,%d)\n\n",final.x,final.y);

	//---FIM DOS EXTRAS---
*/
	while(inicial.x != final.x || inicial.y != final.y){

		if(inicial.x > final.x){
			mov[tam]=1;
			tam++;
			inicial.x--;
		} else if(inicial.x < final.x){
			mov[tam]=3;
			tam++;
			inicial.x++;
		} else if(inicial.y > final.y){
			mov[tam]=2;
			tam++;
			inicial.y--;
		} else if(inicial.y < final.y){
			mov[tam]=0;
			tam++;
			inicial.y++;
		}else if(inicial.x == final.x && inicial.y < final.y){
			mov[tam]=0;
			tam++;
			inicial.y++;
		} else if(inicial.x == final.x && inicial.y > final.y){
			mov[tam]=2;
			tam++;
			inicial.y--;
		} else if(inicial.x < final.x && (inicial.y == final.y)){
			mov[tam]=3;
			tam++;
			inicial.x++;
		} else if(inicial.x > final.x && inicial.y == final.y){
			mov[tam]=1;
			tam++;
			inicial.x--;
		}
	
	}
			
	printf("Posição atual do robo: (%d,%d)\n",inicial.x,inicial.y);
	printf("Numero máximo de comandos permitidos ao robo para chegar ao destino: %d\n",N);
	printf("Numero de comandos necessários para o robo chegar ao destino: %d\n",tam);
	printf("TRAJETO: ");
	for(i=0;i<tam;i++){
		printf("%d --> ",mov[i]);
	}


	if(tam>N){ /*pelo enunciado deveŕa retornar -1 caso o numero de comandos para chegar ao destino seja superior ao maximo estipulado*/
		return -1;
	}else{
		return tam;
	}

}

/*exercicio49*/ //-----a função so passa em dois testes e dá erro em localhost por causa do uso do pow e sqrt mesmo com a bib math.h
double distancia(Posicao pos){
int t;
	
t=sqrt((pow(pos.x,2))+(pow(pos.y,2)));

return t;
}


int maiscentral (Posicao pos[], int N){
int i,indice;
double min;

	min=distancia(pos[0]);
	indice = 0;

	for(i=1;i<N;i++){
	    printf("PONTO: (%d,%d)\n",pos[i].x,pos[i].y);
		if(distancia(pos[i])<min){
			min=distancia(pos[i]);
			indice=i;
		}
	}
	printf("Ponto mais proximo é o ponto (%d,%d), e encontra-se na posição %d do array.\n",pos[indice].x,pos[indice].y,indice);
	return indice;
}

/*exercicio50*/ //-----------------------------------------SÓ PASSA EM 1 TESTE ONLINE E DÁ ERRO POR CAUSA DO POW(mesmo com o include do math.h)
double e_adjacente(Posicao p,Posicao orig){
    /*o uso do pow é para evitar resultados negativos*/
	if(( ((p.x)==(orig.x)) && (((p.y)==pow((orig.y-1),2)) || ((p.y)==pow(((orig.y)+1),2)) )) || /*ponto encontra-se no mesmo eixo dos xx mas acima ou a baixo do ponto origem*/
	   ( ((p.y)==(orig.y)) && (((p.x)==pow((orig.x-1),2)) || ((p.x)==pow(((orig.x)+1),2)) )) || /*ponto encontra-se no mesmo eixo dos xx mas á esquerda ou á direita do ponto origem*/
       ( pow(((p.y)-1),2)==(orig.y)) && (((pow((p.x)-1,2))==(orig.x)) || (pow((p.x)+1,2))==((orig.x)) ) ||/*ponto encontra-se nas posições infeirores que fazem a diagonal com o ponto origem(á esquerda e direita inferiores do ponto original)*/
       ( pow(((p.y)+1),2)==(orig.y)) && ((pow(((p.x)-1),2)==(orig.x)) || (pow((p.x)+1,2))==((orig.x)) ) )/*ponto encontra-se nas posições superiores que fazem a diagonal com o ponto origem(á esquerda e direita acima do ponto original)*/
	{
		return 1;
	}
	return 0;
}


int vizinhos (Posicao p, Posicao pos[], int N){
int i, count;
count =0;
    
    
	for(i=0;i<N;i++){
		if(e_adjacente(pos[i],p)==1){ //CONFIRMAR SE É CORRETO ENTENDER-SE QUE SER SUBJACENTE É DIZER QUE A SUA DISTANCIA ENTRE PONTOS É =1!!!
			count++;
		}
	}
	return count;
}

/*
REVER EXERCICIOS:
5,7,8,10,13,16,19,24,35*,39,42*,44,49,50
*/