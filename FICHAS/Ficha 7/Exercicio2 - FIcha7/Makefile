
All: ficha7.o ficha7_funcoes.o clear 
	 gcc ficha7.o ficha7_funcoes.o -o Executavel
	 ./Executavel 

ficha7.o: ficha7.c    ficha7.h
	gcc -Wall -c ficha7.c 

ficha7_funcoes.o: ficha7_funcoes.c    ficha7_funcoes.h
	gcc -Wall -c ficha7_funcoes.c

clear: 
	clear

clean:
	rm *.o 

cleanAll:
	rm *.o Executavel






