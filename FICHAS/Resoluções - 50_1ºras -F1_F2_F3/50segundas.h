/*Structs a baixo dizem respeito ás 50 segundas questões*/
#include "myStructs.h"/*importa as caracteristicas e composições de todas as estruturas de dados usadas 
						em todas as funções aqui declaradas. NOTA: Ao incluir aqui o ficheiro com as 
						as estruturas de dados usadas nas funções a baixo declaradas(API) estámos a 
						tornar essas mesmas estruturas de dados "publicas". Caso se queira manter as
						estruturas de dados privadas, estas devem ser incluidas (Fazer este include,
						- #include "myStructs.h" no ficheiro .c que contem a definição das funções que
						usam as respetivas estuturas de dados definidas em myStructs.h*/

LInt criarLInt();
void printLInt();
int myLength();
LInt freeL();
void imprimeL();
LInt reverseL ();
int removeOneOrd();