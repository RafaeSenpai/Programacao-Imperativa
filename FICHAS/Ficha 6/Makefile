
All: ficha6.o ficha6_funcoes.o ficha6_interface.o clear 
	 gcc ficha6.o ficha6_funcoes.o ficha6_interface.o -o Executavel
	 ./Executavel 

ficha6.o: ficha6.c    ficha6.h
	gcc -Wall -c ficha6.c 

ficha6_funcoes.o: ficha6_funcoes.c    ficha6_funcoes.h
	gcc -Wall -c ficha6_funcoes.c

ficha6_interface.o: ficha6_interface.c    ficha6_interface.h
	gcc -Wall -c ficha6_interface.c

clear: 
	clear

clean:
	rm *.o 

cleanAll:
	rm *.o Executavel
