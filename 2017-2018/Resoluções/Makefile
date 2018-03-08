
All: bigMain.o ficha1.o m_Ficha1.o reRoutingEntreMenus.o ficha2.o m_Ficha2.o ficha3.o m_Ficha3.o 50primeiras.o m_50Primeiras.o clear 
	 gcc bigMain.o ficha1.o m_Ficha1.o ficha2.o m_Ficha2.o ficha3.o m_Ficha3.o 50primeiras.o m_50Primeiras.o reRoutingEntreMenus.o -o bigMain
	 ./bigMain #esta linha arranca o executavel criado na linha imediatamente a seguir

AllWhithWarnnings: cleanAll bigMain.o ficha1.o m_Ficha1.o reRoutingEntreMenus.o ficha2.o m_Ficha2.o ficha3.o m_Ficha3.o 50primeiras.o m_50Primeiras.o
	gcc bigMain.o ficha1.o m_Ficha1.o ficha2.o m_Ficha2.o ficha3.o m_Ficha3.o 50primeiras.o m_50Primeiras.o reRoutingEntreMenus.o -o bigMain
	

bigMain.o: bigMain.c
	gcc -Wall -c bigMain.c 
	
ficha1.o: ficha1.c    ficha1.h
	gcc -Wall -c ficha1.c #a opção -c diz ao compilador para gerar apenas o arquivo objecto com extenção ***.o

m_Ficha1.o: m_Ficha1.c    m_Ficha1.h
	gcc -Wall -c m_Ficha1.c

ficha2.o: ficha2.c ficha2.h
	gcc -Wall -c ficha2.c

m_Ficha2.o: m_Ficha2.c    m_Ficha2.h
	gcc -Wall -c m_Ficha2.c

ficha3.o: ficha3.c ficha3.h
	gcc -Wall -c ficha3.c

m_Ficha3.o: m_Ficha3.c    m_Ficha3.h
	gcc -Wall -c m_Ficha3.c

50primeiras.o: 50primeiras.c 50primeiras.h
	gcc -Wall -c 50primeiras.c

m_50Primeiras.o: m_50Primeiras.c    m_50Primeiras.h
	gcc -Wall -c m_50Primeiras.c


reRoutingEntreMenus.o: reRoutingEntreMenus.c    reRoutingEntreMenus.h
	gcc -Wall -c reRoutingEntreMenus.c

clear: 
	clear

clean:
	rm *.o #remover todos os ficheiros ***.o gerados

cleanAll:
	rm *.o bigMain

