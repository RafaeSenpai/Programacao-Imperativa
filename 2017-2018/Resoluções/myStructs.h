/*Este ficheiro .h contem todas as structs ou variaveis usadas em todos os programas.
Como tal, deve ser incluido em todos os .c onde se encontram os programas
NOTA: o include deste (#include "myStruct.h")ou outro ".h" que contenha apenas as structs deve ser
apenas incluido nos ".c" mas não nos seus repetivos ".h"*/
typedef enum movimento {
		Norte, 
		Oeste, 
		Sul,
		Este} Movimento;


typedef struct posicao {
	int x, y;
} Posicao;




