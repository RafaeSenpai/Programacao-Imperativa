QuickSort (a, inicio, fim){
   If inicio < fim
      Meio = particiona (inicio, fim)
      QuickSort (inicio, meio-1)
      QuickSort (meio + 1, fim)
   return
}
Particiona (inicio, fim)
   //troca o primeiro valor do vector 
     com o valor do meio para que o valor 
     "médio" fique no inicio do vector
	meio=(inicio+fim)/2
	aux=a[inicio];
	a[inicio]=a[meio];
	a[meio]=aux;
	
   pivot = a[inicio] //coloca como pivot o valor 
                     "médio" que se encontra no 
                     inicio do vector
   ultbaixo = inicio //numero de elementos no 
                      vector menores que o pivot
   for i = inicio to fim do
      if a[i] < pivot
         ultbaixo = ultbaixo + 1
         aux=a[i]
         a[i]=a[pivot]
         a[pivot]=a[i]

   //troca o pivot com o último elemento do 
   vector menor do que ele
   aux=a[inicio]
   a[inicio]=a[ultbaixo]
   a[ultbaixo]=aux
return utlbaixo 
