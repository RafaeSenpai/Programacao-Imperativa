#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bigMain.h"/*quando se quer incluir uma API propria usa-se as aspas ao contrario <API's padrao>*/
#include "ficha2.h"
#include "m_Ficha2.h"



/*Exercicio 1*/
float multInt(int n,float m){
int tot = m;
	for(int x=1; x<n; x++){
		m = m + tot;
	}
return m;
}

/*falta fazer todos os outros exercicios*/	